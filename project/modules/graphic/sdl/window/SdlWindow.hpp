/**
 * @file SdlWindow.hpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-29
 * 
 * @addtogroup SDL
 * @{
 */

#ifndef SDLWINDOW_HPP_
#define SDLWINDOW_HPP_
//Sdl
#include "SDL.h"
#include "SDL_image.h"
//#include "SDL_ttf.h"
//#include "SDL_mixer.h"

//Interface
#include "IWindow.hpp"
//encapsulation
#include "SdlPolygon.hpp"
#include "SdlSprite.hpp"
#include "SdlText.hpp"

#include "SdlEvent.hpp"

#include "SdlCamera.hpp"
#include "SdlModel.hpp"

#include "SdlSound.hpp"
#include "SdlMusic.hpp"

#include <iostream>

/**
 * @brief Sdl Window class 
 */
class SdlWindow : public graphic::IWindow {

    public:

        /**
         * @brief Construct a new Sdl Window object
         * 
         * @param screenWidth 
         * @param screenHeight 
         * @param title 
         */
        SdlWindow(__int32_t screenWidth, __int32_t screenHeight, std::string title): is_open(false), _frameLimit(0), _start(0), _end(60), _delta(60) {
            std::cout << "SdlWindow::SdlWindow implemented" << std::endl;
            if((SDL_Init(SDL_INIT_VIDEO) < 0)) {
                std::cout << "SDL_Init failed" << std::endl;
                return;
            }            
            std::cout << "SDL_Init success" << std::endl;
            _window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
            if (!_window) {
                std::cout << "SDL_Window failed" << std::endl;
                return;
            }
            std::cout << "SDL_Window success" << std::endl;
            _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);

            //_surface = SDL_GetWindowSurface(_window);
            if(!_renderer) {
                std::cout << "SDL_Render failed" << std::endl;
            }
            std::cout << "SDL_Render success" << std::endl;
            is_open = true;
        }

        /**
         * @brief Destroy the Sdl Window object
         */
        ~SdlWindow() {
            std::cout << "SdlWindow::~SdlWindow implemented" << std::endl;
            SDL_DestroyRenderer(_renderer);
            SDL_DestroyWindow(_window);
        }
        
        /**
         * @brief link an event to the window
         * 
         * @param event 
         */
        void linkEvent(graphic::IEvent *event) override {
            _event = static_cast<SdlEvent *>(event);
        };

        /**
         * @brief notice if the window is open
         * 
         * @return true 
         * @return false 
         */
        bool isOpen() override {
            return is_open;
        };

        /**
         * @brief close the window
         */
        void close() override {
            SDL_Quit();
        };

        /**
         * @brief Set the Frame Limit object
         * 
         * @param limit 
         */
        void setFrameLimit(__int32_t limit) override {
            _frameLimit = limit;
        };

        /**
         * @brief Get the Delta object
         * 
         * @return __int32_t 
         */
        __int32_t getDelta() override {
            return _delta;
        };

        /**
         * @brief begin the 2D drawing
         */
        void beginDraw() override {
            std::cout << "SdlWindow::beginDraw not implemented" << std::endl;
            SDL_RenderClear(_renderer);
        };

        /**
         * @brief draw a polygon
         * 
         * @param polygon
         */
        void drawPoly(graphic::IPolygon *polygon) override;

        /**
         * @brief draw a sprite
         * 
         * @param sprite 
         */
        void drawSprite(graphic::ISprite *sprite) override;

        void drawText(graphic::IText *text) override;

        /**
         * @brief end the 2D drawing
         */
        void endDraw() override {
            SDL_RenderPresent(_renderer);

            //time handling
            _end = SDL_GetTicks64();
            _delta = _end - _start;
            if (_frameLimit != 0 && _delta < _frameLimit) {
                SDL_Delay(_frameLimit - _delta);
            }
            _start = _end;
        };

        /**
         * @brief allowing to draw 3D on the window
         * 
         * @param camera 
         */
        void beginMode3(graphic::ICamera *camera) override;
            
        /**
         * @brief draw a model
         * 
         * @param model 
         */
        virtual void drawModel(graphic::IModel *model) override;

        /**
         * @brief end the 3D drawing
         */
        void endMode3() override {
            std::cout << "SdlWindow::endMode3 not implemented" << std::endl;
            //EndMode3D();
        };

        /**
         * @brief poll the event
         * 
         * @return true 
         * @return false 
         */
        bool pollEvent() override {
            return SDL_PollEvent(&_event->_event) > 0;
        }

        /**
         * @brief close the window
         */
        void eventClose() override {
            if (_event == nullptr) {
                return;
            }
            if (_event->_event.type == SDL_QUIT || _event->_event.key.keysym.sym == SDLK_ESCAPE) {
                is_open = false;
            }
        };

        bool beginAudio() override {
            if (!is_audio_init && Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
                return false;
            } else {
                Mix_AllocateChannels(32); // Set max channels
                is_audio_init = true;
                return true;
            }
        };

        void endAudio() override {
            if (is_audio_init) {
                Mix_CloseAudio();
            }
        };

    private:
        bool is_audio_init; 
        bool is_open;
        SDL_Window   *_window;
        SDL_Renderer *_renderer;
        SdlEvent *_event;

        __int32_t _frameLimit;
            
        __uint64_t _start;
        __uint64_t _end;
        float _delta;
};

