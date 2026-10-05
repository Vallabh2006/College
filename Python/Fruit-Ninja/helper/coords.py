import os

SCREEN_WIDTH = 800
SCREEN_HEIGHT = 600
FPS = 60
GRAVITY = 0.22
FRUIT_SIZE = 70

screen_width = SCREEN_WIDTH
screen_height = SCREEN_HEIGHT
fps = FPS
gravity = GRAVITY

def get_asset_paths():
    base_dir = os.path.dirname(os.path.abspath(__file__))
    candidates = [
        os.path.join(base_dir, "../Material"),
        os.path.join(base_dir, "../../Material"),
        os.path.join(os.getcwd(), "Material"),
        os.path.join(os.getcwd(), "../Material"),
    ]
    mat_dir = os.path.abspath(os.path.join(base_dir, "../Material"))
    for c in candidates:
        if os.path.isdir(c):
            mat_dir = os.path.abspath(c)
            break

    return {
        "apple": os.path.join(mat_dir, "apple.png"),
        "mango": os.path.join(mat_dir, "mango.png"),
        "strawberry": os.path.join(mat_dir, "strawberry.png"),
        "bomb": os.path.join(mat_dir, "bomb.png"),
        "background": os.path.join(mat_dir, "plank.jpg")
    }

get_paths = get_asset_paths
