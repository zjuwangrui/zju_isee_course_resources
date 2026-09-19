<template>
  <div id="app">
    <header class="app-header">
      <h1>Signal Analyzer</h1>
    </header>
    <SettingsDialog :is-open="isSettingsOpen" :params="analysisParams" @close="isSettingsOpen = false"
      @update:params="onApplyParams" />
    <div class="main-layout">
      <div class="controls-panel">
        <FileUpload @upload-success="onUploadSuccess" />
        <SettingsIcon @click="isSettingsOpen = true" />
      </div>
      <div class="plots-panel">
        <div v-if="isLoading" class="loading-overlay">
          <p>Analyzing...</p>
        </div>
        <AnalysisTabs v-if="analysisCompleted" :analysisResults="analysisResults" />
        <div v-else-if="!isLoading" class="placeholder-text">
          Please upload a file to begin analysis.
        </div>
      </div>
    </div>
  </div>
</template>

<script setup lang="ts">
import { ref, reactive, onMounted } from 'vue';
import axios from 'axios';
import type { AxiosError } from 'axios';
import FileUpload from './components/FileUpload.vue';
import AnalysisTabs from './components/AnalysisTabs.vue';
import SettingsIcon from './components/SettingsIcon.vue';
import SettingsDialog from './components/SettingsDialog.vue';
import { API_BASE_URL, toAbsoluteApiUrl } from './api/signal';

type VideoType = 'spectrum' | 'spectrogram';
type VideoStatus = 'idle' | 'queued' | 'running' | 'success' | 'failed';

const isSettingsOpen = ref(false);

const uploadedFilename = ref<string | null>(null);
const analysisParams = ref({
  sr: 22050,
  waveform: {},
  spectrum: {
    n_fft: 2048,
  },
  stft: {
    n_fft: 2048,
    hop_length: 512,
    win_length: 2048,
    window: 'hann',
    cmap: 'viridis'
  },
  fft_animation: {
    n_fft: 2048,
    hop_length: 512,
    cmap: 'magma',
    rain_drop_count: 120,
    rain_cmap: 'hsv',
    rain_length_min: 4,
    rain_length_max: 12,
    rain_width_min: 1.5,
    rain_width_max: 3.5,
    rain_alpha: 0.8,
    render_fps: 12,
    max_video_frames: 900,
  },
  stft_animation: {
    n_fft: 2048,
    hop_length: 512,
    win_length: 2048,
    window: 'hann',
    cmap: 'viridis',
    frame_nums: 10,
    render_fps: 12,
    max_video_frames: 900,
  }
});
const analysisResults = reactive({
  waveform: '',
  spectrogram: '',
  spectrum: '',
  spectrogramVideoUrl: '',
  spectrumVideoUrl: '',
  spectrogramVideoStatus: 'idle' as VideoStatus,
  spectrumVideoStatus: 'idle' as VideoStatus,
  spectrogramVideoProgress: 0,
  spectrumVideoProgress: 0,
  spectrogramVideoMessage: '',
  spectrumVideoMessage: '',
  spectrogramVideoError: '',
  spectrumVideoError: '',
});
const isLoading = ref(false);
const analysisCompleted = ref(false);
const analysisRunId = ref(0);
const pollIntervals: ReturnType<typeof setInterval>[] = [];

const resetVideoState = (videoType?: VideoType) => {
  const types: VideoType[] = videoType ? [videoType] : ['spectrum', 'spectrogram'];
  types.forEach((type) => {
    const prefix = type === 'spectrum' ? 'spectrumVideo' : 'spectrogramVideo';
    (analysisResults as any)[`${prefix}Url`] = '';
    (analysisResults as any)[`${prefix}Status`] = 'idle';
    (analysisResults as any)[`${prefix}Progress`] = 0;
    (analysisResults as any)[`${prefix}Message`] = '';
    (analysisResults as any)[`${prefix}Error`] = '';
  });
};

const setVideoTaskState = (
  videoType: VideoType,
  state: Partial<{
    url: string;
    status: VideoStatus;
    progress: number;
    message: string;
    error: string;
  }>,
) => {
  const prefix = videoType === 'spectrum' ? 'spectrumVideo' : 'spectrogramVideo';
  if (state.url !== undefined) (analysisResults as any)[`${prefix}Url`] = state.url;
  if (state.status !== undefined) (analysisResults as any)[`${prefix}Status`] = state.status;
  if (state.progress !== undefined) (analysisResults as any)[`${prefix}Progress`] = state.progress;
  if (state.message !== undefined) (analysisResults as any)[`${prefix}Message`] = state.message;
  if (state.error !== undefined) (analysisResults as any)[`${prefix}Error`] = state.error;
};

