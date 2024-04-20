/**
 *
 * File: SfmlWindow.hpp (header.v2)
 * Created Date: Tue 14/03/2023
 * Project: PERRY
 * Author: Perry Chouteau
 *
 * Last Modified: Sat 18/03/2023
 * Modified By: Perry Chouteau
 *
 * Copyright (c) 2023-2033 Perry Chouteau
 *
 **/

#ifndef SFMLWINDOW_HPP_
#define SFMLWINDOW_HPP_

//SFML
#include <SFML/Graphics.hpp>

//Interface
#include "../../../Interfaces/graphic3/window/IWindow.hpp"
#include "../../../Interfaces/system/math.hpp"
//encapsulation
#include "../graphic/SfmlPolygon.hpp"
#include "../graphic/SfmlSprite.hpp"
#include "../graphic/SfmlModel.hpp"

#include "SfmlCamera.hpp"

class SfmlWindow : public graphic3::IWindow {

    public:
        SfmlWindow(__int32_t screenWidth, __int32_t screenHeight, std::string title)
        : _window(sf::VideoMode(screenWidth, screenHeight), title) {
        };

        ~SfmlWindow() = default;

        //GLOBAL
        bool isOpen() override {
            return _window.isOpen();
        };

        void close() override {
            _window.close();
        };

        //DRAW
        void beginDraw() override {
            _window.clear();
        };

        virtual void drawPoly(graphic3::IPolygon *polygon) override;
        virtual void drawSprite(graphic3::ISprite *sprite) override;

        void endDraw() override {
            _window.display();
        };

        //Draw3 (Carve)
        void beginMode3(graphic3::ICamera *camera) override {
            std::cout << "Sfml::beginMode3 not implemented" << std::endl;
        }
        
        virtual void drawModel(graphic3::IModel *model) override {
            std::cout << "Sfml::drawModel not implemented" << std::endl;
        }

        void endMode3() override {
            std::cout << "Sfml::endMode3 not implemented" << std::endl;
        };

        //EVENT
        bool isPoll() override {
            return true;
        }

        bool pollEvent() override {
            return _window.pollEvent(_event);
        }

        void eventClose() override {
            if (_event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                _window.close();
        };

    private:
        sf::RenderWindow _window;
        sf::Event _event;
};

void SfmlWindow::drawPoly(graphic3::IPolygon *polygon) {
    SfmlPolygon *sfmlpolygon = static_cast<SfmlPolygon *>(polygon);

    std::cout << "StartDraw" << std::endl;
    _window.draw(sfmlpolygon->_points.data(), sfmlpolygon->_points.size(), sf::Points);
    std::cout << "EndDraw" << std::endl;
};

void SfmlWindow::drawSprite(graphic3::ISprite *sprite) {
    SfmlSprite *sfmlsprite = static_cast<SfmlSprite *>(sprite);
    _window.draw(sfmlsprite->_sprite);
};

#endif /* !SFMLWINDOW_HPP_ */