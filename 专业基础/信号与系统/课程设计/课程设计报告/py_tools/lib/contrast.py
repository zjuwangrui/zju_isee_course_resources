import cv2
import numpy as np
from skimage.metrics import structural_similarity as ssim
from typing import Dict, Optional

def compare_images(img_path1: str, img_path2: str) -> Optional[Dict[str, float]]:
    """
    输入两张图像路径，输出：
    - MSE 均方误差（越小越相似）
    - SSIM 结构相似性（1最相似）
    - ORB 特征匹配数量（越多越相似）
    """
    # 读取灰度图
    img1 = cv2.imread(img_path1, cv2.IMREAD_GRAYSCALE)
    img2 = cv2.imread(img_path2, cv2.IMREAD_GRAYSCALE)
    if img1 is None or img2 is None:
        print("⚠️ 无法读取图像，请检查路径")
        return None
    if img1.shape != img2.shape:
        print("⚠️ 图像尺寸不同，调整为同样大小")
        img2 = cv2.resize(img2, (img1.shape[1], img1.shape[0]))

    # 1️⃣ MSE
    mse_val: float = np.mean((img1 - img2) ** 2)

    # 2️⃣ SSIM
    ssim_val: float
    ssim_val, _ = ssim(img1, img2, full=True)

    # 3️⃣ ORB 特征匹配
    orb = cv2.ORB_create()
    _, des1 = orb.detectAndCompute(img1, None)
    _, des2 = orb.detectAndCompute(img2, None)

    bf = cv2.BFMatcher(cv2.NORM_HAMMING, crossCheck=True)
    matches = bf.match(des1, des2)
    matches = sorted(matches, key=lambda x: x.distance)
    num_matches: int = len(matches)

    return {"MSE": float(mse_val), "SSIM": float(ssim_val), "ORB_matches": num_matches}

# 使用示例
img1 = r"py_tools\output\signal1.png"
img2 = r"py_tools\output\signal2.png"
result = compare_images(img1, img2)
print(result)