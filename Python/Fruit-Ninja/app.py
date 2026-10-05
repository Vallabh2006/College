import sys
import os
import pygame

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

from helper.coords import SCREEN_WIDTH, SCREEN_HEIGHT, FPS
from helper.gui import Graphics
from helper.handler import GameLogic

def main():
    pygame.init()
    pygame.display.set_caption("Fruit Ninja - Python Mini Project")
    screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
    clock = pygame.time.Clock()

    graphics = Graphics()
    game = GameLogic(graphics)

    running = True
    while running:
        clock.tick(FPS)
        running = game.handle_input()
        game.update()
        game.draw(screen)

    pygame.quit()
    sys.exit()

if __name__ == "__main__":
    main()
