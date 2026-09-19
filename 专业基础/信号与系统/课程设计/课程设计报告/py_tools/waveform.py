"""
Generates and saves waveform plots for signals from .mat files.
"""
import os
import numpy as np
import matplotlib.pyplot as plt
from scipy.io import loadmat
from typing import Dict, Any
from lib.log import log

class Config:
    """Configuration for the waveform plotting."""
    FIG_SIZE: tuple[int, int] = (12, 4)
    OUTPUT_DIR: str = r"py_tools/output/waveforms"
    SIGNAL_PATHS: list[str] = [
        r"py_tools/data/signal1.mat",
        r"py_tools/data/signal2.mat",
    ]

def load_signal(file_path: str) -> np.ndarray | None:
    """
    Loads a signal from a .mat file.

    Args:
        file_path (str): The path to the .mat file.

    Returns:
        np.ndarray | None: The loaded signal as a NumPy array, or None if loading fails.
    """
    try:
        log(f"Loading signal from '{file_path}'...")
        mat_data: Dict[str, Any] = loadmat(file_path)
        # Assuming the signal is the first variable in the .mat file that is a numpy array
        for key, value in mat_data.items():
            if isinstance(value, np.ndarray) and not key.startswith("__"):
                signal = value.flatten()
                log(f"Successfully loaded signal with shape {signal.shape} from key '{key}'.")
                return signal
        log(f"Warning: No suitable signal array found in '{file_path}'.")
        return None
    except FileNotFoundError:
        log(f"Error: File not found at '{file_path}'.")
        return None
    except Exception as e:
        log(f"An error occurred while loading '{file_path}': {e}")
        return None

def plot_waveform(
    signal: np.ndarray,
    file_name: str,
    output_dir: str,
    date_input: str,
) -> None:
    """
    Plots the waveform of a signal and saves it to a file.

    Args:
        signal (np.ndarray): The input signal.
        file_name (str): The base name for the output file.
        output_dir (str): The directory to save the plot in.
        date_input (str): The date or identifier string provided by the user.
    """
    fig, ax = plt.subplots(figsize=Config.FIG_SIZE)
    ax.plot(signal)
    ax.set_title(f"Waveform - {file_name}\n")
    ax.set_xlabel("Sample")
    ax.set_ylabel("Amplitude")
    ax.grid(True)

    if not os.path.exists(output_dir):
        os.makedirs(output_dir)
        log(f"Created output directory: {output_dir}")

    output_filename = f"{file_name}{date_input}waveform.png"
    output_path = os.path.join(output_dir, output_filename)
    
    fig.savefig(output_path, bbox_inches='tight', pad_inches=0.1)
    plt.close(fig)
    log(f"Saved waveform plot to '{output_path}'")

def main() -> None:
    """
    Main function to generate and save waveform plots for all configured signals.
    """
    date_str = input("Please enter a date or identifier for the filenames: ")
    log(f"Using identifier: '{date_str}'")

    for signal_path in Config.SIGNAL_PATHS:
        signal_data = load_signal(signal_path)
        if signal_data is not None:
            base_name = os.path.splitext(os.path.basename(signal_path))[0]
            plot_waveform(
                signal=signal_data,
                file_name=base_name,
                output_dir=Config.OUTPUT_DIR,
                date_input=date_str,
            )
    log("Waveform generation process completed.")

if __name__ == "__main__":
    main()