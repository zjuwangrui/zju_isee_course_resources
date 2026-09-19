import logging
import os
from typing import Callable, Union

import librosa
import matplotlib

matplotlib.use("Agg")
import matplotlib.animation as animation
import matplotlib.pyplot as plt
import numpy as np
from matplotlib.collections import LineCollection

from .audio_muxing import mux_audio_track
from .animation_rendering import build_frame_schedule

def _get_int_param(params: dict, name: str, default: int) -> int:
    value = params.get(name, default)
    if value in (None, ""):
        return default
    return int(value)


def _get_float_param(params: dict, name: str, default: float) -> float:
    value = params.get(name, default)
    if value in (None, ""):
        return default
    return float(value)


def _build_rainbow_rain_segments(
    rng: np.random.Generator,
    min_frequency: float,
    max_frequency: float,
    min_db: float,
    max_db: float,
    config: dict
) -> tuple[np.ndarray, np.ndarray, np.ndarray]:
    """Generate one frame of decorative rainbow rain segments."""
    drop_count = _get_int_param(config, 'rain_drop_count', 120)
    rain_length_min = _get_float_param(config, 'rain_length_min', 4.0)
    rain_length_max = _get_float_param(config, 'rain_length_max', 12.0)
    rain_width_min = _get_float_param(config, 'rain_width_min', 1.5)
    rain_width_max = _get_float_param(config, 'rain_width_max', 3.5)
    rain_cmap = config.get('rain_cmap', 'hsv')

    log_x = rng.uniform(np.log10(min_frequency), np.log10(max_frequency), drop_count)
    x_positions = np.power(10.0, log_x)
    y_starts = rng.uniform(min_db, max_db, drop_count)
    lengths = rng.uniform(rain_length_min, rain_length_max, drop_count)
    y_ends = np.maximum(y_starts - lengths, min_db)
    colors = plt.get_cmap(rain_cmap)(rng.random(drop_count))
    widths = rng.uniform(rain_width_min, rain_width_max, drop_count)
    segments = np.stack(
        (
            np.column_stack((x_positions, y_starts)),
            np.column_stack((x_positions, y_ends)),
        ),
        axis=1,
    )
    return segments, colors, widths


