import pygame, os, time
from PIL import Image

file_name = "cat"

image_dir = os.path.join(
    os.path.dirname(__file__),
    f"../Material/{file_name}.gif"
)

background_dir = os.path.join(
    os.path.dirname(__file__),
    "../Material/plank.jpg"
)

gravity = 10 # 9.81
mass = 5.0
pixels_per_meter = 100

speed = 0.0
resize_speed = 350

fps = 100
gif_speed = 30

height = 50
width = 50

screen_height = 1100
screen_width = 300

pygame.init()

screen = pygame.display.set_mode((screen_width, screen_height))
clock = pygame.time.Clock()

gif = Image.open(image_dir)

frames = []

for i in range(gif.n_frames):
    gif.seek(i)

    frame = gif.convert("RGBA")
    frame = frame.resize((width, height))

    frame = pygame.image.fromstring(
        frame.tobytes(),
        frame.size,
        frame.mode
    )

    frames.append(frame)

background = pygame.image.load(background_dir)
background = pygame.transform.scale(
    background,
    (screen_width, screen_height)
)

frame_index = 0
timer = 0

x = (screen_width - width) / 2
y = (screen_height - height) / 2

running = True

print("Frames:", len(frames))
print("Frame size:", frames[0].get_size())
print("Mass:", mass, "kg")
print("Gravity:", gravity, "m/s²")
print("Scale:", pixels_per_meter, "pixels/m")

while running:
    dt = clock.tick(fps) / 1000

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    keys = pygame.key.get_pressed()

    if keys[pygame.K_q]:
        running = False

    if keys[pygame.K_LEFT]:
        x -= 500 * dt

    if keys[pygame.K_RIGHT]:
        x += 500 * dt

    if keys[pygame.K_UP]:
        y -= 500 * dt

    if keys[pygame.K_DOWN]:
        y += 500 * dt

    if keys[pygame.K_EQUALS]:
        width = min(width + resize_speed * dt, 400)
        height = min(height + resize_speed * dt, 400)

    if keys[pygame.K_MINUS]:
        width = max(width - resize_speed * dt, 20)
        height = max(height - resize_speed * dt, 20)

    force = mass * gravity
    acceleration = force / mass

    speed += acceleration * dt

    y += speed * pixels_per_meter * dt

    if y >= screen_height:
        y = -height
        speed = 0

    if x <= -width:
        x = screen_width

    if x >= screen_width:
        x = -width

    timer += clock.get_time()

    if timer >= gif_speed:
        frame_index = (frame_index + 1) % len(frames)
        timer = 0

    screen.blit(background, (0, 0))

    screen.blit(
        pygame.transform.scale(
            frames[frame_index],
            (int(width), int(height))
        ),
        (int(x), int(y))
    )

    pygame.display.flip()

pygame.quit()