'''Waveform plot for music signal.
'''
import librosa
import matplotlib.pyplot as plt
import numpy as np
import json
import os
from typing import Any
from lib.log import log

CONFIG_JSON_PATH = r"py_tools\docs\music_waveform.json"

class Config:
    """Configuration for the waveform plot."""
    sr = 44100
    fig_size = (12, 4)
    music_path = r"py_tools\data\self_songbie.mp3"

def update_json(date: str) -> None:
    """Update the JSON file with the current configuration."""
    config_data: dict[str, Any] = {
        "id": date,
        "music_path": Config.music_path,
        "sr": Config.sr,
        "fig_size": Config.fig_size,
    }
    with open(CONFIG_JSON_PATH, "r") as f:
        params_list = json.load(f)
        log(f"Loaded existing config list with {len(params_list)} entries.")
    params_list.append(config_data)
    with open(CONFIG_JSON_PATH, "w") as f:
        json.dump(params_list, f)
    log(f"Updated config list with new entry: {config_data['id']}")

def plot_waveform(
    y: np.ndarray,
    sr: float,
    file_name: str,
    output_dir: str,
    date_input: str,
) -> None:
    """Plots and saves the time-domain waveform."""
    t = np.linspace(0, len(y) / sr, len(y))
    fig, ax = plt.subplots(figsize=Config.fig_size)
    ax.plot(t, y, linewidth=0.5)
    ax.set_title(f"self_songbie.mp3 - Waveform")
    ax.set_xlabel("t (s)")
    ax.set_ylabel("Amplitude")
    ax.grid(True)

    base_name = os.path.splitext(file_name)[0]
    output_filename = f"{date_input}_{base_name}.png"
    output_path = os.path.join(output_dir, output_filename)
    plt.show()
    fig.savefig(output_path, bbox_inches='tight', pad_inches=0.1)
    plt.close()
    log(f"Saved waveform plot to {output_path}")


y, sr = librosa.load(Config.music_path, sr=Config.sr)
log(f"Loaded audio file '{Config.music_path}' with sample rate {sr} and {len(y)} samples.")
date = input("please input:")
plot_waveform(
    y=y,
    sr=sr,
    file_name="music_waveform",
    output_dir="py_tools/output/music_waveform",
    date_input=date,
)
log("Waveform plotting completed successfully.")
update_json(date=date)
