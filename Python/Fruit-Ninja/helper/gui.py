import pygame
import os
from helper.coords import screen_width, screen_height, get_paths

class Graphics:
    def __init__(self, size=70):
        self.size = size
        self.paths = get_paths()
        self.images = {}
        self.halves = {}
        self.background = None

        try:
            self.font_large = pygame.font.SysFont("Arial", 42, bold=True)
            self.font_medium = pygame.font.SysFont("Arial", 26, bold=True)
        except Exception:
            self.font_large = pygame.font.Font(None, 48)
            self.font_medium = pygame.font.Font(None, 30)

        self._load_textures()

    def _load_textures(self):
        bg_path = self.paths.get("background")
        if bg_path and os.path.exists(bg_path):
            try:
                bg = pygame.image.load(bg_path).convert()
                self.background = pygame.transform.scale(bg, (screen_width, screen_height))
            except Exception:
                self.background = self._make_fallback_bg()
        else:
            self.background = self._make_fallback_bg()

        for name in ["apple", "mango", "strawberry", "bomb"]:
            path = self.paths.get(name)
            if path and os.path.exists(path):
                try:
                    img = pygame.image.load(path).convert_alpha()
                    scaled = pygame.transform.scale(img, (self.size, self.size))
                    self.images[name] = scaled
                    self._create_halves(name, scaled)
                except Exception:
                    self._make_fallback_fruit(name)
            else:
                self._make_fallback_fruit(name)

    def _make_fallback_bg(self):
        surf = pygame.Surface((screen_width, screen_height))
        surf.fill((60, 40, 25))
        return surf

    def _make_fallback_fruit(self, name):
        surf = pygame.Surface((self.size, self.size), pygame.SRCALPHA)
        col = (220, 30, 30) if name == "apple" else (240, 160, 20) if name == "mango" else (230, 20, 80) if name == "strawberry" else (30, 30, 30)
        pygame.draw.circle(surf, col, (self.size // 2, self.size // 2), self.size // 2 - 2)
        self.images[name] = surf
        self._create_halves(name, surf)

    def _create_halves(self, name, img):
        w, h = img.get_size()
        half_w = w // 2

        left_surf = pygame.Surface((half_w, h), pygame.SRCALPHA)
        left_surf.blit(img, (0, 0), (0, 0, half_w, h))

        right_surf = pygame.Surface((w - half_w, h), pygame.SRCALPHA)
        right_surf.blit(img, (0, 0), (half_w, 0, w - half_w, h))

        self.halves[name] = (left_surf, right_surf)

    def draw_game(self, screen, fruits, halves, score, lives, blade_trail, is_mouse_down, game_over):
        screen.blit(self.background, (0, 0))

        for h in halves:
            pair = self.halves.get(h.kind)
            if pair:
                tex = pair[0] if h.is_left else pair[1]
                screen.blit(tex, (int(h.x), int(h.y)))

        for f in fruits:
            if not f.sliced:
                tex = self.images.get(f.kind)
                if tex:
                    screen.blit(tex, (int(f.x), int(f.y)))

        if is_mouse_down and len(blade_trail) > 1:
            for i in range(len(blade_trail) - 1):
                pygame.draw.line(screen, (255, 255, 255), blade_trail[i], blade_trail[i + 1], 3)

        score_text = self.font_medium.render(f"Score: {score}", True, (255, 255, 255))
        screen.blit(score_text, (20, 20))

        lives_str = "Lives: " + "X " * max(0, lives)
        lives_text = self.font_medium.render(lives_str.strip(), True, (255, 80, 80))
        screen.blit(lives_text, (screen_width - lives_text.get_width() - 20, 20))

        if game_over:
            overlay = pygame.Surface((screen_width, screen_height), pygame.SRCALPHA)
            overlay.fill((0, 0, 0, 160))
            screen.blit(overlay, (0, 0))

            go_txt = self.font_large.render("GAME OVER", True, (255, 50, 50))
            go_rect = go_txt.get_rect(center=(screen_width // 2, screen_height // 2 - 30))
            screen.blit(go_txt, go_rect)

            res_txt = self.font_medium.render("Click or Press SPACE to Restart", True, (255, 255, 255))
            res_rect = res_txt.get_rect(center=(screen_width // 2, screen_height // 2 + 30))
            screen.blit(res_txt, res_rect)
