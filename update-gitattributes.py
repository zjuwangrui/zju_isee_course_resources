import os
import re
from typing import List, Optional

def find_large_files(working_dir: str, size_threshold: int) -> List[str]:
    """
    在指定目录中查找大于给定大小阈值的文件。
    
    :param working_dir: 要搜索的目录。
    :param size_threshold: 文件大小阈值（以字节为单位）。
    :return: 大于阈值的文件路径列表。
    """
    print("正在查找大于 100MB 的文件...")
    large_files: List[str] = []
    for root, dirs, files in os.walk(working_dir):
        # 排除 .git 目录
        if '.git' in dirs:
            dirs.remove('.git')
            
        for file in files:
            file_path: str = os.path.join(root, file)
            try:
                if os.path.getsize(file_path) > size_threshold:
                    large_files.append(file_path)
            except OSError:
                # 忽略无法访问的文件
                continue
    return large_files

def read_gitattributes(gitattributes_path: str) -> Optional[str]:
    """
    读取 .gitattributes 文件的内容，如果文件不存在则创建它。

    :param gitattributes_path: .gitattributes 文件的路径。
    :return: .gitattributes 文件的内容，如果读取失败则返回 None。
    """
    if not os.path.exists(gitattributes_path):
        with open(gitattributes_path, "w", encoding="utf-8") as f:
            pass
        print(".gitattributes 文件已创建。")
        return ""
    
    try:
        with open(gitattributes_path, "r", encoding="utf-8") as f:
            return f.read()
    except Exception as e:
        print(f"读取 .gitattributes 文件时出错: {e}")
        return None

def update_gitattributes_entries(gitattributes_path: str, large_files: List[str], gitattributes_content: str, working_dir: str) -> List[str]:
    """
    检查大文件是否已在 .gitattributes 中，如果不在则添加。

    :param gitattributes_path: .gitattributes 文件的路径。
    :param large_files: 大文件路径列表。
    :param gitattributes_content: .gitattributes 文件的当前内容。
    :param working_dir: 工作目录。
    :return: 已添加的新文件列表。
    """
    files_added: List[str] = []
    with open(gitattributes_path, "a", encoding="utf-8") as f:
        for file_path in large_files:
            relative_path: str = os.path.relpath(file_path, working_dir).replace(os.sep, '/')
            
            pattern = re.escape(f'"{relative_path}"')
            if not re.search(pattern, gitattributes_content, re.IGNORECASE):
                new_line = f'"{relative_path}" filter=lfs diff=lfs merge=lfs -text\n'
                f.write(new_line)
                files_added.append(relative_path)
    return files_added

def main() -> None:
    """
    主函数，协调查找大文件和更新 .gitattributes 的过程。
    """
    working_dir: str = os.path.dirname(os.path.abspath(__file__))
    os.chdir(working_dir)

    size_threshold: int = 100 * 1024 * 1024  # 100MB
    gitattributes_path: str = os.path.join(working_dir, ".gitattributes")

    large_files: List[str] = find_large_files(working_dir, size_threshold)

    if not large_files:
        print("未找到大于 100MB 的文件。")
        return

    print("找到以下大文件:")
    for file_path in large_files:
        relative_path = os.path.relpath(file_path, working_dir)
        size_mb = os.path.getsize(file_path) / (1024 * 1024)
        print(f"- {relative_path.replace(os.sep, '/')} ({size_mb:.2f} MB)")

    gitattributes_content: Optional[str] = read_gitattributes(gitattributes_path)
    if gitattributes_content is None:
        return

    files_added: List[str] = update_gitattributes_entries(gitattributes_path, large_files, gitattributes_content, working_dir)

    if files_added:
        print("\n以下文件已添加到 .gitattributes 中并配置为 Git LFS:")
        for file in files_added:
            print(f"- {file}")
    else:
        print("\n所有找到的大文件均已在 .gitattributes 中配置。")

    print("\n脚本执行完毕。")

if __name__ == "__main__":
    main()
