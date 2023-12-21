# universe.py

import random

class Universe:
    def __init__(self, size, num_creatures):
        self.size = size
        self.num_creatures = num_creatures
        self.cells = self.initialize_universe()

    def initialize_universe(self):
        universe = [False] * self.size
        alive_indices = random.sample(range(self.size), self.num_creatures)
        for idx in alive_indices:
            universe[idx] = True
        return universe
