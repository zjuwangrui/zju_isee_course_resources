<template>
  <div class="plot-container">
    <img v-if="plotUrl" :src="plotUrl" alt="Spectrum" />
    <div v-else class="placeholder">No data to display</div>
    <div class="button-wrapper">
      <button v-if="plotUrl" @click="saveImage">Save Image</button>
    </div>
  </div>
</template>

<script setup lang="ts">
const props = defineProps<{
  plotUrl: string;
}>();

const saveImage = () => {
  if (!props.plotUrl) return;
  const a = document.createElement('a');
  a.href = props.plotUrl;
  a.download = 'spectrum.png';
  document.body.appendChild(a);
  a.click();
  document.body.removeChild(a);
};
</script>

<style scoped>
.plot-container {
  border: 1px solid #eee;
  padding: 10px;
  margin-bottom: 10px;
  text-align: center;
}

img {
  max-width: 100%;
  display: block;        /* 让图片独占一行 */
  margin: 0 auto;        /* 居中（如果图片比容器小） */
}

.placeholder {
  height: 200px;
  display: flex;
  align-items: center;
  justify-content: center;
  color: #888;
  border: 1px dashed #ccc;
}

.button-wrapper {
  margin-top: 12px;      /* 图片和按钮之间的间距 */
}

button {
  padding: 6px 12px;
  background-color: #42b983;
  color: white;
  border: none;
  border-radius: 4px;
  cursor: pointer;
}

button:hover {
  background-color: #369f6e;
}
</style>