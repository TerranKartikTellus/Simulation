// main.cpp
#include "universe.h"
#include "visualizer.h"

int main() {
    const int n = 90000;
    const int m = 18723;
    Universe universe(n, m);
    Visualizer visualizer(universe.getCells(), 5);

    while (true) {
        visualizer.handleEvents();
        visualizer.visualizeUniverse();
    }

    return 0;
}