const clearPollIntervals = () => {
  while (pollIntervals.length) {
    const interval = pollIntervals.pop();
    if (interval) clearInterval(interval);
  }
};

const onUploadSuccess = (filename: string) => {
  uploadedFilename.value = filename;
  analysisCompleted.value = false; // Reset on new upload
  clearPollIntervals();
  // Clear previous results
  Object.assign(analysisResults, {
    waveform: '',
    spectrogram: '',
    spectrum: '',
  });
  resetVideoState();
  analyzeSignal(); // Trigger analysis on new upload
};

const onApplyParams = (params: any) => {
  analysisParams.value = JSON.parse(JSON.stringify(params));
  if (uploadedFilename.value) {
    analyzeSignal();
  }
};

const getErrorMessage = (error: unknown, fallback: string) => {
  if (axios.isAxiosError(error)) {
    const axiosError = error as AxiosError<{ error?: string }>;
    return axiosError.response?.data?.error || axiosError.message || fallback;
  }
  if (error instanceof Error) {
    return error.message;
  }
  return fallback;
};

onMounted(() => {
  // No need to do anything here anymore as sr is part of the main ref
});

const analyzeSignal = async () => {
  if (!uploadedFilename.value) return;

  const runId = ++analysisRunId.value;
  clearPollIntervals();
  isLoading.value = true;
  analysisCompleted.value = false;
  // Reset previous results
  Object.assign(analysisResults, {
    waveform: '', spectrogram: '', spectrum: '',
  });
  resetVideoState();

  try {
    // --- Trigger static image analysis ---
    const imageResponse = await axios.get(`${API_BASE_URL}/analyze/${uploadedFilename.value}`, {
      params: {
        sr: analysisParams.value.sr,
        spectrum_n_fft: analysisParams.value.spectrum.n_fft,
        stft_n_fft: analysisParams.value.stft.n_fft,
        hop_length: analysisParams.value.stft.hop_length,
        win_length: analysisParams.value.stft.win_length,
        window: analysisParams.value.stft.window,
        cmap: analysisParams.value.stft.cmap,
      }
    });
    const { waveform, spectrogram, spectrum } = imageResponse.data;
    analysisResults.waveform = `data:image/png;base64,${waveform}`;
    analysisResults.spectrogram = `data:image/png;base64,${spectrogram}`;
    analysisResults.spectrum = `data:image/png;base64,${spectrum}`;
    analysisCompleted.value = true; // Show static images immediately

    // --- Trigger video analysis (no need to await) ---
    triggerSpectrumVideoAnalysis(runId);
    triggerSpectrogramVideoAnalysis(runId);

  } catch (error) {
    console.error('Error analyzing signal:', error);
    alert(`Error analyzing signal: ${getErrorMessage(error, 'Unknown error')}`);
  } finally {
    isLoading.value = false;
  }
};

const triggerSpectrumVideoAnalysis = async (runId: number) => {
  if (!uploadedFilename.value) return;

  try {
    setVideoTaskState('spectrum', {
      status: 'queued',
      progress: 0,
      message: 'Queued',
      error: '',
    });
    const videoResponse = await axios.post(`${API_BASE_URL}/analyze/spectrum_video/${uploadedFilename.value}`, {
      sr: analysisParams.value.sr,
      ...analysisParams.value.fft_animation
    });
    const { task_id } = videoResponse.data;
    
    // Start polling for task status
    pollTaskStatus(task_id, 'spectrum', runId);

  } catch (error) {
    console.error('Error starting spectrum video analysis:', error);
    const message = getErrorMessage(error, 'Failed to start spectrum video task.');
    setVideoTaskState('spectrum', {
      status: 'failed',
      message: 'Failed to start',
      error: message,
    });
  }
};


