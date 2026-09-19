from __future__ import annotations

import json
import os
from typing import Any, Tuple

import librosa
import matplotlib.animation as animation
import matplotlib.pyplot as plt
import numpy as np
from matplotlib.collections import LineCollection

from lib.log import log

CONFIG_JSON_PATH = r"py_tools\docs\output.json"


class Config:
    """Configuration for the spectrum animation."""

    sr = 44100
    music_path = r"py_tools\data\self_songbie.mp3"
    n_fft = 2**15
    hop_length = 2**10
    fig_size = (12, 7)
    cmap = "magma"
    audio_bitrate = "192k"
    output_dir = r"py_tools\output\video\fft"
    rain_drop_count = 120
    rain_length_min = 4.0
    rain_length_max = 12.0
    rain_width_min = 1.5
    rain_width_max = 3.5
    rain_alpha = 0.8


def update_json(date: str) -> None:
    """Update the JSON file with the current configuration."""
    config_data: dict[str, Any] = {
        "id": date,
        "music_path": Config.music_path,
        "sr": Config.sr,
        "n_fft": Config.n_fft,
        "hop_length": Config.hop_length,
        "fig_size": Config.fig_size,
        "cmap": Config.cmap,
        "audio_bitrate": Config.audio_bitrate,
        "rain_drop_count": Config.rain_drop_count,
        "rain_length_min": Config.rain_length_min,
        "rain_length_max": Config.rain_length_max,
        "rain_width_min": Config.rain_width_min,
        "rain_width_max": Config.rain_width_max,
        "rain_alpha": Config.rain_alpha,
        "description": "尝试减慢雨速",
    }
    with open(CONFIG_JSON_PATH, "r") as f:
        params_list = json.load(f)
        log(f"Loaded existing config list with {len(params_list)} entries.")
    params_list.append(config_data)
    with open(CONFIG_JSON_PATH, "w") as f:
        json.dump(params_list, f)
    log(f"Updated config list with new entry: {config_data['id']}")


def _build_rainbow_rain_segments(
    rng: np.random.Generator,
    min_frequency: float,
    max_frequency: float,
    min_db: float,
    max_db: float,
) -> tuple[np.ndarray, np.ndarray, np.ndarray]:
    """Generate one frame of decorative rainbow rain segments."""
    drop_count = Config.rain_drop_count
    log_x = rng.uniform(np.log10(min_frequency), np.log10(max_frequency), drop_count)
    x_positions = np.power(10.0, log_x)
    y_starts = rng.uniform(min_db, max_db, drop_count)
    lengths = rng.uniform(Config.rain_length_min, Config.rain_length_max, drop_count)
    y_ends = np.maximum(y_starts - lengths, min_db)
    colors = plt.cm.hsv(rng.random(drop_count))
    widths = rng.uniform(Config.rain_width_min, Config.rain_width_max, drop_count)
    segments = np.stack(
        (
            np.column_stack((x_positions, y_starts)),
            np.column_stack((x_positions, y_ends)),
        ),
        axis=1,
    )
    return segments, colors, widths


def create_spectrum_animation(
    input_path: str,
    output_dir: str,
    filename: str,
    sr: int = 44100,
    n_fft: int = 2048,
    hop_length: int = 512,
) -> None:
    """Render a silent frame-wise FFT spectrum animation."""
    os.makedirs(output_dir, exist_ok=True)

    if n_fft <= 0:
        raise ValueError("n_fft must be positive.")
    if hop_length <= 0:
        raise ValueError("hop_length must be positive.")

    y, sr = librosa.load(input_path, sr=sr)
    log(f"Loaded audio file '{input_path}' with sample rate {sr} and {len(y)} samples.")

    if len(y) < n_fft:
        raise ValueError("n_fft must not exceed the audio length.")

    num_frames = (len(y) - n_fft) // hop_length + 1
    positive_bin_count = n_fft // 2 + 1
    positive_frequencies = np.arange(positive_bin_count, dtype=np.float64) * sr / n_fft
    spectrum_magnitude = np.zeros((positive_bin_count, num_frames), dtype=np.float64)
    window = np.ones(n_fft, dtype=np.float64)

    for frame_index in range(num_frames):
        start_index = frame_index * hop_length
        end_index = start_index + n_fft
        frame = y[start_index:end_index] * window
        fft_result = np.fft.fft(frame, n=n_fft)
        spectrum_magnitude[:, frame_index] = np.abs(fft_result[:positive_bin_count])

    D = librosa.amplitude_to_db(spectrum_magnitude, ref=np.max)
    max_frequency = float(positive_frequencies[-1])
    min_frequency = float(positive_frequencies[1])
    min_db = float(np.min(D))
    log(
        "Computed frame-wise FFT with "
        f"n_fft={n_fft}, hop_length={hop_length}. Result shape: {spectrum_magnitude.shape}"
    )
    log(f"Frequency range: {min_frequency} Hz to {max_frequency} Hz")

    fig, ax = plt.subplots(figsize=Config.fig_size)
    fig.patch.set_facecolor("black")
    ax.set_facecolor("black")
    rng = np.random.default_rng()

    line_color = plt.get_cmap(Config.cmap)(0.85)
    line, = ax.plot(
        positive_frequencies[1:],
        D[1:, 0],
        color=line_color,
        linewidth=1.5,
        zorder=2,
    )
    rain_lines = LineCollection([], alpha=Config.rain_alpha, zorder=1, capstyle="round")
    ax.add_collection(rain_lines)
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

    ax.set_xlim(min_frequency, max_frequency)
    ax.set_ylim(min_db, 0)
    ax.set_xscale("log")
    fig.subplots_adjust(left=0, right=1, bottom=0, top=1)
    ax.set_axis_off()

    def update(frame: int) -> Tuple[plt.Artist, ...]:
        current_time = frame * hop_length / sr
        line.set_ydata(D[1:, frame])
        segments, colors, widths = _build_rainbow_rain_segments(
            rng,
            min_frequency,
            max_frequency,
            min_db,
            0.0,
        )
        rain_lines.set_segments(segments)
        rain_lines.set_colors(colors)
        rain_lines.set_linewidths(widths)
        time_text.set_text(f"{current_time:.2f} s")
        return (line, rain_lines, time_text)

    fps = sr / hop_length
    ani = animation.FuncAnimation(
        fig,
        update,
        frames=num_frames,
        blit=True,
        interval=hop_length / sr * 1000,
    )

    output_path = os.path.join(output_dir, filename)
    ani.save(output_path, writer="ffmpeg", fps=int(fps))
    plt.close(fig)
    log(f"Silent FFT spectrum animation saved to: {output_path}")


if __name__ == "__main__":
    date = input("Please enter a date (for example YYYYMMDD): ")
    create_spectrum_animation(
        input_path=Config.music_path,
        output_dir=Config.output_dir,
        filename=f"{date}_music_fft.mp4",
        sr=Config.sr,
        n_fft=Config.n_fft,
        hop_length=Config.hop_length,
    )
    update_json(date=date)
