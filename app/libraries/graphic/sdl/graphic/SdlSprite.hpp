/**
 *
 * File: SdlSprite.hpp
 * Created Date: Fr Mar 2023
 * Project: PERRY
 * Author: Perry Chouteau
 *
 * Last Modified: Fri Mar 10 2023
 * Modified By: Perry Chouteau
 *
 * Copyright (c) 2023-2033 Perry Chouteau
 *
 **/


#ifndef SDLSPRITE_HPP_
#define SDLSPRITE_HPP_

//Interface
#include "../../../../interfaces/graphic/graphic/IPolygon.hpp"

//Sdl
#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>
#include "SDL.h"
#include "SDL_image.h"

class SdlSprite : public graphic::ISprite {

    public:
        SdlSprite(std::string path) {
            _surface = IMG_Load(path.c_str());
            _texture = nullptr;
            _crop = {0, 0, _surface->w, _surface->h};
            _position = {0, 0};            
//            SDL_Surface *surface = IMG_LoadTexture(_render, path.c_str());
            //_texture = LoadTexture(path.c_str());
            //_position = {0, 0};
            //_scale = {1, 1};
        }

        ~SdlSprite() override {
            if (_surface != nullptr)
                SDL_FreeSurface(_surface);
        }

        bool isReady() const override {
            return _surface != nullptr;
            //return IsTextureReady(_texture);
        }

        __v4f_t getBounds() const override {
            return {_position.x,
                    _position.y,
                    static_cast<float>(_crop.w),
                    static_cast<float>(_crop.h)};
        }

        void setCrop(__v4f_t rect) override {
            _crop = {static_cast<int>(rect.x),
                    static_cast<int>(rect.y), 
                    static_cast<int>(rect.w), 
                    static_cast<int>(rect.h)};
        }

        __v2f_t getPosition() const override {
            return _position;
        }

        void setPosition(__v2f_t position) override {
            _position = position;
        }

        float getRotation() const override {
            return _rotation;
        }

        void setRotation(float angle, bool isRad = false) override {
            if (isRad) {
                _rotation = angle * 180 / M_PI;
            } else {
                _rotation = angle;
            }
        }

        __v2f_t getSize() const override {
            std::cout << "getSize not implemented" << std::endl;
            return {0, 0};
        //    return { float(_texture.width) * _scale.x, float(_texture.height) * _scale.y };
        }

        void setSize(__v2f_t size) override {
            std::cout << "setSize not implemented" << std::endl;
        //   _scale = {float(this->getSize().x/float(_texture.width)), float(this->getSize().y/float(_texture.height))};
        }

        friend class SdlWindow;

    private:
        SDL_Surface *_surface;
        SDL_Texture *_texture;
        __v2f_t _position;
        SDL_Rect _crop;
        float _rotation;
        ////your variables here
};

#endif /* !SDLSPRITE_HPP_ */