void SdlWindow::drawPoly(graphic::IPolygon *polygon) {
    std::cout << "SdlWindow::drawPoly not implemented" << std::endl;
    SdlPolygon *sdlPolygon = static_cast<SdlPolygon *>(polygon);

    std::vector<graphic::triangle_t> triangles = sdlPolygon->_triangles;
    std::vector<SDL_Vertex> points = sdlPolygon->_points;

    std::cout << "StartDraw" << std::endl;
    for (int i = 0; i < triangles.size(); i++) {
        //raylib ask for counter clockwise it's why I reverse the order
//        SDL_RenderGeometry(_renderer, nullptr, points.data(), points.size(), nullptr, 0);
        int rColor = rand()%255;
        SDL_Color color = {static_cast<unsigned char>(sdlPolygon->_color.r), static_cast<unsigned char>(sdlPolygon->_color.g), static_cast<unsigned char>(sdlPolygon->_color.b), static_cast<unsigned char>(sdlPolygon->_color.a)};
        
        std::vector<SDL_Vertex> vertices = {
            SDL_Vertex{SDL_FPoint{static_cast<float>(triangles[i].A.x), static_cast<float>(triangles[i].A.y)}, 
                        color, SDL_FPoint{0, 0}},
            SDL_Vertex{SDL_FPoint{static_cast<float>(triangles[i].B.x), static_cast<float>(triangles[i].B.y)}, 
                        color, SDL_FPoint{0, 0}},
            SDL_Vertex{SDL_FPoint{static_cast<float>(triangles[i].C.x), static_cast<float>(triangles[i].C.y)}, 
                        color, SDL_FPoint{0, 0}},
        }; 
        SDL_RenderGeometry(_renderer, nullptr, vertices.data(), vertices.size(), nullptr, 0);
        //DrawTriangle({static_cast<float>(triangles[i].C.x), static_cast<float>(triangles[i].C.y)},
        //            {static_cast<float>(triangles[i].B.x), static_cast<float>(triangles[i].B.y)},
        //            {static_cast<float>(triangles[i].A.x), static_cast<float>(triangles[i].A.y)},
        //            Color{static_cast<unsigned char>(rand()%255), 0, 0, 255});
    }
    std::cout << "EndDraw" << std::endl;
};

void SdlWindow::drawSprite(graphic::ISprite *sprite) {
    std::cout << "SdlWindow::drawSprite implemented" << std::endl;
    SdlSprite *sdlSprite = static_cast<SdlSprite *>(sprite);
    if (sdlSprite->_texture == nullptr && sdlSprite->_surface != nullptr) {
        sdlSprite->_texture = SDL_CreateTextureFromSurface(_renderer, sdlSprite->_surface);
    }
    SDL_FRect position = {static_cast<float>(sdlSprite->_position.x), 
                        static_cast<float>(sdlSprite->_position.y),
                        static_cast<float>(sdlSprite->_crop.w),
                        static_cast<float>(sdlSprite->_crop.h)};
    //SDL_FPoint center = {static_cast<float>(sdlSprite->_crop.w*-0.5), static_cast<float>(sdlSprite->_crop.h*-0.5)};
    SDL_FPoint center = {0, 0};
    std::cout << center.x << " " << center.y << std::endl;
    SDL_RenderCopyExF(_renderer, sdlSprite->_texture, &sdlSprite->_crop, &position, sdlSprite->_rotation,  &center, SDL_FLIP_NONE);
};

void SdlWindow::drawText(graphic::IText *text) {
    //std::cout << "SdlWindow::drawText implemented" << std::endl;
    //SdlText *sdlText = static_cast<SdlText *>(text);
//
    //if (sdlText->_texture == nullptr && sdlText->_surface != nullptr) {
    //    sdlText->_texture = SDL_CreateTextureFromSurface(_renderer, sdlText->_surface);
    //}
    //SDL_FRect position = {static_cast<float>(sdlText->_position.x), 
    //                    static_cast<float>(sdlText->_position.y),
    //                    static_cast<float>(sdlText->_surface->w),
    //                    static_cast<float>(sdlText->_surface->h)};
    //
    //SDL_FPoint center = {static_cast<float>(sdlText->_surface->w / 2), static_cast<float>(sdlText->_surface->h / 2)};
    //
    //SDL_RenderCopyExF(_renderer, sdlText->_texture, nullptr, &position, sdlText->_rotation,  &center, SDL_FLIP_NONE);
};

void SdlWindow::beginMode3(graphic::ICamera *camera) {
    std::cout << "SdlWindow::beginMode3 not implemented" << std::endl;
};

void SdlWindow::drawModel(graphic::IModel *model) {
    std::cout << "SdlWindow::drawModel not implemented" << std::endl;
};

#endif /* !SDLWINDOW_HPP_ */