/**
 *
 * File: RayModel2.hpp
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
#include "../../../Interfaces/graphic3/graphic/IPolygon.hpp"

//Sdl
//#include <SDL3/SDL.h>

class SdlSprite : public graphic3::ISprite {

    public:
        SdlSprite(std::string path) {
            std::cout << "SdlSprite not implemented" << std::endl;
            //_texture = LoadTexture(path.c_str());
            //_position = {0, 0};
            //_scale = {1, 1};
            //_crop = {0, 0, float(_texture.width), float(_texture.height)};
        }

        ~SdlSprite() {
            //UnloadTexture(_texture);
        }

        bool isReady() const override {
            std::cout << "isReady not implemented" << std::endl;
            return true;
            //return IsTextureReady(_texture);
        }

        __v4f_t getBounds() const override {
            std::cout << "getBounds not implemented" << std::endl;
            return {0, 0, 0, 0};
            //return {_position.x, _position.y, float(_texture.width), float(_texture.height)};
        }

        void setCrop(__v4f_t rect) override {
            std::cout << "setCrop not implemented" << std::endl;
            //_crop = {float(rect.x), float(rect.y), float(rect.w), float(rect.h)};
        }

        __v2f_t getPosition() const override {
            std::cout << "getPosition not implemented" << std::endl;
            return {0, 0};
            //return {_position.x, _position.y};
        }
        void setPosition(__v2f_t position) override {
            std::cout << "setPosition not implemented" << std::endl;
            //_position = {float(position.x), float(position.y)};
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
        //Texture2D _texture;
        //__v2f_t _position;
        //Vector2 _scale;
        //Rectangle _crop;
        ////your variables here
};

#endif /* !SDLSPRITE_HPP_ */