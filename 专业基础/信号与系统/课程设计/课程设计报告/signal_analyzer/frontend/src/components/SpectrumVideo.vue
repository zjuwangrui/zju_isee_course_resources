<template>
  <div class="video-container">
    <video v-if="videoUrl" :src="videoUrl" controls></video>
    <div v-else class="placeholder">
      <div v-if="status === 'queued' || status === 'running'" class="task-state">
        <div class="status-line">{{ message || 'Generating spectrum video' }}</div>
        <progress :value="progress" max="100"></progress>
        <div class="progress-text">{{ progress }}%</div>
      </div>
      <div v-else-if="status === 'failed'" class="task-state error">
        <div class="status-line">Video generation failed</div>
        <div class="error-text">{{ error }}</div>
      </div>
      <div v-else>No video to display</div>
    </div>
    <a
      v-if="videoUrl"
      :href="videoUrl"
      download="spectrum_video.mp4"
      target="_blank"
      rel="noopener noreferrer"
    >
      <button>Download Video</button>
    </a>
  </div>
</template>

<script setup lang="ts">

defineProps<{
  videoUrl: string;
  status: string;
  progress: number;
  message: string;
  error: string;
}>();
</script>

<style scoped>
.video-container {
  border: 1px solid var(--border-color);
  padding: 10px;
  margin-bottom: 10px;
  text-align: center;
  background-color: var(--dark-blue-bg);
  border-radius: 4px;
}
h4 {
  color: var(--text-light);
}
video {
  max-width: 100%;
  border: 1px solid var(--border-color);
  border-radius: 4px;
}
.placeholder {
  height: 300px;
  display: flex;
  align-items: center;
  justify-content: center;
  color: var(--text-dark);
  border: 1px dashed var(--border-color);
  border-radius: 4px;
}
.task-state {
  width: min(360px, 90%);
}
.status-line {
  margin-bottom: 12px;
  color: var(--text-light);
}
progress {
  width: 100%;
  height: 12px;
}
.progress-text {
  margin-top: 8px;
  font-size: 14px;
}
.error .status-line {
  color: #ff8a8a;
}
.error-text {
  margin-top: 8px;
  color: var(--text-dark);
}
button {
  margin-top: 10px;
  padding: 8px 15px;
  background-color: #42b983;
  border: none;
  border-radius: 4px;
  color: #fff;
  cursor: pointer;
  transition: background-color 0.3s ease;
}
button:hover {
  background-color: #369f6e;
}
</style>
