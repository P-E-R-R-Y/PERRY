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
        : _window(sf::VideoMode(screenWidth, screenHeight), "SFML window"), _clock() {
            ;
        };

        ~SfmlWindow() override {};

        void display() override {
            _window.display();
        };

        void clear() override {
            _window.clear(sf::Color::White);
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

        bool isCursorVisible() override {
            return _cursorVisible;
        };

        void setSize(__v2u_s size) override {
            _window.setSize(sf::Vector2u(size.x, size.y));
        };

        // __v2u_s getSize() override {
        //     sf::Vector2u size = _window.getSize();
        //     return { static_cast<__uint32_t>(size.x), static_cast<__uint32_t>(size.y) };
        // };

        // void setTitle(std::string title) override {
        //     _window.setTitle(title.c_str());
        // }

        // void setVisible(bool enabled) override {
        //     _window.setVisible(enabled);
        // }

        // void setFramerateLimit(__int32_t framerate) override {
        //     _window.setFramerateLimit(framerate);
        //     _framerate = framerate;
        // }

        // __int32_t getFramerateLimit() override {
        //     return _framerate;
        // }

        // __int32_t getTime() override {
        //     return _clock.getElapsedTime().asMilliseconds();
        // }

        // void setCursorVisible(bool enabled) override {
        //     _window.setMouseCursorVisible(enabled);
        // }

        // bool getCursorVisible() override {
        //     return _cursorVisible;
        // }

        // virtual bool pollEvent() override {
        //     _window.pollEvent(_event);
        // }

        // virtual void takeScreenshot(std::string path) override {
        //     _window.capture().saveToFile(path);
        // }

        // //beginDraw 2D
        // virtual void beginModel2(ICamera2 camera2) override {
        //     std::cout << "beginModel2 not implemented" << std::endl;
        // }
        // virtual void endModel2() override {
        //     std::cout << "endModel2 not implemented" << std::endl;
        // }

        // //beginMode 3D
        // void beginModel3(ICamera3 camera3) override {
        //     std::cout << "beginModel3 not implemented" << std::endl;
        // };
        // void endModel3() override {
        //     std::cout << "endModel3 not implemented" << std::endl;
        // };

        // //draw 2D/3D
        // void draw(IModel2 &model2) override {
        //     model2._draw(*this);
        // }

        // void draw(IModel3 &model3) override {
        //     std::cout << "draw (model3) not implemented" << std::endl;
        // }

        friend class SfmlModel2;

    private:
        sf::RenderWindow _window;
        //your variables here
        sf::Event _event;
        __int32_t _framerate;
        bool _cursorVisible;
        sf::Clock _clock;
};