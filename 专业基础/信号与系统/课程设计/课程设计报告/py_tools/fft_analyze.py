from __future__ import annotations

import os
from typing import Any

import matplotlib.pyplot as plt
import numpy as np
from numpy.typing import NDArray
from scipy.io import loadmat

try:
    # 直接运行 `python py_tools/analyze.py` 时，脚本目录会进入导入路径。
    from lib.manual_fft import build_frequency_samples, build_time_samples, fft
except ModuleNotFoundError:
    # 作为包导入 `py_tools.analyze` 时，需要走完整包路径。
    from py_tools.lib.manual_fft import build_frequency_samples, build_time_samples, fft


def analyze_signal(data_path: str, output_path: str, fs: int = 4410) -> None:
    """分析单个信号文件并保存频谱图。"""
    try:
        mat_data: dict[str, Any] = loadmat(data_path)
    except FileNotFoundError:
        print(f"错误：文件 {data_path} 未找到。")
        return

    signal = _extract_signal(mat_data, data_path)
    if signal is None:
        return

    sample_count = signal.size
    if sample_count == 0:
        print(f"警告：{data_path} 中的信号为空，已跳过。")
        return

    # 先构造 t 和 f，再用数值积分形式近似连续傅里叶变换。
    time_samples = build_time_samples(sample_count, fs)
    frequency_samples = build_frequency_samples(sample_count, fs)
    spectrum = fft(signal, time_samples, frequency_samples)

    # 转换为单边谱
    # 找到 0 频率的索引
    zero_freq_index = np.argmin(np.abs(frequency_samples))
    
    # 取单边频谱
    single_sided_freq = frequency_samples[zero_freq_index:]
    single_sided_spectrum = spectrum[zero_freq_index:]
    
    # 幅值加倍（直流分量除外）
    single_sided_spectrum[1:] *= 2

    # 绘制 0 到 fs/2 附近的频谱采样结果。
    plt.figure(figsize=(10, 6))
    plt.plot(single_sided_freq, np.abs(single_sided_spectrum))
    plt.title(f"Fourier Transform - {os.path.basename(data_path)}")
    plt.xlabel("Frequency (Hz)")
    plt.ylabel("Amplitude")
    plt.grid(True)
    plt.tight_layout()
    plt.savefig(output_path)
    plt.close()
    print(f"图像已保存到：{output_path}")


def _extract_signal(
    mat_data: dict[str, Any], data_path: str
) -> NDArray[np.float64] | None:
    """兼容两种变量名，取出一维信号向量。"""
    if "z" in mat_data:
        return np.asarray(mat_data["z"], dtype=np.float64).reshape(-1)
    if "zz" in mat_data:
        return np.asarray(mat_data["zz"], dtype=np.float64).reshape(-1)

    print(f"警告：在 {data_path} 中未找到 'z' 或 'zz' 变量，已跳过。")
    return None


def main() -> None:
    """遍历数据目录中的所有 MAT 文件并生成频谱图。"""
    data_dir = "py_tools/data"
    output_dir = "py_tools/output/spectrum"

    if not os.path.exists(output_dir):
        os.makedirs(output_dir)
        print(f"创建目录：{output_dir}")

    date_input = input("please input an indentifier:")

    for filename in os.listdir(data_dir):
        if not filename.endswith(".mat"):
            continue

        data_file_path = os.path.join(data_dir, filename)
        output_filename = f"{date_input}_{os.path.splitext(filename)[0]}.png"
        output_file_path = os.path.join(output_dir, output_filename)
        analyze_signal(data_file_path, output_file_path,fs=4410)


if __name__ == "__main__":
    main()
