<template>
  <div v-if="isOpen" class="dialog-overlay" @click.self="close">
    <div class="dialog-content">
      <h2>Settings</h2>
      <div class="tabs">
        <button v-for="tab in tabs" :key="tab.id" @click="activeTab = tab.id" :class="{ active: activeTab === tab.id }">
          {{ tab.name }}
        </button>
      </div>
      <div class="tab-content">
        <div v-if="activeTab === 'waveform'">
            <div class="form-group">
            <label for="sr">Sample Rate (sr)</label>
            <input id="sr" type="number" v-model.number="editableParams.sr">
          </div>
          <p class="hint">(注：该采样率是所有图片和动画生成的共用参数)</p>
        </div>
        <div v-if="activeTab === 'spectrum'">
          <div class="form-group">
            <label for="spectrum_n_fft">N-FFT</label>
            <input id="spectrum_n_fft" type="number" v-model.number="editableParams.spectrum.n_fft">
          </div>
        </div>
        <div v-if="activeTab === 'stft'">
          <div class="form-group">
            <label for="n_fft">N-FFT</label>
            <input id="n_fft" type="number" v-model.number="editableParams.stft.n_fft">
          </div>
          <div class="form-group">
            <label for="hop_length">Hop Length</label>
            <input id="hop_length" type="number" v-model.number="editableParams.stft.hop_length">
          </div>
          <div class="form-group">
            <label for="win_length">Window Length</label>
            <input id="win_length" type="number" v-model.number="editableParams.stft.win_length">
          </div>
           <div class="form-group">
            <label for="window">Window Type</label>
            <select id="window" v-model="editableParams.stft.window">
              <option v-for="win in windowOptions" :key="win" :value="win">{{ win }}</option>
            </select>
          </div>
          <div class="form-group">
            <label for="cmap">Colormap</label>
             <select id="cmap" v-model="editableParams.stft.cmap">
              <option v-for="c in cmapOptions" :key="c" :value="c">{{ c }}</option>
            </select>
          </div>
        </div>
        <div v-if="activeTab === 'fft_animation'">
           <div class="form-group">
            <label for="fft_n_fft">N-FFT</label>
            <input id="fft_n_fft" type="number" v-model.number="editableParams.fft_animation.n_fft">
          </div>
          <div class="form-group">
            <label for="fft_hop_length">Hop Length</label>
            <input id="fft_hop_length" type="number" v-model.number="editableParams.fft_animation.hop_length">
          </div>
          <div class="form-group">
            <label for="fft_cmap">Line Colormap</label>
            <select id="fft_cmap" v-model="editableParams.fft_animation.cmap">
              <option v-for="c in cmapOptions" :key="c" :value="c">{{ c }}</option>
            </select>
          </div>
          <div class="form-group">
            <label for="fft_rain_drop_count">Rain Drop Count</label>
            <input id="fft_rain_drop_count" type="number" v-model.number="editableParams.fft_animation.rain_drop_count">
          </div>
          <div class="form-group">
            <label for="fft_rain_cmap">Rain Colors</label>
            <select id="fft_rain_cmap" v-model="editableParams.fft_animation.rain_cmap">
              <option v-for="c in rainCmapOptions" :key="c" :value="c">{{ c }}</option>
            </select>
          </div>
          <div class="form-group">
            <label for="fft_rain_length_min">Rain Length Min</label>
            <input id="fft_rain_length_min" type="number" step="0.1" v-model.number="editableParams.fft_animation.rain_length_min">
          </div>
          <div class="form-group">
            <label for="fft_rain_length_max">Rain Length Max</label>
            <input id="fft_rain_length_max" type="number" step="0.1" v-model.number="editableParams.fft_animation.rain_length_max">
          </div>
          <div class="form-group">
            <label for="fft_rain_width_min">Rain Width Min</label>
            <input id="fft_rain_width_min" type="number" step="0.1" v-model.number="editableParams.fft_animation.rain_width_min">
          </div>
          <div class="form-group">
            <label for="fft_rain_width_max">Rain Width Max</label>
            <input id="fft_rain_width_max" type="number" step="0.1" v-model.number="editableParams.fft_animation.rain_width_max">
          </div>
          <div class="form-group">
            <label for="fft_rain_alpha">Rain Alpha</label>
            <input id="fft_rain_alpha" type="number" min="0" max="1" step="0.05" v-model.number="editableParams.fft_animation.rain_alpha">
          </div>
          <div class="form-group">
            <label for="fft_render_fps">Render FPS</label>
            <input id="fft_render_fps" type="number" step="0.1" v-model.number="editableParams.fft_animation.render_fps">
          </div>
          <div class="form-group">
            <label for="fft_max_video_frames">Max Video Frames</label>
            <input id="fft_max_video_frames" type="number" v-model.number="editableParams.fft_animation.max_video_frames">
          </div>
        </div>
         <div v-if="activeTab === 'stft_animation'">
           <div class="form-group">
            <label for="stft_anim_n_fft">N-FFT</label>
            <input id="stft_anim_n_fft" type="number" v-model.number="editableParams.stft_animation.n_fft">
          </div>
           <div class="form-group">
            <label for="stft_anim_hop_length">Hop Length</label>
            <input id="stft_anim_hop_length" type="number" v-model.number="editableParams.stft_animation.hop_length">
          </div>
          <div class="form-group">
            <label for="stft_anim_win_length">Window Length</label>
            <input id="stft_anim_win_length" type="number" v-model.number="editableParams.stft_animation.win_length">
          </div>
          <div class="form-group">
            <label for="stft_anim_window">Window Type</label>
            <select id="stft_anim_window" v-model="editableParams.stft_animation.window">
              <option v-for="win in windowOptions" :key="win" :value="win">{{ win }}</option>
            </select>
          </div>
          <div class="form-group">
            <label for="stft_anim_cmap">Colormap</label>
            <select id="stft_anim_cmap" v-model="editableParams.stft_animation.cmap">
              <option v-for="c in cmapOptions" :key="c" :value="c">{{ c }}</option>
            </select>
          </div>
          <div class="form-group">
            <label for="stft_anim_frame_nums">Frame Nums</label>
            <input id="stft_anim_frame_nums" type="number" v-model.number="editableParams.stft_animation.frame_nums">
          </div>
          <div class="form-group">
            <label for="stft_anim_render_fps">Render FPS</label>
            <input id="stft_anim_render_fps" type="number" step="0.1" v-model.number="editableParams.stft_animation.render_fps">
          </div>
          <div class="form-group">
            <label for="stft_anim_max_video_frames">Max Video Frames</label>
            <input id="stft_anim_max_video_frames" type="number" v-model.number="editableParams.stft_animation.max_video_frames">
          </div>
        </div>
      <div class="dialog-actions">
        <button @click="save" class="primary">Apply</button>
        <button @click="close">Cancel</button>
      </div>
    </div>
  </div>
  </div>
