/**
 * @file SdlText.hpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-03
 * 
 * @addtogroup Sdl
 */

#ifndef SDLTEXT_HPP_
    #define SDLTEXT_HPP_

    //standard
    #include <string>
    #include <iostream>

    //Interface
    #include "IText.hpp"

    //Sdl
    #include "SDL.h"
//    #include "SDL_image.h"
//    #include "SDL_ttf.h"


class SdlText: public graphic::IText {

    public:
        SdlText(std::string data, std::string font) {
            _data = data;
            _path = font;
            _size = 20;
            _position = {0, 0};
            _rotation = 0;

            //_font = TTF_OpenFont(font.c_str(), _size);
            _color = {255, 255, 255, 255};
            //_surface = TTF_RenderText_Solid(_font, data.c_str(), _color);
            _texture = nullptr;
        }

        virtual ~SdlText() = default;

        bool isReady() const override {
            return false; //_font != NULL;
        }

        void setText(std::string text) override {
            _data = text;
            //if (_surface != nullptr) {
            //    SDL_FreeSurface(_surface);
            //}
            //_surface = TTF_RenderText_Solid(_font, text.c_str(), _color);
            //if (_texture != nullptr) {
            //    SDL_DestroyTexture(_texture);
            //}
        } 

        std::string getText() const override {
            return _data;
        } 

        void setFont(std::string font) override {
            _path = font;
            //if (_font != nullptr) {
            //    TTF_CloseFont(_font);
            //}
            //_font = TTF_OpenFont(font.c_str(), _size);
        }

        void setFontSize(unsigned int size) override {
            _size = size;
            //if (_font != nullptr) {
            //    TTF_CloseFont(_font);
            //}
            //_font = TTF_OpenFont(_path.c_str(), _size);
        }
        unsigned int getFontSize() const override {
            return _size;
        }

        void setTextColor(__color_t color) override {
            _color = {static_cast<Uint8>(color.r), static_cast<Uint8>(color.g), static_cast<Uint8>(color.b), static_cast<Uint8>(color.a)};
        } 
        __color_t getTextColor() const override {
            return __color_t{static_cast<double>(_color.r), static_cast<double>(_color.g), static_cast<double>(_color.b), static_cast<double>(_color.a)};
        } 

        void setPosition(__v2f_t position) override {
            _position = position;
        }
        
        __v2f_t getPosition() const override {
            return __v2f_t{_position.x, _position.y};
        }

        void setRotation(float angle) override {
            std::cout << "SdlText::setRotation not implemented" << std::endl;
        }

        float getRotation() const override {
            return 0;
        }

        friend class SdlWindow;

    private:

        std::string _data;
        std::string _path;
        unsigned int _size; 
        __v2f_t _position;
        float _rotation;

        //TTF_Font *_font;
        SDL_Color _color;
        SDL_Surface *_surface;
        SDL_Texture *_texture;

};

#endif /* !SDLTEXT_HPP_ */