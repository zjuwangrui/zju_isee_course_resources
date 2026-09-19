from __future__ import annotations

import logging
import os
from pathlib import Path
from uuid import uuid4

from flask import Blueprint, current_app, jsonify, request, send_from_directory

from app.services.signal_processing import AnalysisParams, analyze_signal_data
from app.services.stft_animation import (
    AnimationParams,
    create_spectrogram_animation,
)
from app.tasks import run_task_async

signal_bp = Blueprint("signal", __name__)


def get_request_param(name: str):
    """Read a parameter from query string first, then JSON body."""
    if name in request.args:
        return request.args.get(name)
    if request.is_json:
        data = request.get_json(silent=True) or {}
        return data.get(name)
    return None


def get_animation_folder() -> str:
    """Return the concrete folder used for generated STFT animations."""
    return os.path.abspath(str(current_app.config["ANIMATION_FOLDER"]))


def get_int_query_param(name: str, default: int) -> int:
    """Read an integer query parameter with a concrete typed fallback."""
    value = get_request_param(name)
    if value in (None, ""):
        return default
    return int(value)


def get_str_query_param(name: str, default: str) -> str:
    """Read a string query parameter with a concrete typed fallback."""
    value = get_request_param(name)
    if value in (None, ""):
        return default
    return str(value)


def get_float_query_param(name: str, default: float) -> float:
    """Read a float query parameter with a concrete typed fallback."""
    value = get_request_param(name)
    if value in (None, ""):
        return default
    return float(value)


def build_animation_params() -> AnimationParams:
    """Read animation parameters from the query string."""
    n_fft = get_int_query_param("n_fft", 2048)
    return {
        "sr": get_int_query_param("sr", 22050),
        "n_fft": n_fft,
        "hop_length": get_int_query_param("hop_length", 512),
        "win_length": get_int_query_param("win_length", n_fft),
        "window": get_str_query_param("window", "hann"),
        "cmap": get_str_query_param("cmap", "viridis"),
        "frame_nums": get_int_query_param("frame_nums", 10),
        "render_fps": get_float_query_param("render_fps", 12.0),
        "max_video_frames": get_int_query_param("max_video_frames", 900),
    }


@signal_bp.route("/upload", methods=["POST"])
def upload_file():
    """Handle file uploads."""
    if "file" not in request.files:
        logging.warning("Upload attempt with no file part.")
        return jsonify({"error": "No file part"}), 400

    file = request.files["file"]
    filename = file.filename
    if not filename:
        logging.warning("Upload attempt with no selected file.")
        return jsonify({"error": "No selected file"}), 400

    upload_folder = str(current_app.config["UPLOAD_FOLDER"])
    filepath = os.path.join(upload_folder, filename)
    file.save(filepath)
    logging.info("File '%s' uploaded successfully.", filename)
    return jsonify({"message": "File uploaded successfully", "filename": filename})


@signal_bp.route("/analyze/<filename>", methods=["GET"])
def analyze_signal_route(filename: str):
    """Analyze the signal and return plots."""
    upload_folder = str(current_app.config["UPLOAD_FOLDER"])
    filepath = os.path.join(upload_folder, filename)
    if not os.path.exists(filepath):
        logging.error(f"Analysis requested for non-existent file: {filename}")
        return jsonify({"error": "File not found"}), 404

    try:
        # Get parameters from request or use defaults
        stft_n_fft = get_int_query_param("stft_n_fft", get_int_query_param("n_fft", 2048))
        params: AnalysisParams = {
            "sr": get_int_query_param("sr", 22050),
            "spectrum_n_fft": get_int_query_param("spectrum_n_fft", get_int_query_param("n_fft", 2048)),
            "stft_n_fft": stft_n_fft,
            "hop_length": get_int_query_param("hop_length", 512),
            "win_length": get_int_query_param("win_length", stft_n_fft),
            "window": get_str_query_param("window", "hann"),
            "cmap": get_str_query_param("cmap", "viridis"),
        }
        if params["sr"] <= 0:
            return jsonify({"error": "sr must be positive"}), 400
        if params["spectrum_n_fft"] <= 0:
            return jsonify({"error": "spectrum_n_fft must be positive"}), 400
        if params["stft_n_fft"] <= 0:
            return jsonify({"error": "stft_n_fft must be positive"}), 400
        if params["hop_length"] <= 0:
            return jsonify({"error": "hop_length must be positive"}), 400
        if params["win_length"] <= 0:
            return jsonify({"error": "win_length must be positive"}), 400

        logging.info("Analyzing '%s' with params: %s", filename, params)

        plots = analyze_signal_data(filepath, params)

        logging.info("Successfully generated plots for '%s'.", filename)
        return jsonify(plots)

    except Exception as error:
        logging.error("Error analyzing file '%s': %s", filename, error, exc_info=True)
        return jsonify({"error": str(error)}), 500


@signal_bp.route("/animate/<filename>", methods=["POST"])
@signal_bp.route("/analyze/spectrogram_video/<filename>", methods=["POST"])
def animate_signal_route(filename: str):
    """Generate an STFT animation for an uploaded audio file."""
    upload_folder = str(current_app.config["UPLOAD_FOLDER"])
    filepath = os.path.join(upload_folder, filename)
    if not os.path.exists(filepath):
        logging.error("Animation requested for non-existent file: %s", filename)
        return jsonify({"error": "File not found"}), 404

    try:
        params = build_animation_params()
        if params["n_fft"] <= 0:
            return jsonify({"error": "n_fft must be positive"}), 400
        if params["hop_length"] <= 0:
            return jsonify({"error": "hop_length must be positive"}), 400
        if params["win_length"] <= 0:
            return jsonify({"error": "win_length must be positive"}), 400
        if params["n_fft"] < params["win_length"]:
            return jsonify({"error": "n_fft must not be smaller than win_length"}), 400
        if params["frame_nums"] <= 0:
            return jsonify({"error": "frame_nums must be positive"}), 400
        if params["render_fps"] <= 0:
            return jsonify({"error": "render_fps must be positive"}), 400
        if params["max_video_frames"] <= 0:
            return jsonify({"error": "max_video_frames must be positive"}), 400

        animation_folder = get_animation_folder()
        source_stem = Path(filename).stem
        animation_filename = f"{source_stem}_{uuid4().hex}_stft.mp4"
        task_id = run_task_async(
            create_spectrogram_animation,
            input_path=filepath,
            output_dir=animation_folder,
            filename=animation_filename,
            sr=params["sr"],
            n_fft=params["n_fft"],
            hop_length=params["hop_length"],
            win_length=params["win_length"],
            window=params["window"],
            cmap=params["cmap"],
            frame_nums=params["frame_nums"],
            render_fps=params["render_fps"],
            max_video_frames=params["max_video_frames"],
        )

        logging.info("Successfully queued animation task for '%s': %s", filename, task_id)
        return jsonify({"task_id": task_id}), 202

    except Exception as error:
        logging.error("Error processing animation for %s: %s", filename, error, exc_info=True)
        return jsonify({"error": "Failed to start animation task"}), 500


@signal_bp.route("/animations/<filename>", methods=["GET"])
def get_animation_file(filename: str):
    """Serve generated STFT animation files."""
    animation_folder = get_animation_folder()
    return send_from_directory(animation_folder, filename, mimetype="video/mp4")


@signal_bp.route("/animations/<filename>/download", methods=["GET"])
def download_animation_file(filename: str):
    """Download a generated STFT animation file."""
    animation_folder = get_animation_folder()
    return send_from_directory(
        animation_folder,
        filename,
        mimetype="video/mp4",
        as_attachment=True,
        download_name=filename,
    )
