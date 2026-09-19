from __future__ import annotations

import os

import matplotlib.pyplot as plt
import numpy as np
import scipy.io as sio
from numpy.typing import NDArray

FloatArray = NDArray[np.float64]
ComplexArray = NDArray[np.complex128]


def load_signal(file_path: str) -> FloatArray:
    """Load a 1D signal from a .mat file."""
    mat_contents = sio.loadmat(file_path)

    if "z" in mat_contents:
        signal = mat_contents["z"]
    elif "zz" in mat_contents:
        signal = mat_contents["zz"]
    else:
        valid_keys = [key for key in mat_contents if not key.startswith("__")]
        if not valid_keys:
            raise ValueError(f"No valid signal variable found in {file_path}.")
        signal = mat_contents[valid_keys[0]]

    return np.asarray(signal, dtype=np.float64).reshape(-1)


def stft(
    signal: FloatArray,
    fs: float,
    window_size: int,
    frame_shift: int | None = None,
) -> tuple[FloatArray, FloatArray, ComplexArray]:
    """
    Compute STFT with manual framing, rectangular windowing, and per-frame FFT.

    `frame_shift` defaults to half-window overlap to preserve the original behavior
    of this script.
    """
    samples = np.asarray(signal, dtype=np.float64).reshape(-1)
    if samples.size == 0:
        raise ValueError("Input signal must not be empty.")
    if fs <= 0:
        raise ValueError("Sampling rate must be positive.")
    if window_size <= 0:
        raise ValueError("Window size must be positive.")
    if window_size > samples.size:
        raise ValueError("Window size must not exceed signal length.")

    if frame_shift is None:
        frame_shift = max(window_size // 2, 1)
    if frame_shift <= 0:
        raise ValueError("Frame shift must be positive.")

    nfft = window_size
    num_frames = (samples.size - window_size) // frame_shift + 1
    window = np.ones(window_size, dtype=np.float64)

    spectrum = np.zeros((nfft, num_frames), dtype=np.complex128)
    frequencies = np.arange(nfft, dtype=np.float64) * fs / nfft

    for frame_index in range(num_frames):
        start_index = frame_index * frame_shift
        end_index = start_index + window_size
        frame = samples[start_index:end_index] * window
        spectrum[:, frame_index] = np.fft.fft(frame, n=nfft)

    times = (np.arange(num_frames, dtype=np.float64) * frame_shift + window_size / 2) / fs
    return frequencies, times, spectrum


def plot_stft(
    frequencies: FloatArray,
    times: FloatArray,
    spectrum: ComplexArray,
    file_name: str,
    output_dir: str,
    date_input: str,
    window_size: int,
    fs: float,
    cmap: str = "viridis",
) -> None:
    """Plot and save an STFT magnitude spectrogram."""
    plt.figure(figsize=(10, 6))
    plt.pcolormesh(times, frequencies, np.abs(spectrum), shading="gouraud", cmap=cmap)
    plt.title(f"STFT (W={window_size}) - {file_name}\nDate: {date_input}")
    plt.xlabel("t (s)")
    plt.ylabel("f (Hz)")
    plt.colorbar(label="Magnitude")
    plt.ylim(0, fs / 2)

    base_name = os.path.splitext(file_name)[0]
    output_filename = f"{date_input}_{base_name}_stft_W{window_size}.png"
    output_path = os.path.join(output_dir, output_filename)

    plt.savefig(output_path)
    plt.close()
    print(f"Saved STFT plot to: {output_path}")


def main() -> None:
    """Run STFT analysis for all .mat files in the data directory."""
    data_dir = "py_tools/data"
    output_dir = "py_tools/output"
    os.makedirs(output_dir, exist_ok=True)

    date_input = input("请输入日期（例如 20240101）：")
    window_sizes = [700,1400,2800]
    fs = 4410.0

    for file_name in os.listdir(data_dir):
        if not file_name.endswith(".mat"):
            continue

        file_path = os.path.join(data_dir, file_name)
        try:
            signal = load_signal(file_path)
            for window_size in window_sizes:
                frequencies, times, spectrum = stft(signal, fs, window_size)
                plot_stft(
                    frequencies,
                    times,
                    spectrum,
                    file_name,
                    output_dir,
                    date_input,
                    window_size,
                    fs,
                )
        except (ValueError, FileNotFoundError) as error:
            print(f"处理文件 {file_name} 时出错：{error}")
        except Exception as error:
            print(f"处理文件 {file_name} 时发生未知错误：{error}")


if __name__ == "__main__":
    main()
