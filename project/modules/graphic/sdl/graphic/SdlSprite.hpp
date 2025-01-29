/**
 * @file SdlSprite.hpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-29
 * 
 * @addtogroup SDL
 * @{
 */


#ifndef SDLSPRITE_HPP_
#define SDLSPRITE_HPP_

//Interface
#include "../../../../interfaces/graphic/graphic/IPolygon.hpp"

//Sdl
#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>
#include "SDL.h"
#include "SDL_image.h"

/**
 * @brief Used to handle images
 */
class SdlSprite : public graphic::ISprite {

    public:
        /**
         * @brief Construct a new Sdl Sprite object
         * 
         * @param path 
         */
        SdlSprite(std::string path) {
            _surface = IMG_Load(path.c_str());
            _texture = nullptr;
            _crop = {0, 0, _surface->w, _surface->h};
            _position = {0, 0};            
        }

        /**
         * @brief Destroy the Sdl Sprite object
         */
        ~SdlSprite() override {
            if (_surface != nullptr)
                SDL_FreeSurface(_surface);
        }

        /**
         * @brief check if the sprite is ready
         * 
         * @return true 
         * @return false 
         */
        bool isReady() const override {
            return _surface != nullptr;
            //return IsTextureReady(_texture);
        }

        /**
         * @brief Get the Bounds object
         * 
         * @return __v4f_t 
         */
        __v4f_t getBounds() const override {
            return {_position.x,
                    _position.y,
                    static_cast<float>(_crop.w),
                    static_cast<float>(_crop.h)};
        }

        /**
         * @brief Set the Crop object
         * 
         * @param rect 
         */
        void setCrop(__v4f_t rect) override {
            _crop = {static_cast<int>(rect.x),
                    static_cast<int>(rect.y), 
                    static_cast<int>(rect.w), 
                    static_cast<int>(rect.h)};
        }

        /**
         * @brief Get the Position object
         * 
         * @return __v2f_t 
         */
        __v2f_t getPosition() const override {
            return _position;
        }

        /**
         * @brief Set the Position object
         * 
         * @param position 
         */
        void setPosition(__v2f_t position) override {
            _position = position;
        }
        
        /**
         * @brief Get the Rotation object
         * 
         * @return float 
         */
        float getRotation() const override {
            return _rotation;
        }

        /**
         * @brief Set the Rotation object
         * 
         * @param angle 
         * @param isRad 
         */
        void setRotation(float angle, bool isRad = false) override {
            if (isRad) {
                _rotation = angle * 180 / M_PI;
            } else {
                _rotation = angle;
            }
        }

        /**
         * @brief Get the Size object
         * 
         * @return __v2f_t 
         */
        __v2f_t getSize() const override {
            std::cout << "getSize not implemented" << std::endl;
            return {0, 0};
        //    return { float(_texture.width) * _scale.x, float(_texture.height) * _scale.y };
        }

        /**
         * @brief Set the Size object
         * 
         * @param size 
         */
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
};

#endif /* !SDLSPRITE_HPP_ */