FROM node:20-bookworm AS frontend-build

WORKDIR /build/frontend
COPY frontend/package*.json ./
RUN npm ci
COPY frontend/ ./
ENV VITE_API_BASE_URL=
RUN npm run build


FROM python:3.9-slim-bookworm AS runtime

ENV FLASK_ENV=production \
    MPLBACKEND=Agg \
    PYTHONUNBUFFERED=1 \
    FRONTEND_DIST_DIR=/app/frontend_dist

WORKDIR /app/backend

RUN apt-get update \
    && apt-get install -y --no-install-recommends ffmpeg \
    && rm -rf /var/lib/apt/lists/*

COPY backend/requirements.txt /app/backend/requirements.txt
RUN pip install --no-cache-dir -r /app/backend/requirements.txt

COPY backend/ /app/backend/
COPY --from=frontend-build /build/frontend/dist/ /app/frontend_dist/

RUN mkdir -p /app/backend/uploads /app/backend/logs /app/backend/animations /app/backend/videos

EXPOSE 7860

CMD ["gunicorn", "--bind", "0.0.0.0:7860", "--workers", "1", "--threads", "2", "--timeout", "3600", "run:app"]
