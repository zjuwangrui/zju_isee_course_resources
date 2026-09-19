from flask import Blueprint, request, jsonify, current_app, send_from_directory
from app.services.video_processing import create_spectrum_animation
from app.tasks import run_task_async, get_task_status
import os
import logging

video_bp = Blueprint('video', __name__)

VIDEO_OUTPUT_FOLDER = 'videos'
os.makedirs(VIDEO_OUTPUT_FOLDER, exist_ok=True)

@video_bp.route('/analyze/spectrum_video/<filename>', methods=['POST'])
def analyze_spectrum_video_route(filename):
    """Triggers the spectrum video generation task."""
    input_filepath = os.path.join(current_app.config['UPLOAD_FOLDER'], filename)
    if not os.path.exists(input_filepath):
        logging.error(f"Video analysis requested for non-existent file: {filename}")
        return jsonify({"error": "File not found"}), 404

    try:
        # Combine request args and body for params
        params = request.args.to_dict()
        if request.is_json:
            params.update(request.get_json())

        output_filename = f"spectrum_{os.path.splitext(filename)[0]}.mp4"
        
        task_id = run_task_async(
            create_spectrum_animation,
            input_path=input_filepath,
            output_dir=VIDEO_OUTPUT_FOLDER,
            filename=output_filename,
            params=params
        )
        
        return jsonify({"task_id": task_id}), 202

    except Exception as e:
        logging.error(f"Error starting video analysis for file '{filename}': {e}", exc_info=True)
        return jsonify({"error": str(e)}), 500

@video_bp.route('/tasks/status/<task_id>', methods=['GET'])
def task_status_route(task_id):
    """Checks the status of a background task."""
    task = get_task_status(task_id)
    if task is None:
        return jsonify({"error": "Task not found"}), 404
    
    response = {
        "status": task['status'],
        "progress": task.get('progress', 0.0),
        "message": task.get('message', ''),
    }
    if task['status'] == 'success':
        # Result is the full path, we want a URL
        result_path = task['result']
        video_filename = os.path.basename(result_path)
        result_folder = os.path.abspath(os.path.dirname(result_path))
        animation_folder = os.path.abspath(current_app.config.get('ANIMATION_FOLDER'))
        if result_folder == animation_folder:
            response['video_url'] = f'/animations/{video_filename}'
        else:
            response['video_url'] = f'/videos/{video_filename}'
    elif task['status'] == 'failed':
        response['error'] = task['error']
        
    return jsonify(response)

@video_bp.route('/videos/<video_filename>', methods=['GET'])
def serve_video(video_filename):
    """Serves a generated video file."""
    return send_from_directory(os.path.abspath(VIDEO_OUTPUT_FOLDER), video_filename)
