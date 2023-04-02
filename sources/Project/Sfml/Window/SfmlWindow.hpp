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

//Interface
#include "../../Interface/Window/IWindow.hpp"
#include "../../Interface/Graphics/IModel2.hpp"

//SFML
#include <SFML/Graphics.hpp>

class SfmlWindow : public IWindow {

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
        };

        //DRAW
        void beginDraw() override {
            _window.clear();
        };

        void draw2(IModel2 *model) override;

        void endDraw() override {
            _window.display();
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

//encapsulation
#include "../Graphics/SfmlModel2.hpp"

void SfmlWindow::draw2(IModel2 *model) {
    SfmlModel2 *sfmlmodel = static_cast<SfmlModel2 *>(model);
    _window.draw(sfmlmodel->_sprite);
};

#endif /* !SFMLWINDOW_HPP_ */