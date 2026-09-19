<template>
  <div class="file-upload">
    <input type="file" @change="handleFileChange" accept=".wav,.mp3" />
    <button @click="uploadFile" :disabled="!selectedFile">Upload</button>
  </div>
</template>

<script setup lang="ts">
import { ref } from 'vue';
import axios from 'axios';
import { API_BASE_URL } from '../api/signal';

const selectedFile = ref<File | null>(null);
const emit = defineEmits(['upload-success']);

const handleFileChange = (event: Event) => {
  const target = event.target as HTMLInputElement;
  if (target.files) {
    selectedFile.value = target.files[0];
  }
};

const uploadFile = async () => {
  if (!selectedFile.value) return;

  const formData = new FormData();
  formData.append('file', selectedFile.value);

  try {
    const response = await axios.post(`${API_BASE_URL}/upload`, formData, {
      headers: {
        'Content-Type': 'multipart/form-data',
      },
    });
    alert('File uploaded successfully!');
    emit('upload-success', response.data.filename);
  } catch (error) {
    console.error('Error uploading file:', error);
    alert('Error uploading file.');
  }
};
</script>

<style scoped>
.file-upload {
  margin-bottom: 20px;
}
input[type="file"] {
  color: var(--text-dark);
}
button {
  width: 100%;
  padding: 10px;
  margin-top: 10px;
  background-color: var(--accent-cyan);
  border: none;
  border-radius: 4px;
  color: var(--dark-blue-bg);
  cursor: pointer;
  font-size: 16px;
  font-weight: bold;
  transition: background-color 0.3s ease;
}
button:hover {
  background-color: #88ffee;
}
button:disabled {
  background-color: #555;
  cursor: not-allowed;
}
</style>
