# visualizer.py

import pygame
import sys

class Visualizer:
    def __init__(self, universe, pixel_size):
        self.universe = universe
        self.pixel_size = pixel_size
        self.screen_width = 800
        self.screen_height = 600
        self.screen = pygame.display.set_mode((self.screen_width, self.screen_height))
        self.rows = (len(universe) + self.screen_width - 1) // self.screen_width
        self.scroll_speed = 10  # Adjust the scroll speed as needed
        self.scroll_offset = 0

    def visualize_universe(self):
        self.screen.fill((0, 0, 0))

        for i, alive in enumerate(self.universe):
            row = (i + self.scroll_offset) // self.screen_width
            col = (i + self.scroll_offset) % self.screen_width

            x = col * self.pixel_size
            y = row * self.pixel_size

            if 0 <= row < self.rows:
                color = (0, 255, 0) if alive else (0, 0, 0)  # Green for alive, black for dead
                pygame.draw.rect(self.screen, color, (x, y, self.pixel_size, self.pixel_size))

        pygame.display.flip()

    def handle_events(self):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                sys.exit()
            elif event.type == pygame.MOUSEBUTTONDOWN:
                if event.button == 4:  # Scroll up
                    self.scroll_offset -= self.scroll_speed
                elif event.button == 5:  # Scroll down
                    self.scroll_offset += self.scroll_speed

        keys = pygame.key.get_pressed()
        if keys[pygame.K_UP]:
            self.scroll_offset -= self.scroll_speed
        if keys[pygame.K_DOWN]:
            self.scroll_offset += self.scroll_speed
