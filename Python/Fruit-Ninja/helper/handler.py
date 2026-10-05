import random
import pygame
from helper.physics import HalfPiece, spawn_item

class GameLogic:
    def __init__(self, graphics):
        self.graphics = graphics
        self.score = 0
        self.lives = 3
        self.game_over = False

        self.fruits = []
        self.halves = []

        self.blade_trail = []
        self.is_mouse_down = False
        self.last_pos = None

        self.spawn_timer = 0
        self.spawn_interval = 90

    def reset(self):
        self.score = 0
        self.lives = 3
        self.game_over = False
        self.fruits.clear()
        self.halves.clear()
        self.blade_trail.clear()
        self.spawn_timer = 0

    def handle_input(self):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                return False

            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_q:
                    return False
                elif event.key == pygame.K_SPACE or event.key == pygame.K_r:
                    if self.game_over:
                        self.reset()

            elif event.type == pygame.MOUSEBUTTONDOWN:
                if event.button == 1:
                    self.is_mouse_down = True
                    pos = event.pos
                    self.blade_trail = [pos]
                    self.last_pos = pos

                    if self.game_over:
                        self.reset()
                    else:
                        self._check_slice(pos)

            elif event.type == pygame.MOUSEBUTTONUP:
                if event.button == 1:
                    self.is_mouse_down = False
                    self.blade_trail.clear()
                    self.last_pos = None

            elif event.type == pygame.MOUSEMOTION:
                pos = event.pos
                if self.is_mouse_down and not self.game_over:
                    self.blade_trail.append(pos)
                    if len(self.blade_trail) > 8:
                        self.blade_trail.pop(0)

                    if self.last_pos:
                        mid = ((self.last_pos[0] + pos[0]) / 2, (self.last_pos[1] + pos[1]) / 2)
                        self._check_slice(mid)

                    self._check_slice(pos)
                    self.last_pos = pos

        return True

    def _check_slice(self, pos):
        for f in self.fruits:
            if not f.sliced and f.is_hit(pos):
                self._slice(f)

    def _slice(self, fruit):
        fruit.sliced = True

        if fruit.kind == "bomb":
            self.lives -= 1
            if self.lives <= 0:
                self.game_over = True
        else:
            self.score += 1
            self.halves.append(HalfPiece(fruit.kind, True, fruit.x - 5, fruit.y, fruit.vx - 2.0, fruit.vy - 1.0, fruit.size))
            self.halves.append(HalfPiece(fruit.kind, False, fruit.x + 5, fruit.y, fruit.vx + 2.0, fruit.vy - 1.0, fruit.size))

    def update(self):
        if self.game_over:
            return

        self.spawn_timer += 1
        if self.spawn_timer >= self.spawn_interval:
            self.spawn_timer = 0
            count = random.choice([1, 2])
            bomb_chance = min(0.3, 0.15 + self.score * 0.01)
            for _ in range(count):
                self.fruits.append(spawn_item(bomb_chance))

        for f in self.fruits:
            if not f.sliced:
                f.update()
                if f.is_out():
                    if f.kind != "bomb":
                        self.lives -= 1
                        if self.lives <= 0:
                            self.game_over = True

        self.fruits = [f for f in self.fruits if not f.sliced and not f.is_out()]

        for h in self.halves:
            h.update()
        self.halves = [h for h in self.halves if not h.is_out()]

    def draw(self, screen):
        self.graphics.draw_game(
            screen,
            self.fruits,
            self.halves,
            self.score,
            self.lives,
            self.blade_trail,
            self.is_mouse_down,
            self.game_over
        )
        pygame.display.flip()
