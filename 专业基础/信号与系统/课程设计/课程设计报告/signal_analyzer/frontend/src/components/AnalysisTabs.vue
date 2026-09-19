<template>
  <div class="analysis-tabs">
    <div class="tabs">
      <button :class="{ active: activeTab === 'waveform' }" @click="activeTab = 'waveform'">Waveform</button>
      <button :class="{ active: activeTab === 'spectrogram' }" @click="activeTab = 'spectrogram'">Spectrogram</button>
      <button :class="{ active: activeTab === 'spectrum' }" @click="activeTab = 'spectrum'">Spectrum</button>
      <button :class="{ active: activeTab === 'spectrumVideo' }" @click="activeTab = 'spectrumVideo'">Spectrum Video</button>
      <button :class="{ active: activeTab === 'spectrogramVideo' }" @click="activeTab = 'spectrogramVideo'">Spectrogram Video</button>
    </div>
    <div class="tab-content">
      <div v-if="activeTab === 'waveform'">
        <WaveformPlot :plotUrl="analysisResults.waveform" />
      </div>
      <div v-if="activeTab === 'spectrum'">
        <SpectrumPlot :plotUrl="analysisResults.spectrum" />
      </div>
      <div v-if="activeTab === 'spectrogram'">
        <SpectrogramPlot :plotUrl="analysisResults.spectrogram" />
      </div>
      <div v-if="activeTab === 'spectrumVideo'">
        <SpectrumVideo
          :videoUrl="analysisResults.spectrumVideoUrl"
          :status="analysisResults.spectrumVideoStatus"
          :progress="analysisResults.spectrumVideoProgress"
          :message="analysisResults.spectrumVideoMessage"
          :error="analysisResults.spectrumVideoError"
        />
      </div>
      <div v-if="activeTab === 'spectrogramVideo'">
        <SpectrogramVideo
          :videoUrl="analysisResults.spectrogramVideoUrl"
          :status="analysisResults.spectrogramVideoStatus"
          :progress="analysisResults.spectrogramVideoProgress"
          :message="analysisResults.spectrogramVideoMessage"
          :error="analysisResults.spectrogramVideoError"
        />
      </div>
    </div>
  </div>
</template>

<script setup lang="ts">
import { ref, type PropType } from 'vue';
import WaveformPlot from './WaveformPlot.vue';
import SpectrogramPlot from './SpectrogramPlot.vue';
import SpectrumPlot from './SpectrumPlot.vue';
import SpectrumVideo from './SpectrumVideo.vue';
import SpectrogramVideo from './SpectrogramVideo.vue';

interface AnalysisResults {
  waveform: string;
  spectrogram: string;
  spectrum: string;
  spectrumVideoUrl: string;
  spectrogramVideoUrl: string;
  spectrumVideoStatus: string;
  spectrogramVideoStatus: string;
  spectrumVideoProgress: number;
  spectrogramVideoProgress: number;
  spectrumVideoMessage: string;
  spectrogramVideoMessage: string;
  spectrumVideoError: string;
  spectrogramVideoError: string;
}

defineProps({
  analysisResults: {
    type: Object as PropType<AnalysisResults>,
    required: true,
  },
});

const activeTab = ref('waveform');
</script>

<style scoped>
.analysis-tabs {
  width: 100%;
}
.tabs {
  display: flex;
  border-bottom: 2px solid var(--border-color);
}
.tabs button {
  padding: 10px 20px;
  cursor: pointer;
  background-color: transparent;
  border: none;
  color: var(--text-dark);
  font-size: 16px;
  transition: all 0.3s ease;
  border-bottom: 3px solid transparent;
}
.tabs button.active {
  color: var(--accent-cyan);
  border-bottom: 3px solid var(--accent-cyan);
}
.tabs button:hover {
  background-color: var(--light-blue-panel);
  color: var(--accent-cyan);
}
.tab-content {
  padding-top: 20px;
}
</style>