const triggerSpectrogramVideoAnalysis = async (runId: number) => {
  if (!uploadedFilename.value) return;

  try {
    setVideoTaskState('spectrogram', {
      status: 'queued',
      progress: 0,
      message: 'Queued',
      error: '',
    });
    const videoResponse = await axios.post(`${API_BASE_URL}/analyze/spectrogram_video/${uploadedFilename.value}`, {
      sr: analysisParams.value.sr,
      ...analysisParams.value.stft_animation
    });
    const { task_id } = videoResponse.data;

    // Start polling for task status
    pollTaskStatus(task_id, 'spectrogram', runId);
  } catch (error) {
    console.error('Error starting spectrogram video analysis:', error);
    const message = getErrorMessage(error, 'Failed to start spectrogram video task.');
    setVideoTaskState('spectrogram', {
      status: 'failed',
      message: 'Failed to start',
      error: message,
    });
  }
};

const pollTaskStatus = (taskId: string, videoType: VideoType, runId: number) => {
  const interval = setInterval(async () => {
    if (runId !== analysisRunId.value) {
      clearInterval(interval);
      return;
    }

    try {
      const statusResponse = await axios.get(`${API_BASE_URL}/tasks/status/${taskId}`);
      const { status, video_url, error, progress, message } = statusResponse.data;
      const normalizedStatus = status as VideoStatus;
      setVideoTaskState(videoType, {
        status: normalizedStatus,
        progress: Math.round((Number(progress) || 0) * 100),
        message: message || status,
      });

      if (status === 'success') {
        clearInterval(interval);
        const fullUrl = toAbsoluteApiUrl(video_url);
        setVideoTaskState(videoType, {
          url: fullUrl,
          status: 'success',
          progress: 100,
          message: 'Completed',
        });
      } else if (status === 'failed') {
        clearInterval(interval);
        console.error(`Video generation task ${taskId} of type ${videoType} failed:`, error);
        setVideoTaskState(videoType, {
          status: 'failed',
          error: error || 'Video generation failed.',
          message: 'Failed',
        });
      }
      // If status is 'running' or 'pending', do nothing and wait for the next poll.
    } catch (err) {
      clearInterval(interval);
      console.error('Error polling task status:', err);
      const message = getErrorMessage(err, 'Could not check video task status.');
      setVideoTaskState(videoType, {
        status: 'failed',
        message: 'Status check failed',
        error: message,
      });
    }
  }, 3000); // Poll every 3 seconds
  pollIntervals.push(interval);
};
</script>

<style>
:root {
  --dark-blue-bg: #0a192f;
  --light-blue-panel: #112240;
  --accent-blue: #42a5f5;
  --accent-cyan: #64ffda;
  --text-light: #ccd6f6;
  --text-dark: #8892b0;
  --border-color: #233554;
}

body {
  background-color: var(--dark-blue-bg);
  color: var(--text-light);
}

#app {
  font-family: 'Segoe UI', 'Roboto', 'Oxygen', 'Ubuntu', 'Cantarell', 'Fira Sans', 'Droid Sans', 'Helvetica Neue', sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  margin-top: 40px;
}

.app-header {
  text-align: center;
  display:block;
}

h1 {
  color: var(--accent-cyan);
  font-weight: 600;
  letter-spacing: 1.5px;
}

.main-layout {
  display: flex;
  flex-direction: column;
  gap: 20px;
  padding: 20px;
  align-items: stretch; /* Stretch items to fill the width */
}

.controls-panel {
  background-color: var(--light-blue-panel);
  padding: 20px;
  border-radius: 8px;
  border: 1px solid var(--border-color);
  width: 100%; /* Occupy full width */
  max-width: none; /* Override previous max-width */
  box-sizing: border-box; /* Ensure padding is included in width */
}

.plots-panel {
  position: relative;
  min-height: 400px; /* Ensure it has some height */
  background-color: var(--light-blue-panel);
  padding: 10px;
  border-radius: 8px;
  border: 1px solid var(--border-color);
}

.loading-overlay {
  position: absolute;
  top: 0;
  left: 0;
  right: 0;
  bottom: 0;
  background-color: rgba(10, 25, 47, 0.8);
  display: flex;
  justify-content: center;
  align-items: center;
  font-size: 1.5em;
  z-index: 10;
  color: var(--accent-cyan);
  border-radius: 8px;
}

.placeholder-text {
  color: var(--text-dark);
  font-size: 1.2em;
  margin-top: 50px;
}
</style>
