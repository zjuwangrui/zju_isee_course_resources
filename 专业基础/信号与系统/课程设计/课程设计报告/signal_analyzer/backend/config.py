import os

class Config:
    """Base configuration."""
    SECRET_KEY = os.environ.get('SECRET_KEY', 'a_default_secret_key')
    UPLOAD_FOLDER = 'uploads'
    LOG_FOLDER = 'logs'
    ANIMATION_FOLDER = 'animations'
    
    # Create directories if they don't exist
    os.makedirs(UPLOAD_FOLDER, exist_ok=True)
    os.makedirs(LOG_FOLDER, exist_ok=True)
    os.makedirs(ANIMATION_FOLDER, exist_ok=True)

class DevelopmentConfig(Config):
    """Development configuration."""
    DEBUG = True

class ProductionConfig(Config):
    """Production configuration."""
    DEBUG = False

# You can set an environment variable FLASK_ENV to 'production' 
# to use the ProductionConfig
config = {
    'development': DevelopmentConfig,
    'production': ProductionConfig,
    'default': DevelopmentConfig
}
