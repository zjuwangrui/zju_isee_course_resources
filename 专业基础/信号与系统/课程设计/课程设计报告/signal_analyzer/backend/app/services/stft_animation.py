from __future__ import annotations

import os
from collections.abc import Callable

import librosa
import matplotlib

matplotlib.use("Agg")
import matplotlib.animation as animation
import matplotlib.pyplot as plt
import numpy as np
from typing import TypedDict

import logging
from .audio_muxing import mux_audio_track
from .animation_rendering import build_frame_schedule
from .stft_analyzer import stft as manual_stft


class AnimationParams(TypedDict):
    """Parameters for spectrogram animation."""

    sr: int
    n_fft: int
    hop_length: int
    win_length: int
    window: str
    cmap: str
    frame_nums: int
    render_fps: float
    max_video_frames: int


def create_spectrogram_animation(
    input_path: str,
    output_dir: str,
    filename: str,
    sr: int = 22050,
    n_fft: int = 2048,
    hop_length: int = 512,
    win_length: int = 2048,
    window: str = "hann",
    cmap: str = "viridis",
    frame_nums: int = 10,
    render_fps: float = 12.0,
    max_video_frames: int = 900,
    progress_callback: Callable[[float, str], None] | None = None,
) -> str:
    """Render an STFT animation with the source audio track."""
    os.makedirs(output_dir, exist_ok=True)

    if n_fft <= 0:
        raise ValueError("n_fft must be positive.")
    if hop_length <= 0:
        raise ValueError("hop_length must be positive.")
    if win_length <= 0:
        raise ValueError("win_length must be positive.")
    if n_fft < win_length:
        raise ValueError("n_fft must not be smaller than win_length.")
    if frame_nums <= 0:
        raise ValueError("frame_nums must be positive.")
    if render_fps <= 0:
        raise ValueError("render_fps must be positive.")
    if max_video_frames <= 0:
        raise ValueError("max_video_frames must be positive.")

    if progress_callback:
        progress_callback(0.02, "Loading audio")
    y, sr = librosa.load(input_path, sr=sr)
    logging.info(
        "Loaded audio file '%s' for STFT animation with sample rate %s and %s samples.",
        input_path,
        sr,
        len(y),
    )

    if progress_callback:
        progress_callback(0.08, "Computing STFT")
    frequencies, _, stft_result = manual_stft(
        y,
        float(sr),
        window_size=win_length,
        frame_shift=hop_length,
        window_type=window,
        n_fft=n_fft,
    )
    positive_bin_count = n_fft // 2 + 1
    positive_frequencies = frequencies[:positive_bin_count]
    stft_magnitude = np.abs(stft_result[:positive_bin_count, :])
    D = librosa.amplitude_to_db(stft_magnitude, ref=np.max)
    max_frequency = float(positive_frequencies[-1])
    logging.info(
        "Computed STFT animation data with n_fft=%s, hop_length=%s, win_length=%s, window=%s. Result shape: %s",
        n_fft,
        hop_length,
        win_length,
        window,
        stft_magnitude.shape,
    )

    fig, ax = plt.subplots(figsize=(12, 7))
    fig.patch.set_facecolor("black")
    ax.set_facecolor("black")

    min_frequency = float(positive_frequencies[1]) if len(positive_frequencies) > 1 else 1.0
    visible_D = D[1:, :] if D.shape[0] > 1 else D

    img = ax.imshow(
        visible_D[:, :1],
        aspect="auto",
        origin="lower",
        cmap=cmap,
        extent=[0, hop_length / sr, min_frequency, max_frequency],
        vmin=float(np.min(D)),
        vmax=0.0,
    )
    time_text = ax.text(
        0.98,
        0.95,
        "0.00 s",
        color="white",
        fontsize=12,
        ha="right",
        va="top",
        transform=ax.transAxes,
    )
    ax.set_ylim(min_frequency, max_frequency)
    ax.set_yscale("log")
    fig.subplots_adjust(left=0, right=1, bottom=0, top=1)
    ax.set_axis_off()

    def update(source_frame: int) -> tuple[plt.Artist, ...]:
        current_time = source_frame * hop_length / sr
        start_frame = max(0, source_frame - frame_nums // 2)
        end_frame = start_frame + frame_nums

        if end_frame > D.shape[1]:
            end_frame = D.shape[1]
            start_frame = max(0, end_frame - frame_nums)

        start_time = start_frame * hop_length / sr
        end_time = end_frame * hop_length / sr
        img.set_data(visible_D[:, start_frame:end_frame])
        img.set_extent([start_time, end_time, min_frequency, max_frequency])
        ax.set_xlim(start_time, end_time)
        time_text.set_text(f"{current_time:.2f} s")
        return (img, time_text)

    num_frames = D.shape[1]
    source_fps = sr / hop_length
    frame_schedule, output_fps, duration = build_frame_schedule(
        source_frame_count=num_frames,
        source_fps=source_fps,
        requested_fps=render_fps,
        max_frames=max_video_frames,
    )
    logging.info(
        "Rendering STFT animation with %s/%s frames at %.2f fps (duration %.2fs).",
        len(frame_schedule),
        num_frames,
        output_fps,
        duration,
    )
    if progress_callback:
        progress_callback(0.15, "Rendering STFT video")

    ani = animation.FuncAnimation(
        fig,
        update,
        frames=frame_schedule,
        blit=True,
        interval=1000 / output_fps,
    )

    output_path = os.path.join(output_dir, filename)
    silent_output_path = os.path.join(output_dir, f".{os.path.splitext(filename)[0]}_silent.mp4")
    writer = animation.FFMpegWriter(
        fps=max(1, int(round(output_fps))),
        codec="h264",
        extra_args=["-pix_fmt", "yuv420p", "-preset", "veryfast", "-crf", "23"],
    )

    def save_progress(frame_number: int, total_frames: int) -> None:
        if progress_callback and total_frames:
            progress_callback(
                0.15 + 0.75 * ((frame_number + 1) / total_frames),
                f"Rendering STFT video {frame_number + 1}/{total_frames}",
            )

    try:
        ani.save(silent_output_path, writer=writer, progress_callback=save_progress)
    finally:
        plt.close(fig)

    logging.info("Silent STFT animation saved to: %s", silent_output_path)
    if progress_callback:
        progress_callback(0.92, "Muxing source audio")

    try:
        mux_audio_track(silent_output_path, input_path, output_path)
    finally:
        try:
            os.remove(silent_output_path)
        except FileNotFoundError:
            pass

    if progress_callback:
        progress_callback(0.98, "Finalizing STFT video")
    logging.info("STFT animation with audio saved to: %s", output_path)
    return output_path
