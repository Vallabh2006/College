import random
import math
from helper.coords import SCREEN_WIDTH, SCREEN_HEIGHT, GRAVITY, FRUIT_SIZE

class Fruit:
    def __init__(self, kind, x, y, vx, vy, size=FRUIT_SIZE):
        self.kind = kind
        self.x = float(x)
        self.y = float(y)
        self.vx = float(vx)
        self.vy = float(vy)
        self.size = size
        self.sliced = False

    def update(self):
        self.vy += GRAVITY
        self.x += self.vx
        self.y += self.vy

    def is_out(self):
        return self.y > SCREEN_HEIGHT + 20 and self.vy > 0

    def is_hit(self, mouse_pos):
        center_x = self.x + self.size / 2
        center_y = self.y + self.size / 2
        radius = self.size / 2
        distance = math.hypot(mouse_pos[0] - center_x, mouse_pos[1] - center_y)
        return distance <= radius


class HalfPiece:
    def __init__(self, kind, is_left, x, y, vx, vy, size=FRUIT_SIZE):
        self.kind = kind
        self.is_left = is_left
        self.x = float(x)
        self.y = float(y)
        self.vx = float(vx)
        self.vy = float(vy)
        self.size = size

    def update(self):
        self.vy += GRAVITY
        self.x += self.vx
        self.y += self.vy

    def is_out(self):
        return self.y > SCREEN_HEIGHT + 20


def spawn_item(bomb_chance=0.2):
    if random.random() < bomb_chance:
        kind = "bomb"
    else:
        kind = random.choice(["apple", "mango", "strawberry"])

    x = random.randint(120, SCREEN_WIDTH - 180)
    y = SCREEN_HEIGHT
    vy = random.uniform(-15.0, -13.5)

    if x < SCREEN_WIDTH / 2:
        vx = random.uniform(0.8, 2.2)
    else:
        vx = random.uniform(-2.2, -0.8)

    return Fruit(kind, x, y, vx, vy)
