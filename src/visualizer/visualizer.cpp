// visualizer.cpp
#include "visualizer.h"
#include <iostream>
#include <SDL.h>
#include <SDL_events.h>

Visualizer::Visualizer(const std::vector<bool>& universe, int pixelSize)
    : universe(universe), pixelSize(pixelSize), screenWidth(800), screenHeight(600),
      rows((universe.size() + screenWidth - 1) / screenWidth), scrollSpeed(10), scrollOffset(0) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(screenWidth, screenHeight, 0, &window, &renderer);
}

void Visualizer::visualizeUniverse() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    for (int i = 0; i < universe.size(); ++i) {
        int row = (i + scrollOffset) / screenWidth;
        int col = (i + scrollOffset) % screenWidth;

        int x = col * pixelSize;
        int y = row * pixelSize;

        if (row >= 0 && row < rows) {
            int color = universe[i] ? 0x00FF00 : 0x000000;
            drawRectangle(x, y, pixelSize, pixelSize, (color >> 16) & 0xFF, (color >> 8) & 0xFF, color & 0xFF);
        }
    }

    SDL_RenderPresent(renderer);
}

void Visualizer::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            SDL_Quit();
            exit(0);
        } else if (event.type == SDL_MOUSEBUTTONDOWN) {
            if (event.button.button == SDL_BUTTON_WHEELUP) {
                scrollOffset -= scrollSpeed;
            } else if (event.button.button == SDL_BUTTON_WHEELDOWN) {
                scrollOffset += scrollSpeed;
            }
        }
    }

    const Uint8* state = SDL_GetKeyboardState(nullptr);
    if (state[SDL_SCANCODE_UP]) {
        scrollOffset -= scrollSpeed;
    }
    if (state[SDL_SCANCODE_DOWN]) {
        scrollOffset += scrollSpeed;
    }
}

void Visualizer::drawRectangle(int x, int y, int width, int height, int red, int green, int blue) {
    SDL_Rect rect{ x, y, width, height };
    SDL_SetRenderDrawColor(renderer, red, green, blue, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, &rect);
}
