from __future__ import annotations

import os
from typing import Tuple,Any
import librosa
import matplotlib.animation as animation
import matplotlib.pyplot as plt
import numpy as np
from stft_analyzer import stft as manual_stft
import json
from lib.log import log
CONFIG_JSON_PATH = r"py_tools\docs\output.json"
class Config:
    """Configuration for the spectrogram animation."""
    sr = 44100
    music_path = r"py_tools\data\self_songbie.mp3"
    n_fft = 2**15 # 2048 1024
    hop_length = 2**10 # 512
    fig_size = (12, 7)
    cmap = "viridis"
    audio_bitrate = "192k"
    frame_nums = 10
    output_dir = r"py_tools\output\video\stft"
def update_json(date:str) ->None:
    """Update the JSON file with the current configuration."""
    config_data :dict[str,Any]= {
        "id": date,
        "music_path": Config.music_path,
        "sr": Config.sr,
        "n_fft": Config.n_fft,
        "hop_length": Config.hop_length,
        "fig_size": Config.fig_size,
        "cmap": Config.cmap,
        "audio_bitrate": Config.audio_bitrate,
        "frame_nums": Config.frame_nums,
        "description":"viridis",
    }
    with open(CONFIG_JSON_PATH, "r") as f:
        params_list = json.load(f)
        log(f"Loaded existing config list with {len(params_list)} entries.")
    params_list.append(config_data)
    with open(CONFIG_JSON_PATH, "w") as f:
        json.dump(params_list, f)
    log(f"Updated config list with new entry: {config_data['id']}")


def create_spectrogram_animation(
    input_path: str,
    output_dir: str,
    filename: str,
    sr: int = 44100,
    n_fft: int = 2048,
    hop_length: int = 512,
) -> None:
    """Render a silent STFT animation."""
    os.makedirs(output_dir, exist_ok=True)

    y, sr = librosa.load(input_path, sr=sr)
    log(f"Loaded audio file '{input_path}' with sample rate {sr} and {len(y)} samples.")
    frequencies, _, stft_result = manual_stft(
        y,
        float(sr),
        window_size=n_fft,
        frame_shift=hop_length,
    )
    positive_bin_count = n_fft // 2 + 1
    positive_frequencies = frequencies[:positive_bin_count]
    stft_magnitude = np.abs(stft_result[:positive_bin_count, :])
    D = librosa.amplitude_to_db(stft_magnitude, ref=np.max)
    max_frequency = float(positive_frequencies[-1])
    log(f"Computed STFT with n_fft={n_fft} and hop_length={hop_length}. Result shape: {stft_result.shape}")
    log(f"Max frequency: {max_frequency}")
    fig, ax = plt.subplots(figsize=Config.fig_size)
    fig.patch.set_facecolor("black")
    ax.set_facecolor("black")

    img = ax.imshow(
        D[:, :1],
        aspect="auto",
        origin="lower",
        cmap=Config.cmap,
        extent=[0, hop_length / sr, 0, max_frequency],
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
    ax.set_ylim(1, max_frequency)
    fig.subplots_adjust(left=0, right=1, bottom=0, top=1)
    ax.set_axis_off()

    def update(frame: int) -> Tuple[plt.Artist, ...]:
        current_time = frame * hop_length / sr
        frame_nums = Config.frame_nums
        start_frame = max(0, frame - frame_nums // 2)
        end_frame = start_frame + frame_nums

        if end_frame > D.shape[1]:
            end_frame = D.shape[1]
            start_frame = max(0, end_frame - frame_nums)

        start_time = start_frame * hop_length / sr
        end_time = end_frame * hop_length / sr
        img.set_data(D[:, start_frame:end_frame])
        img.set_extent([start_time, end_time, 0, max_frequency])
        ax.set_xlim(start_time, end_time)
        time_text.set_text(f"{current_time:.2f} s")
        return (img, time_text)

    num_frames = D.shape[1]
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
    log(f"Silent STFT animation saved to: {output_path}")


if __name__ == "__main__":
    date = input("Please enter a date (for example YYYYMMDD): ")
    create_spectrogram_animation(
        input_path=Config.music_path,
        output_dir=Config.output_dir,
        filename=f"{date}_music_stft.mp4",
        sr=Config.sr,
        n_fft=Config.n_fft,
        hop_length=Config.hop_length,
    )
    update_json(date=date)
