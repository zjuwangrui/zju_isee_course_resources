'''STFT analysis for music signals.
'''
import librosa
import matplotlib.pyplot as plt
import numpy as np
from stft_analyzer import stft as manual_stft
import json
from typing import Any
from lib.log import log
import os

CONFIG_JSON_PATH = r"py_tools\docs\music_stft.json"

class Config:
    """Configuration for the spectrogram animation."""
    sr = 44100
    n_fft = 2 ** 15 # 2048 1024
    hop_length = 2 ** 10 # 512
    fig_size = (12, 7)
    cmap = "magma"
    music_path = r"py_tools\data\self_songbie.mp3"
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
        "description":"use y log scale and a larger n_fft for better frequency resolution"
    }
    with open(CONFIG_JSON_PATH, "r") as f:
        params_list = json.load(f)
        log(f"Loaded existing config list with {len(params_list)} entries.")
    params_list.append(config_data)
    with open(CONFIG_JSON_PATH, "w") as f:
        json.dump(params_list, f)
    log(f"Updated config list with new entry: {config_data['id']}")

def plot_stft(
    stft_result: np.ndarray,
    frequencies: np.ndarray,
    file_name: str,
    output_dir: str,
    date_input: str,
    window_size: int,
    fs: float,
    cmap: str = "viridis",
) -> None:
    """Plots and saves the STFT magnitude spectrogram."""
    positive_bin_count = window_size // 2 + 1
    positive_frequencies = frequencies[:positive_bin_count]
    stft_magnitude = np.abs(stft_result[:positive_bin_count, :])
    D = librosa.amplitude_to_db(stft_magnitude, ref=np.max)
    max_frequency = float(positive_frequencies[-1])
    fig, ax = plt.subplots(figsize=Config.fig_size)
    ax.set_yscale("log")
    img = ax.imshow(
        D,
        aspect="auto",
        origin="lower",
        cmap=cmap,
        extent=[0, D.shape[1] * Config.hop_length / fs, 0, max_frequency],
    )
    ax.set_ylim(0, max_frequency)
    ax.set_title(f"STFT (W={window_size}) - {file_name}")
    ax.set_xlabel("t (s)")
    ax.set_ylabel("f (Hz)")
    fig.colorbar(img, ax=ax, label="Magnitude (dB)")

    base_name = os.path.splitext(file_name)[0]
    output_filename = f"{date_input}_{base_name}_W{window_size}.png"
    output_path = os.path.join(output_dir, output_filename)
    plt.show()
    fig.savefig(output_path,bbox_inches='tight', pad_inches=0.1)
    plt.close()
    log(f"Saved STFT spectrogram to {output_path}")

y, sr = librosa.load(Config.music_path, sr=Config.sr)
log(f"Loaded audio file '{Config.music_path}' with sample rate {sr} and {len(y)} samples.")
frequencies, t, stft_result = manual_stft(
    y,
    float(sr),
    window_size=Config.n_fft,
    frame_shift=Config.hop_length,
)
log(f"Computed STFT with n_fft={Config.n_fft} and hop_length={Config.hop_length}. Result shape: {stft_result.shape}")
date = input("please input:")
plot_stft(
    stft_result=stft_result,
    frequencies=frequencies,
    file_name="music_stft",
    output_dir="py_tools/output/music_stft",
    date_input=date,
    window_size=Config.n_fft,
    fs=Config.sr,
    cmap=Config.cmap
)

log("STFT analysis and plotting completed successfully.")
update_json(date=date)