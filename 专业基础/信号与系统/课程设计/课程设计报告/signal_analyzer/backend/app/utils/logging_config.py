import logging
import os

def setup_logging(log_folder):
    """Configures the logging for the application."""
    logging.basicConfig(
        filename=os.path.join(log_folder, 'app.log'),
        level=logging.INFO,
        format='%(asctime)s - %(levelname)s - %(message)s'
    )
