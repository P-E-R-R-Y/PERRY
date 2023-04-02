/**
 *
 * File: IWindow.hpp
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

#ifndef SFMLMODEL2_HPP_
#define SFMLMODEL2_HPP_

//Interface
#include "../../Interface/Graphics/IModel2.hpp"

//SFML
#include <SFML/Graphics.hpp>

//friends
#include "../Window/SfmlWindow.hpp"

class SfmlModel2 : public IModel2 {

    public:
        SfmlModel2(std::string path) {
            if (_texture.loadFromFile(path)) {
                _sprite.setTexture(_texture);
            }
        }

        ~SfmlModel2() = default;

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
        //your variables here
        sf::Texture _texture;
        sf::Sprite _sprite;
};

#endif /* !SFMLMODEL2_HPP_ */