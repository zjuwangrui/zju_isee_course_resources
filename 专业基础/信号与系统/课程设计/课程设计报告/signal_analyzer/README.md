# Signal Analyzer

这是一个简单的信号分析Web应用，允许用户上传音频文件，并查看其时域波形、频谱图和时频图。用户可以动态调整分析参数并保存生成的图像。

## 特性

-   **文件上传**: 支持上传 `.wav` 和 `.mp3` 格式的音频文件。
-   **信号可视化**:
    -   时域波形图
    -   频谱图
    -   时频图（Spectrogram）
-   **参数可调**:
    -   采样率 (Sample Rate)
    -   FFT窗口大小 (N_FFT)
    -   帧移长度 (Hop Length)
    -   颜色映射 (Colormap)
-   **图像保存**: 可以将每个分析图表保存为PNG格式的图片。
-   **容器化**: 整个应用使用 Docker 和 Docker Compose 进行容器化，方便一键部署和运行。

## 技术栈

-   **前端**: Vue.js + TypeScript + Vite
-   **后端**: Python + Flask
-   **信号处理**: Librosa, NumPy
-   **绘图**: Matplotlib
-   **部署**: Docker, Docker Compose, Nginx

## 项目结构

```
signal_analyzer/
├── backend/
│   ├── uploads/          # 上传的信号文件
│   ├── logs/             # 后端日志
│   ├── app.py            # Flask 后端应用
│   ├── requirements.txt  # Python 依赖
│   └── Dockerfile        # 后端 Dockerfile
├── frontend/
│   ├── src/
│   │   ├── components/   # Vue 组件
│   │   └── ...
│   ├── Dockerfile        # 前端 Dockerfile
│   └── ...
├── docker-compose.yml    # Docker Compose 配置文件
└── README.md             # 项目说明
```

## 如何运行

### 先决条件

-   [Docker](https://www.docker.com/get-started)
-   [Docker Compose](https://docs.docker.com/compose/install/)

### 步骤

1.  **克隆或下载项目**
    将项目文件放置在你的本地机器上。

2.  **构建并运行容器**
    在项目的根目录下，打开终端并执行以下命令：

    ```bash
    docker-compose up --build
    ```
    这个命令会构建前端和后端的Docker镜像，并启动相应的服务。

3.  **访问应用**
    -   **前端界面**: 在你的浏览器中打开 `http://localhost:8080`
    -   **后端API**: 后端服务运行在 `http://localhost:5000`

4.  **停止应用**
    在终端中按下 `Ctrl + C`，然后可以运行以下命令来移除容器：
    ```bash
    docker-compose down
    ```

## API 端点 (后端)

-   `POST /upload`: 上传音频文件。
-   `GET /analyze/<filename>`: 分析指定的音频文件并返回图表的Base64编码。
    -   **查询参数**:
        -   `sr` (int): 采样率
        -   `n_fft` (int): FFT点数
        -   `hop_length` (int): 帧移
        -   `cmap` (string): Matplotlib的颜色图名称
