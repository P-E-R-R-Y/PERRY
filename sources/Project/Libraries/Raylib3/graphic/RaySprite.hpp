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


#ifndef RAYSPRITE_HPP_
#define RAYSPRITE_HPP_

//Interface
#include "../../../Interfaces/graphic3/graphic/IPolygon.hpp"

//Raylib
#include <raylib.h>

class RaySprite : public graphic3::ISprite {

    public:
        RaySprite(std::string path) {
            _texture = LoadTexture(path.c_str());
            _position = {0, 0};
            _scale = {1, 1};
            _crop = {0, 0, float(_texture.width), float(_texture.height)};
        }

        ~RaySprite() {
            UnloadTexture(_texture);
        }

        bool isReady() const override {
            return IsTextureReady(_texture);
        }

        __v4f_t getBounds() const override {
            return {_position.x, _position.y, float(_texture.width), float(_texture.height)};
        }

        void setCrop(__v4f_t rect) override {
            _crop = {float(rect.x), float(rect.y), float(rect.w), float(rect.h)};
        }

        __v2f_t getPosition() const override {
            return {_position.x, _position.y};
        }
        void setPosition(__v2f_t position) override {
            _position = {float(position.x), float(position.y)};
        }

        __v2f_t getSize() const override {
            return { float(_texture.width) * _scale.x, float(_texture.height) * _scale.y };
        }

        void setSize(__v2f_t size) override {
            _scale = {float(this->getSize().x/float(_texture.width)), float(this->getSize().y/float(_texture.height))};
        }

        friend class RayWindow;

    private:
        Texture2D _texture;
        Vector2 _position;
        Vector2 _scale;
        Rectangle _crop;
        //your variables here
};

#endif /* !RAYSPRITE_HPP_ */