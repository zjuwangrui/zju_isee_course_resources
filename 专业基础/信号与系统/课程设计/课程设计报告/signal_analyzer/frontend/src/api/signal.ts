import axios from 'axios';

const configuredApiBaseUrl = import.meta.env.VITE_API_BASE_URL;
export const API_BASE_URL =
  configuredApiBaseUrl === undefined ? 'http://localhost:5000' : configuredApiBaseUrl;

export interface AnimationParams {
  sr?: number;
  n_fft?: number;
  hop_length?: number;
  win_length?: number;
  window?: string;
  cmap?: string;
  rain_drop_count?: number;
  rain_cmap?: string;
  rain_length_min?: number;
  rain_length_max?: number;
  rain_width_min?: number;
  rain_width_max?: number;
  rain_alpha?: number;
  frame_nums?: number;
  render_fps?: number;
  max_video_frames?: number;
}

export interface StftAnimationResponse {
  task_id: string;
}

export const createStftAnimation = async (
  filename: string,
  params: AnimationParams = {},
): Promise<StftAnimationResponse> => {
  const response = await axios.post<StftAnimationResponse>(
    `${API_BASE_URL}/animate/${filename}`,
    null,
    { params },
  );
  return response.data;
};

export const toAbsoluteApiUrl = (path: string): string => {
  if (path.startsWith('http://') || path.startsWith('https://')) {
    return path;
  }
  return `${API_BASE_URL}${path}`;
};
