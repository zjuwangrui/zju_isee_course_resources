from flask import Flask, send_from_directory
from flask_cors import CORS
from config import Config
from .utils.logging_config import setup_logging
import os

os.environ.setdefault("MPLBACKEND", "Agg")

def create_app():
    """Create and configure an instance of the Flask application."""
    frontend_dist_dir = os.environ.get("FRONTEND_DIST_DIR")
    static_folder = frontend_dist_dir if frontend_dist_dir and os.path.isdir(frontend_dist_dir) else None
    app = Flask(__name__, static_folder=None)
    CORS(app)
    
    # Load configuration
    app.config.from_object(Config)
    
    # Ensure instance folder exists
    try:
        os.makedirs(app.instance_path)
    except OSError:
        pass

    # Setup logging
    setup_logging(app.config['LOG_FOLDER'])

    # Register blueprints
    from .api.signal import signal_bp
    from .api.video import video_bp
    app.register_blueprint(signal_bp)
    app.register_blueprint(video_bp)

    if static_folder:
        @app.route("/", defaults={"path": ""})
        @app.route("/<path:path>")
        def serve_frontend(path: str):
            requested_path = os.path.join(static_folder, path)
            if path and os.path.isfile(requested_path):
                return send_from_directory(static_folder, path)
            return send_from_directory(static_folder, "index.html")

    return app
