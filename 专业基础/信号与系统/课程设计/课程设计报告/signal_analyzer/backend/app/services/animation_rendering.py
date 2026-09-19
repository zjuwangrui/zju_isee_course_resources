from __future__ import annotations

import math

import numpy as np


def build_frame_schedule(
    source_frame_count: int,
    source_fps: float,
    requested_fps: float = 12.0,
    max_frames: int = 900,
) -> tuple[np.ndarray, float, float]:
    """Build a downsampled render schedule while preserving video duration."""
    if source_frame_count <= 0:
        raise ValueError("source_frame_count must be positive.")
    if source_fps <= 0:
        raise ValueError("source_fps must be positive.")

    requested_fps = max(float(requested_fps), 0.1)
    max_frames = max(int(max_frames), 1)
    duration = max(source_frame_count / source_fps, 1.0 / requested_fps)
    requested_frame_count = max(1, int(math.ceil(duration * requested_fps)))
    render_frame_count = min(source_frame_count, requested_frame_count, max_frames)

    source_indices = np.rint(
        np.linspace(0, source_frame_count - 1, num=render_frame_count)
    ).astype(int)
    render_fps = render_frame_count / duration

    return source_indices, render_fps, duration
