import sys
import os
import pygame

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

from helper.coords import screen_width, screen_height, fps
from helper.gui import Graphics
from helper.handler import GameLogic

def main():
    pygame.init()
    pygame.display.set_caption("Fruit Ninja")

    screen = pygame.display.set_mode((screen_width, screen_height))
    clock = pygame.time.Clock()

    graphics = Graphics()
    game = GameLogic(graphics)

    running = True
    while running:
        dt = clock.tick(fps) / 1000.0

        running = game.handle_input()
        game.update(dt)
        game.draw(screen)

    pygame.quit()
    sys.exit()

if __name__ == "__main__":
    main()
