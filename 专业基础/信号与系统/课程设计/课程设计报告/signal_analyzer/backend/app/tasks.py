from __future__ import annotations

import inspect
import logging
import uuid
from datetime import datetime, timezone
from threading import Lock, Semaphore, Thread
from typing import Any, Callable

# In-memory dictionary to store task status and results
# In a production environment, you would use a more robust solution like Redis or a database.
tasks: dict[str, dict[str, Any]] = {}
_task_lock = Lock()
_task_slots = Semaphore(1)


def _utc_now() -> str:
    return datetime.now(timezone.utc).isoformat()


def _accepts_progress_callback(func: Callable[..., Any]) -> bool:
    try:
        return "progress_callback" in inspect.signature(func).parameters
    except (TypeError, ValueError):
        return False

def run_task_async(func, *args, **kwargs):
    """
    Runs a function in a background thread and tracks its progress.
    
    :param func: The function to run.
    :param args: Arguments for the function.
    :param kwargs: Keyword arguments for the function.
    :return: The ID of the created task.
    """
    task_id = str(uuid.uuid4())
    with _task_lock:
        tasks[task_id] = {
            'status': 'queued',
            'result': None,
            'error': None,
            'progress': 0.0,
            'message': 'Queued',
            'created_at': _utc_now(),
            'started_at': None,
            'completed_at': None,
        }

    last_logged_percent = -10

    def update_task(**updates):
        with _task_lock:
            tasks[task_id].update(updates)

    def update_progress(progress: float, message: str = ""):
        nonlocal last_logged_percent
        try:
            normalized_progress = max(0.0, min(float(progress), 0.99))
        except (TypeError, ValueError):
            normalized_progress = 0.0

        with _task_lock:
            current_progress = float(tasks[task_id].get('progress') or 0.0)
            normalized_progress = max(current_progress, normalized_progress)
            tasks[task_id]['progress'] = normalized_progress
            if message:
                tasks[task_id]['message'] = message

        percent = int(normalized_progress * 100)
        if percent >= last_logged_percent + 10:
            last_logged_percent = (percent // 10) * 10
            logging.info(
                "Task %s (%s) progress %s%%: %s",
                task_id,
                func.__name__,
                percent,
                message,
            )

    def task_wrapper():
        try:
            with _task_slots:
                update_task(status='running', message='Running', started_at=_utc_now())
                call_kwargs = dict(kwargs)
                if _accepts_progress_callback(func) and 'progress_callback' not in call_kwargs:
                    call_kwargs['progress_callback'] = update_progress

                result = func(*args, **call_kwargs)
                update_task(
                    status='success',
                    result=result,
                    progress=1.0,
                    message='Completed',
                    completed_at=_utc_now(),
                )
                logging.info("Task %s for function %s completed.", task_id, func.__name__)
        except Exception as e:
            logging.error(f"Task {task_id} failed: {e}", exc_info=True)
            update_task(
                status='failed',
                error=str(e),
                message='Failed',
                completed_at=_utc_now(),
            )

    thread = Thread(target=task_wrapper)
    thread.start()

    logging.info(f"Queued task {task_id} for function {func.__name__}")
    
    return task_id

def get_task_status(task_id):
    """
    Retrieves the status and result of a task.
    
    :param task_id: The ID of the task to check.
    :return: A dictionary with the task's status and result, or None if not found.
    """
    with _task_lock:
        task = tasks.get(task_id)
        if task is None:
            return None
        return task.copy()
