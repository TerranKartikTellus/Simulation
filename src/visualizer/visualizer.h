// visualizer.h
#pragma once

#include <vector>

class Visualizer {
public:
    Visualizer(const std::vector<bool>& universe, int pixelSize);
    void visualizeUniverse();
    void handleEvents();

private:
    const std::vector<bool>& universe;
    int pixelSize;
    int screenWidth;
    int screenHeight;
    int rows;
    int scrollSpeed;
    int scrollOffset;

    void drawRectangle(int x, int y, int width, int height, int red, int green, int blue);
};
