from __future__ import annotations

import numpy as np
from numpy.typing import ArrayLike, NDArray

ComplexArray = NDArray[np.complex128]
RealArray = NDArray[np.float64]


def fft(
    signal: ArrayLike,
    time_samples: ArrayLike,
    frequency_samples: ArrayLike,
) -> ComplexArray:
    """按连续傅里叶变换的数值求和公式计算频谱。"""
    values = np.asarray(signal, dtype=np.complex128).reshape(-1)
    time_axis = np.asarray(time_samples, dtype=np.float64).reshape(-1)
    freq_axis = np.asarray(frequency_samples, dtype=np.float64).reshape(-1)

    if values.size != time_axis.size:
        raise ValueError("signal 和 time_samples 的长度必须一致。")
    if values.size == 0 or freq_axis.size == 0:
        return np.zeros(freq_axis.size, dtype=np.complex128)

    sample_interval = _get_sample_interval(time_axis)
    result = np.zeros(freq_axis.size, dtype=np.complex128)

    # 对频率点和时间点做双重循环求和。
    for k in range(freq_axis.size):
        for i in range(time_axis.size):
            result[k] += (
                values[i]
                * np.exp(-2j * np.pi * freq_axis[k] * time_axis[i])
                * sample_interval
            )

    return result


def build_time_samples(sample_count: int, fs: float) -> RealArray:
    """生成时间采样点 t_n = n / fs。"""
    if sample_count < 0:
        raise ValueError("sample_count 不能为负数。")
    if fs <= 0:
        raise ValueError("fs 必须大于 0。")
    return np.arange(sample_count, dtype=np.float64) / fs


def build_frequency_samples(sample_count: int, fs: float) -> RealArray:
    """生成频率采样点 f_k = k * fs / N。"""
    if sample_count <= 0:
        raise ValueError("sample_count 必须是正整数。")
    if fs <= 0:
        raise ValueError("fs 必须大于 0。")
    return np.arange(sample_count, dtype=np.float64) * fs / sample_count


def _get_sample_interval(time_axis: RealArray) -> float:
    """根据时间轴估计积分中的采样间隔。"""
    if time_axis.size <= 1:
        return 1.0
    return float(time_axis[1] - time_axis[0])
