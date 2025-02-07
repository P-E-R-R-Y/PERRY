/**
 * @file Window.hpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-07
 */

#ifndef SDLWINDOW_HPP_
    #define SDLWINDOW_HPP_

#include "IWindow.hpp"

#include "Text.hpp"

#include "SDL.h"
#include <SDL_ttf.h>

#include <iostream>

static const int WIDTH = 800;
static const int HEIGHT = 600;

class SdlWindow: public graphic::IWindow {
    public:
        SdlWindow() {
            // Initialize SDL and SDL_ttf
            if (SDL_Init(SDL_INIT_VIDEO) < 0) {
                std::cerr << "SDL could not initialize! Error: " << SDL_GetError() << std::endl;
                m_isOpen = false;
                return;
            }
            if (TTF_Init() == -1) {
                std::cerr << "SDL_ttf could not initialize! Error: " << TTF_GetError() << std::endl;
                m_isOpen = false;
                return;
            }

            // Create window
            window = SDL_CreateWindow("SDL2 Text Example", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
            if (!window) {
                std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
                m_isOpen = false;
                return;
            }

            // Create renderer
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if (!renderer) {
                std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
                m_isOpen = false;
                return;
            }

            m_isOpen = true;
        }

        ~SdlWindow() override {
            SDL_DestroyWindow(window);
            SDL_Quit();
        }
        
        bool isOpen() override {
            return m_isOpen;
        }
        
        void beginDraw() override {
            SDL_RenderClear(renderer);
        }

        void drawText(graphic::IText *text) override {
            SdlText *sdlText = static_cast<SdlText *>(text);

            // Create text texture
            SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, sdlText->textSurface);
            if (!textTexture) {
                std::cerr << "Unable to create texture from rendered text! SDL_Error: " << SDL_GetError() << std::endl;
                return;
            }

            // Get texture size
            int textWidth, textHeight;
            SDL_QueryTexture(textTexture, nullptr, nullptr, &textWidth, &textHeight);
            SDL_Rect textRect = { (WIDTH - textWidth) / 2, (HEIGHT - textHeight) / 2, textWidth, textHeight };

            // Render text
            SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);            
        }

        /**
         * @brief end the 2D drawing
         */
        void endDraw() override {
            SDL_RenderPresent(renderer);
        }

        bool pollEvent() override {
            return SDL_PollEvent(&event) > 0;
        }

        void close() override {
            if (event.type == SDL_QUIT) {
                m_isOpen = false;
            }
        }

        
    private:
        bool m_isOpen;
        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Event event;
};

#endif /* !SDLWINDOW_HPP_ */