def create_spectrum_animation(
    input_path: str,
    output_dir: str,
    filename: str,
    params: dict,
    progress_callback: Union[Callable[[float, str], None], None] = None,
) -> str:
    """Render a frame-wise FFT spectrum animation with the source audio track."""
    os.makedirs(output_dir, exist_ok=True)

    sr = _get_int_param(params, 'sr', 22050)
    n_fft = _get_int_param(params, 'n_fft', 2048)
    hop_length = _get_int_param(params, 'hop_length', 512)
    cmap = params.get('cmap', 'magma')
    fig_size = params.get('fig_size', (12, 7))
    rain_drop_count = _get_int_param(params, 'rain_drop_count', 120)
    rain_length_min = _get_float_param(params, 'rain_length_min', 4.0)
    rain_length_max = _get_float_param(params, 'rain_length_max', 12.0)
    rain_width_min = _get_float_param(params, 'rain_width_min', 1.5)
    rain_width_max = _get_float_param(params, 'rain_width_max', 3.5)
    rain_alpha = _get_float_param(params, 'rain_alpha', 0.8)
    render_fps = _get_float_param(params, 'render_fps', 12.0)
    max_video_frames = _get_int_param(params, 'max_video_frames', 900)

    if n_fft <= 0:
        raise ValueError("n_fft must be positive.")
    if hop_length <= 0:
        raise ValueError("hop_length must be positive.")
    if rain_drop_count < 0:
        raise ValueError("rain_drop_count must not be negative.")
    if rain_length_min < 0 or rain_length_max < 0:
        raise ValueError("rain length values must not be negative.")
    if rain_length_min > rain_length_max:
        raise ValueError("rain_length_min must not exceed rain_length_max.")
    if rain_width_min < 0 or rain_width_max < 0:
        raise ValueError("rain width values must not be negative.")
    if rain_width_min > rain_width_max:
        raise ValueError("rain_width_min must not exceed rain_width_max.")
    if not 0 <= rain_alpha <= 1:
        raise ValueError("rain_alpha must be between 0 and 1.")

    if progress_callback:
        progress_callback(0.02, "Loading audio")
    y, sr = librosa.load(input_path, sr=sr)
    logging.info(f"Loaded audio file '{input_path}' with sample rate {sr} and {len(y)} samples.")

    if len(y) < n_fft:
        raise ValueError("n_fft must not exceed the audio length.")

    num_frames = (len(y) - n_fft) // hop_length + 1
    positive_bin_count = n_fft // 2 + 1
    positive_frequencies = np.arange(positive_bin_count, dtype=np.float64) * sr / n_fft
    spectrum_magnitude = np.zeros((positive_bin_count, num_frames), dtype=np.float64)
    window = np.ones(n_fft, dtype=np.float64)

    if progress_callback:
        progress_callback(0.08, "Computing frame-wise FFT")
    for frame_index in range(num_frames):
        start_index = frame_index * hop_length
        end_index = start_index + n_fft
        frame = y[start_index:end_index] * window
        fft_result = np.fft.fft(frame, n=n_fft)
        spectrum_magnitude[:, frame_index] = np.abs(fft_result[:positive_bin_count])

    D = librosa.amplitude_to_db(spectrum_magnitude, ref=np.max)
    max_frequency = float(positive_frequencies[-1])
    min_frequency = float(positive_frequencies[1]) if len(positive_frequencies) > 1 else 0.0
    min_db = float(np.min(D))
    logging.info(
        "Computed frame-wise FFT with "
        f"n_fft={n_fft}, hop_length={hop_length}. Result shape: {spectrum_magnitude.shape}"
    )
    logging.info(f"Frequency range: {min_frequency} Hz to {max_frequency} Hz")

    fig, ax = plt.subplots(figsize=fig_size)
    fig.patch.set_facecolor("black")
    ax.set_facecolor("black")
    rng = np.random.default_rng()

    line_color = plt.get_cmap(cmap)(0.85)
    line, = ax.plot(
        positive_frequencies[1:],
        D[1:, 0],
        color=line_color,
        linewidth=1.5,
        zorder=2,
    )
    rain_lines = LineCollection([], alpha=rain_alpha, zorder=1, capstyle="round")
    ax.add_collection(rain_lines)
    time_text = ax.text(
        0.98,
        0.95,
        "0.00 s",
        color="white",
        fontsize=12,
        ha="right",
        va="top",
        transform=ax.transAxes,
    )

    ax.set_xlim(min_frequency, max_frequency)
    ax.set_ylim(min_db, 0)
    ax.set_xscale("log")
    fig.subplots_adjust(left=0, right=1, bottom=0, top=1)
    ax.set_axis_off()

    def update(frame: int):
        current_time = frame * hop_length / sr
        line.set_ydata(D[1:, frame])
        segments, colors, widths = _build_rainbow_rain_segments(
            rng,
            min_frequency,
            max_frequency,
            min_db,
            0.0,
            params
        )
        rain_lines.set_segments(segments)
        rain_lines.set_colors(colors)
        rain_lines.set_linewidths(widths)
        time_text.set_text(f"{current_time:.2f} s")
        return (line, rain_lines, time_text)

    source_fps = sr / hop_length
    frame_schedule, output_fps, duration = build_frame_schedule(
        source_frame_count=num_frames,
        source_fps=source_fps,
        requested_fps=render_fps,
        max_frames=max_video_frames,
    )
    logging.info(
        "Rendering FFT spectrum animation with %s/%s frames at %.2f fps (duration %.2fs).",
        len(frame_schedule),
        num_frames,
        output_fps,
        duration,
    )
    if progress_callback:
        progress_callback(0.15, "Rendering FFT video")

    ani = animation.FuncAnimation(
        fig,
        update,
        frames=frame_schedule,
        blit=True,
        interval=1000 / output_fps,
    )

    output_path = os.path.join(output_dir, filename)
    silent_output_path = os.path.join(output_dir, f".{os.path.splitext(filename)[0]}_silent.mp4")
    writer = animation.FFMpegWriter(
        fps=max(1, int(round(output_fps))),
        codec="h264",
        extra_args=["-pix_fmt", "yuv420p", "-preset", "veryfast", "-crf", "23"],
    )

    def save_progress(frame_number: int, total_frames: int) -> None:
        if progress_callback and total_frames:
            progress_callback(
                0.15 + 0.75 * ((frame_number + 1) / total_frames),
                f"Rendering FFT video {frame_number + 1}/{total_frames}",
            )

    try:
        ani.save(silent_output_path, writer=writer, progress_callback=save_progress)
    finally:
        plt.close(fig)

    logging.info("Silent FFT spectrum animation saved to: %s", silent_output_path)
    if progress_callback:
        progress_callback(0.92, "Muxing source audio")

    try:
        mux_audio_track(silent_output_path, input_path, output_path)
    finally:
        try:
            os.remove(silent_output_path)
        except FileNotFoundError:
            pass

    if progress_callback:
        progress_callback(0.98, "Finalizing FFT video")
    logging.info("FFT spectrum animation with audio saved to: %s", output_path)
    return output_path
