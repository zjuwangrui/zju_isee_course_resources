from app import create_app
import os

# Get config name from environment or use default
config_name = os.getenv('FLASK_ENV', 'default')
# app = create_app(config[config_name])
app = create_app()


if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)
