/**
 *
 * File: IModel2.hpp
 * Created Date: Fr Mar 2023
 * Project: PERRY
 * Author: Perry Chouteau
 *
 * Last Modified: Sat Mar 11 2023
 * Modified By: Perry Chouteau
 *
 * Copyright (c) 2023-2033 Perry Chouteau
 *
 **/

#ifndef SFMLMODEL2_HPP_
#define SFMLMODEL2_HPP_

#include "../../Interface/Graphics/IModel2.hpp"
#include <SFML/Graphics.hpp>

class SfmlModel2 : public IModel2 {
    public:
        SfmlModel2(std::string path) {
            sf::Texture texture;
            sf::Sprite sprite;
        };
        ~SfmlModel2() override {
            ;
        };

        void setPositon(__v2f_t positon) override {
            _sprite.setPosition(positon.x, positon.y);
        }

        void setScale(__v2f_t scale) override {
            _sprite.setScale(scale.x, scale.y);
        }

        void setRect(__v4f_t rect) override {
            _sprite.setTextureRect(sf::IntRect(rect.x, rect.y, rect.w, rect.h));
        }

        void setRotation(double rotation) override {
            std::cout << "setRotation not implemented" << std::endl;
        }

        __v2f_s getPositon() {
            _sprite.getPosition();
        }

        __v2f_s getScale() {
            ;
        }

        __v4f_s getRect() {
            ;
        }

        double getRotation() {
            ;
        }

    /*    friend class IWindow;

    private:*/
        virtual void _draw(IWindow &window) override {
            window._window.draw(_sprite);
        }

    private:
        //your variables here
        sf::Texture _texture;
        sf::Sprite _sprite;
};

#endif /* !IMODEL2_HPP_ */