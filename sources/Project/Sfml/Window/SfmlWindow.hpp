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

#include "../../Interface/Window/IWindow.hpp"
#include <SFML/Graphics.hpp>

class SfmlWindow : public IWindow {

    public:
        SfmlWindow(__int32_t screenWidth, __int32_t screenHeight, std::string title)
        : _window(sf::VideoMode(screenWidth, screenHeight), title) {
        };

        void display() override {
            _window.display();
        };

        void clear() override {
            _window.clear();
        };

        bool isReady() override {
            return _window.isOpen();
        };

        bool isOpen() override {
            return _window.isOpen();
        };

        void close() override {
            _window.close();
        };

    private:
        sf::RenderWindow _window;
};