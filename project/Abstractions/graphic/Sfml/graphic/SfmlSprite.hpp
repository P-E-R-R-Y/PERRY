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


#ifndef SFMLSPRITE_HPP_
#define SFMLSPRITE_HPP_

//Interface
#include "../../../interfaces/graphic/graphic/IPolygon.hpp"

//Raylib
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class SfmlSprite : public graphic::ISprite {

    public:
        SfmlSprite(std::string path) {
            if (_texture.loadFromFile(path)) {
                _sprite.setTexture(_texture);
            }
            _position = {0, 0};
            _scale = {1, 1};
        }

        ~SfmlSprite() = default;

        bool isReady() const override {
            return (_sprite.getTexture() != nullptr);
        }

        __v4f_t getBounds() const override {
            sf::FloatRect rect = _sprite.getGlobalBounds();
            return { rect.left, rect.top, rect.width, rect.height};
        }

        void setCrop(__v4f_t rect) override {
            _sprite.setTextureRect(sf::IntRect(rect.x, rect.y, rect.w, rect.h));
        }

        __v2f_t getPosition() const override {
            return { _sprite.getPosition().x, _sprite.getPosition().y};
        }
        void setPosition(__v2f_t position) override {
            _sprite.setPosition(position.x, position.y);
        }

        float getRotation() const override {
            return _sprite.getRotation();
        }

        void setRotation(float angle, bool isRad = false) override {
            if (isRad) {
                _sprite.setRotation(angle * 180.f / M_PI);
            } else {
                _sprite.setRotation(angle);
            }
        }

        __v2f_t getSize() const override {
            sf::Vector2u size = _sprite.getTexture()->getSize();
            sf::Vector2f scale = _sprite.getScale();
            return {float(size.x) * scale.x, float(size.y) * scale.y};
        }

        void setSize(__v2f_t size) override {
            auto oldSize = _sprite.getTexture()->getSize();
            _sprite.setScale(size.x/oldSize.x, size.y/oldSize.y);
        }

        friend class SfmlWindow;

    private:
        sf::Texture _texture;
        sf::Sprite _sprite;
        sf::Vector2f _position;
        sf::Vector2f _scale;
        //your variables here
};

#endif /* !SFMLSPRITE_HPP_ */