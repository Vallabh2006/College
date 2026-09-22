import pygame, os
from PIL import Image

file_name = input("\nFile name: ")

image_dir = os.path.join(
    os.path.dirname(__file__),
    f"../Material/{file_name}.gif"
)

background_dir = os.path.join(
    os.path.dirname(__file__),
    "../Material/sky.jpg"
)

fps = 100
gif_speed = int(input("Gif Speed: "))

height = 50
width = 50

screen_height = 800
screen_width = 1000

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

x = 100
y = 100

speed = 300
resize_speed = 350

running = True

print("Frames:", len(frames))
print("Frame size:", frames[0].get_size())

while running:
    dt = clock.tick(fps) / 1000

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    keys = pygame.key.get_pressed()

    if keys[pygame.K_q]:
        print("Quit")
        running = False

    if keys[pygame.K_LEFT]:
        if x <= -width:
            x = screen_width
        else:
            x -= speed * dt

    if keys[pygame.K_RIGHT]:
        if x >= screen_width:
            x = -width
        else:
            x += speed * dt

    if keys[pygame.K_UP]:
        if y <= -height:
            y = screen_height
        else:
            y -= speed * dt

    if keys[pygame.K_DOWN]:
        if y >= screen_height:
            y = -height
        else:
            y += speed * dt

    if keys[pygame.K_EQUALS]:
        width = min(width + resize_speed * dt, 400)
        height = min(height + resize_speed * dt, 400)

    if keys[pygame.K_MINUS]:
        width = max(width - resize_speed * dt, 20)
        height = max(height - resize_speed * dt, 20)

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