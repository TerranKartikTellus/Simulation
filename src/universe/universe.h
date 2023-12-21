// universe.h
#pragma once

#include <vector>
#include <memory>

class Universe {
public:
    Universe(int size, int numCreatures);
    const std::vector<bool>& getCells() const;

private:
    int size;
    int numCreatures;
    std::unique_ptr<std::vector<bool>> cells;

    void initializeUniverse();
};
