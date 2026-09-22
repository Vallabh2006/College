import os

image_dir = os.path.join(
    os.path.dirname(__file__),
    "../Material/cat.gif"
)
print(image_dir)
print(os.path.exists(image_dir))
