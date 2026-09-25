import os

screen_width = 800
screen_height = 600
fps = 60
gravity = 650

def get_paths():
    current_dir = os.path.dirname(os.path.abspath(__file__))
    candidates = [
        os.path.join(current_dir, "../Material"),
        os.path.join(current_dir, "../../Material"),
        os.path.join(os.getcwd(), "Material"),
        os.path.join(os.getcwd(), "../Material"),
    ]
    mat_dir = os.path.abspath(os.path.join(current_dir, "../Material"))
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
