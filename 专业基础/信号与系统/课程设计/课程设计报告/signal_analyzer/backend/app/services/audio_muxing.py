from __future__ import annotations

import logging
import os
import subprocess


def mux_audio_track(
    video_path: str,
    audio_path: str,
    output_path: str,
    audio_bitrate: str = "192k",
) -> str:
    """Mux an existing video stream with the source audio as browser-friendly AAC."""
    command = [
        "ffmpeg",
        "-y",
        "-i",
        video_path,
        "-i",
        audio_path,
        "-map",
        "0:v:0",
        "-map",
        "1:a:0",
        "-c:v",
        "copy",
        "-c:a",
        "aac",
        "-b:a",
        audio_bitrate,
        "-shortest",
        "-movflags",
        "+faststart",
        output_path,
    ]

    logging.info(
        "Muxing audio track into video: video=%s audio=%s output=%s",
        video_path,
        audio_path,
        output_path,
    )
    try:
        subprocess.run(command, check=True, capture_output=True, text=True)
    except FileNotFoundError as error:
        raise RuntimeError("ffmpeg is required to mux audio into animation videos.") from error
    except subprocess.CalledProcessError as error:
        stderr = (error.stderr or "").strip()
        raise RuntimeError(f"Failed to mux audio into video: {stderr}") from error

    if not os.path.exists(output_path):
        raise RuntimeError("Audio muxing completed without producing an output file.")

    logging.info("Muxed animation video saved to: %s", output_path)
    return output_path
