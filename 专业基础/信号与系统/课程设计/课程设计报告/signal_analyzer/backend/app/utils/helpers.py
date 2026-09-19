import io
import base64
import matplotlib

matplotlib.use("Agg")
import matplotlib.pyplot as plt

def fig_to_base64(fig):
    """Convert a matplotlib figure to a base64 encoded string."""
    buf = io.BytesIO()
    fig.savefig(buf, format='png', bbox_inches='tight')
    plt.close(fig)
    return base64.b64encode(buf.getvalue()).decode('utf-8')
