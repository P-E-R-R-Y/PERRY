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

#include "../../Interface/Window/IWindow.hpp"
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

// sfml                     // raylib           // code
// event                    // ask_event()       // if is_poll_event() {
//while (poll_event()) {    // ask_event()       //     while(poll_event()) {
//    ask_event()s          // ask_event()       //         ask_events();
//}                         // ask_event()       //     }
                                                 // } else {
                                                 //     ask_events();
                                                 // }

                                                 // ask_event() {
                                                 //     ask_event()
                                                 //     ask_event()
                                                 // }
