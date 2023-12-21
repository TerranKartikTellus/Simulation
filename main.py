# main.py

import pygame
from universe import Universe
from visualizer import Visualizer

def get_user_input():
    def_n = 90000
    def_m = 18723

    user_input_n = input(f"Enter the size of the universe (n, default is {def_n}): ")
    user_input_m = input(f"Enter the number of creatures (m, default is {def_m}): ")

    n = int(user_input_n.strip()) if user_input_n.strip() else def_n
    m = int(user_input_m.strip()) if user_input_m.strip() else def_m

    return n, m

def main():
    # Get user input for the size of the universe (n) and number of creatures (m)
    n, m = get_user_input()

    # Check if m is less than n
    if m >= n:
        print("Number of creatures must be less than the size of the universe.")
        pygame.quit()
        return

    # Initialize the Pygame library
    pygame.init()

    # Set the pixel size for visualization
    pixel_size = 5

    # Initialize the universe
    universe = Universe(n, m)

    # Initialize the visualizer and set window caption
    visualizer = Visualizer(universe.cells, pixel_size)
    pygame.display.set_caption("Lumino: 1D Universe")

    # Run the visualization loop
    running = True
    while running:
        # Handle events
        visualizer.handle_events()

        # Visualize the universe
        visualizer.visualize_universe()

    # Quit Pygame
    pygame.quit()

if __name__ == "__main__":
    main()
