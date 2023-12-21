// universe.cpp
#include "universe.h"
#include <random>

Universe::Universe(int size, int numCreatures)
    : size(size), numCreatures(numCreatures), cells(std::make_unique<std::vector<bool>>()) {
    initializeUniverse();
}

const std::vector<bool>& Universe::getCells() const {
    return *cells;
}

void Universe::initializeUniverse() {
    cells->resize(size, false);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, size - 1);

    for (int i = 0; i < numCreatures; ++i) {
        int idx = distribution(gen);
        (*cells)[idx] = true;
    }
}
