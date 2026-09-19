from __future__ import annotations
import logging
import os
from typing import List
# 创建一个 logger
logger = logging.getLogger('project_logger')
logger.setLevel(logging.INFO)

# 防止重复添加 handlers
if not logger.handlers:
    # 定义日志文件路径
    log_file_path = os.path.join(os.path.dirname(__file__), '..', 'data', 'project.log')

    # 确保日志文件所在的目录存在
    os.makedirs(os.path.dirname(log_file_path), exist_ok=True)

    # 创建一个 handler，用于写入日志文件
    file_handler = logging.FileHandler(log_file_path, encoding='utf-8')
    file_handler.setLevel(logging.INFO)

    # 创建一个 handler, 用于输出到控制台
    console_handler = logging.StreamHandler()
    console_handler.setLevel(logging.INFO)

    # 定义 handler 的输出格式
    formatter = logging.Formatter('%(asctime)s - %(levelname)s - %(message)s')
    file_handler.setFormatter(formatter)
    console_handler.setFormatter(formatter)

    # 给 logger 添加 handler
    logger.addHandler(file_handler)
    logger.addHandler(console_handler)

def log(message:object, level : str='info'):
    """
    记录日志到控制台和文件。
    :param message: 要记录的信息。
    :param level: 日志级别 ('info', 'debug', 'warning', 'error', 'critical')。
    """
    if level == 'debug':
        logger.debug(message)
    elif level == 'warning':
        logger.warning(message)
    elif level == 'error':
        logger.error(message)
    elif level == 'critical':
        logger.critical(message)
    else:
        logger.info(message)

def print_table(headers: List[str], rows: List[List[str]]) -> None:
    """
    打印一个格式化的文本表格。

    Args:
        headers: 表头字符串列表。
        rows: 包含行数据的列表的列表。
    """
    if not headers or not rows:
        print("没有数据可供打印。")
        return

    # 计算每列的最大宽度
    column_widths = [len(header) for header in headers]
    for row in rows:
        for i, cell in enumerate(row):
            if len(cell) > column_widths[i]:
                column_widths[i] = len(cell)

    # 打印表头
    header_line = " | ".join(
        f"{header:<{column_widths[i]}}" for i, header in enumerate(headers)
    )
    print(header_line)

    # 打印分隔线
    separator_line = "-+-".join("-" * width for width in column_widths)
    print(separator_line)

    # 打印数据行
    for row in rows:
        row_line = " | ".join(
            f"{cell:<{column_widths[i]}}" for i, cell in enumerate(row)
        )
        print(row_line)
