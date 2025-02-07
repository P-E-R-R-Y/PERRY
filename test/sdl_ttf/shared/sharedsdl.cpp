/**
 * @file main.cpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-06
 */

#include "SDL.h"
#include "SDL_ttf.h"
#include <iostream>

#include "graphic/Window.hpp"
#include "graphic/Text.hpp"

extern "C" graphic::IWindow *createWindow() {
    return new SdlWindow();
}

extern "C" void deleteWindow(graphic::IWindow *window) {
    delete window;
}

extern "C" graphic::IText *createText(std::string data, std::string font) {
    return new SdlText(data, font);
}

extern "C" void deleteText(graphic::IText *text) {
    delete text;
}

extern "C" int function() {
    // Initialize SDL and SDL_ttf
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! Error: " << SDL_GetError() << std::endl;
        return -1;
    }
    if (TTF_Init() == -1) {
        std::cerr << "SDL_ttf could not initialize! Error: " << TTF_GetError() << std::endl;
        return -1;
    }

    // Create window
    SDL_Window* window = SDL_CreateWindow("SDL2 Text Example", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return -1;
    }

    // Create renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return -1;
    }

    // Load font
    TTF_Font* font = TTF_OpenFont("assets/noto.ttf", 24);
    if (!font) {
        std::cerr << "Failed to load font! TTF_Error: " << TTF_GetError() << std::endl;
        return -1;
    }

    // Create text surface and texture
    SDL_Color textColor = {255, 255, 255}; // White color
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, "Hello, SDL2!", textColor);
    if (!textSurface) {
        std::cerr << "Unable to render text surface! TTF_Error: " << TTF_GetError() << std::endl;
        return -1;
    }
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface); // Free surface after creating texture

    // Get texture size
    int textWidth, textHeight;
    SDL_QueryTexture(textTexture, nullptr, nullptr, &textWidth, &textHeight);
    SDL_Rect textRect = { (WIDTH - textWidth) / 2, (HEIGHT - textHeight) / 2, textWidth, textHeight };

    // Main loop
    bool running = true;
    SDL_Event e;
    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                running = false;
            }
        }

        // Clear screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Render text
        SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);

        // Present the renderer
        SDL_RenderPresent(renderer);
    }

    // Cleanup
    SDL_DestroyTexture(textTexture);
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();

    return 0;
}