</template>

<script setup lang="ts">
import { ref, watch, reactive } from 'vue';

const props = defineProps<{
  isOpen: boolean;
  params: any;
}>();

const emit = defineEmits(['close', 'update:params']);

const activeTab = ref('stft');
const tabs = [
  { id: 'waveform', name: 'Waveform' },
  { id: 'spectrum', name: 'Spectrum' },
  { id: 'stft', name: 'Spectrogram' },
  { id: 'fft_animation', name: 'FFT Animation' },
  { id: 'stft_animation', name: 'STFT Animation' },
];

const windowOptions = ['hann', 'hamming', 'blackman', 'bartlett', 'kaiser'];
const cmapOptions = ['viridis', 'plasma', 'inferno', 'magma', 'cividis'];
const rainCmapOptions = ['hsv', 'rainbow', 'turbo', 'viridis', 'plasma', 'inferno', 'magma', 'cividis'];

// Deep copy of params to avoid modifying the original object directly
const editableParams = reactive(JSON.parse(JSON.stringify(props.params)));

watch(() => props.params, (newParams) => {
  Object.assign(editableParams, JSON.parse(JSON.stringify(newParams)));
}, { deep: true });


const close = () => {
  emit('close');
};

const save = () => {
  emit('update:params', JSON.parse(JSON.stringify(editableParams)));
  close();
};
</script>

<style scoped>
.dialog-overlay {
  position: fixed;
  top: 0;
  left: 0;
  width: 100%;
  height: 100%;
  background-color: rgba(0, 0, 0, 0.6);
  display: flex;
  justify-content: center;
  align-items: center;
  z-index: 1000;
}

.dialog-content {
  background-color: #2a2a2a;
  padding: 2rem;
  border-radius: 8px;
  max-height: 90vh;
  max-width: 90%;
  overflow-y: auto;
  box-shadow: 0 5px 15px rgba(0, 0, 0, 0.3);
}

h2 {
  margin-top: 0;
  color: #eee;
}

.tabs {
  display: flex;
  border-bottom: 1px solid #444;
  margin-bottom: 1rem;
}

.tabs button {
  padding: 0.5rem 1rem;
  border: none;
  background: none;
  color: #ccc;
  cursor: pointer;
  font-size: 1rem;
  border-bottom: 2px solid transparent;
  transition: all 0.3s ease;
}

.tabs button.active {
  color: #42b983;
  border-bottom-color: #42b983;
}

.tabs button:hover {
    background-color: #333;
}

.tab-content {
  margin-top: 1rem;
  color: #ddd;
}

.form-group {
  margin-bottom: 1rem;
  display: flex;
  align-items: center;
}

.form-group label {
  flex: 1;
  margin-right: 1rem;
}

.form-group input,
.form-group select {
  flex: 2;
  padding: 0.5rem;
  background-color: #333;
  border: 1px solid #555;
  color: #fff;
  border-radius: 4px;
}

.dialog-actions {
  margin-top: 2rem;
  display: flex;
  justify-content: flex-end;
  gap: 1rem;
}

button {
  padding: 0.6rem 1.2rem;
  border-radius: 4px;
  border: none;
  cursor: pointer;
  font-weight: bold;
}

button.primary {
  background-color: #42b983;
  color: white;
}

.hint {
  font-size: 0.85rem;
  color: #888;
  margin-top: -0.5rem;
  margin-bottom: 1rem;
}
</style>
