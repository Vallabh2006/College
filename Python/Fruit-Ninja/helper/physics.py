import random
import math
from helper.coords import screen_width, screen_height, gravity

class Fruit:
    def __init__(self, kind, x, y, vx, vy, size=70):
        self.kind = kind
        self.x = float(x)
        self.y = float(y)
        self.vx = float(vx)
        self.vy = float(vy)
        self.size = size
        self.sliced = False

    def update(self, dt):
        self.vy += gravity * dt
        self.x += self.vx * dt
        self.y += self.vy * dt

    def is_out(self):
        return self.y > screen_height + 50 and self.vy > 0

    def is_clicked(self, pos):
        cx = self.x + self.size / 2
        cy = self.y + self.size / 2
        return math.hypot(pos[0] - cx, pos[1] - cy) <= (self.size / 2 + 5)

    def is_cut_by_line(self, p1, p2):
        cx = self.x + self.size / 2
        cy = self.y + self.size / 2
        radius = self.size / 2 + 5

        x1, y1 = p1
        x2, y2 = p2
        dx = x2 - x1
        dy = y2 - y1
        length_sq = dx * dx + dy * dy

        if length_sq == 0:
            return math.hypot(x1 - cx, y1 - cy) <= radius

        t = max(0.0, min(1.0, ((cx - x1) * dx + (cy - y1) * dy) / length_sq))
        proj_x = x1 + t * dx
        proj_y = y1 + t * dy
        return math.hypot(proj_x - cx, proj_y - cy) <= radius


class HalfPiece:
    def __init__(self, kind, is_left, x, y, vx, vy, size=70):
        self.kind = kind
        self.is_left = is_left
        self.x = float(x)
        self.y = float(y)
        self.vx = float(vx)
        self.vy = float(vy)
        self.size = size

    def update(self, dt):
        self.vy += gravity * dt
        self.x += self.vx * dt
        self.y += self.vy * dt

    def is_out(self):
        return self.y > screen_height + 50


def spawn_item(bomb_chance=0.2):
    is_bomb = (random.random() < bomb_chance)
    kind = "bomb" if is_bomb else random.choice(["apple", "mango", "strawberry"])

    x = random.uniform(100, screen_width - 180)
    y = screen_height + 10

    apex_y = random.uniform(120, 240)
    jump_height = y - apex_y
    vy = -math.sqrt(2 * gravity * jump_height)

    center = screen_width / 2.0
    vx = (center - (x + 35)) * random.uniform(0.7, 1.2) + random.uniform(-20, 20)

    return Fruit(kind, x, y, vx, vy)
