from __future__ import annotations

import os
from typing import Any

import numpy as np
from numpy.typing import NDArray
from scipy.io import loadmat

try:
    # 兼容直接运行和作为包导入两种情况
    from py_tools.lib.log import print_table
except ModuleNotFoundError:
    from lib.log import print_table


def calculate_stats(signal: NDArray[np.float64]) -> dict[str, float]:
    """
    计算信号的均值、方差和总能量。

    Args:
        signal: 一维信号数组。

    Returns:
        包含信号统计特征的字典。
    """
    mean = np.mean(signal)
    variance = np.var(signal)
    total_energy = np.sum(signal**2)
    return {"mean": mean, "variance": variance, "total_energy": total_energy}


def _extract_signal(
    mat_data: dict[str, Any], data_path: str
) -> NDArray[np.float64] | None:
    """从 .mat 文件数据中提取一维信号向量，兼容 'z' 和 'zz' 两种变量名。"""
    if "z" in mat_data:
        return np.asarray(mat_data["z"], dtype=np.float64).reshape(-1)
    if "zz" in mat_data:
        return np.asarray(mat_data["zz"], dtype=np.float64).reshape(-1)

    print(f"警告：在 {data_path} 中未找到 'z' 或 'zz' 变量，已跳过。")
    return None


def analyze_and_print_stats(data_path: str) -> dict[str, float] | None:
    """
    分析单个信号文件并打印其统计特征。

    Args:
        data_path: .mat 文件的路径。

    Returns:
        如果成功，返回包含统计特征的字典，否则返回 None。
    """
    try:
        mat_data = loadmat(data_path)
    except FileNotFoundError:
        print(f"错误：文件 {data_path} 未找到。")
        return None

    signal = _extract_signal(mat_data, data_path)
    if signal is None or signal.size == 0:
        print(f"警告：{data_path} 中的信号为空或无效，已跳过。")
        return None

    stats = calculate_stats(signal)
    return stats


def main() -> None:
    """
    遍历数据目录中的所有 .mat 文件，计算并以表格形式打印它们的统计特征。
    """
    data_dir = "py_tools/data"
    all_stats = []
    filenames = []

    file_list = sorted([f for f in os.listdir(data_dir) if f.endswith(".mat")])

    for filename in file_list:
        data_file_path = os.path.join(data_dir, filename)
        stats = analyze_and_print_stats(data_file_path)
        if stats:
            all_stats.append(stats)
            filenames.append(filename)

    if not all_stats:
        print("未能计算任何信号的统计数据。")
        return

    # 准备并打印表格
    headers = ["Signal", "Mean", "Variance", "Total Energy"]
    rows = []
    for i, stats in enumerate(all_stats):
        rows.append(
            [
                filenames[i],
                f"{stats['mean']:.4f}",
                f"{stats['variance']:.4f}",
                f"{stats['total_energy']:.4f}",
            ]
        )

    print("\n信号基本特征分析:")
    print_table(headers, rows)


if __name__ == "__main__":
    main()
