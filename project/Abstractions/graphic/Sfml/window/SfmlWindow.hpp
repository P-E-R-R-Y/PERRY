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

///SFML
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

///Interface
#include "../../../../Interfaces/graphic/window/IWindow.hpp"
#include "../../../../Interfaces/system/math.hpp"

///Abstract
//graphic
#include "../graphic/SfmlPolygon.hpp"
#include "../graphic/SfmlSprite.hpp"
#include "../graphic/SfmlModel.hpp"
//event
#include "../event/SfmlEvent.hpp"
//window
#include "SfmlCamera.hpp"

class SfmlWindow : public graphic::IWindow {

    public:
        SfmlWindow(__int32_t screenWidth, __int32_t screenHeight, std::string title)
        : _window(sf::VideoMode(screenWidth, screenHeight), title), _event(nullptr){
            _window.setFramerateLimit(60);
        };

        ~SfmlWindow() = default;

        //EVENT
        void linkEvent(graphic::IEvent *event) override {
            _event = static_cast<SfmlEvent *>(event);
        };
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

        virtual void drawPoly(graphic::IPolygon *polygon) override;
        virtual void drawSprite(graphic::ISprite *sprite) override;

        void endDraw() override {
            _window.display();
        };

        //Draw3 (Carve)
        void beginMode3(graphic::ICamera *camera) override {
            std::cout << "Sfml::beginMode3 not implemented" << std::endl;
        }
        
        virtual void drawModel(graphic::IModel *model) override {
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
            return _window.pollEvent(_event->_event);
        }

        void eventClose() override {
            if (_event->_event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                _window.close();
        };

    private:
        sf::RenderWindow _window;
        SfmlEvent *_event;
};

void SfmlWindow::drawPoly(graphic::IPolygon *polygon) {
    SfmlPolygon *sfmlPolygon = static_cast<SfmlPolygon *>(polygon);
    std::vector<graphic::triangle_t> triangles = sfmlPolygon->_triangles;

    std::cout << "StartDraw" << std::endl;
    for (int i = 0; i < triangles.size(); i++) {
        sf::ConvexShape cpolygon;
        cpolygon.setPointCount(3);
        cpolygon.setPoint(0, sf::Vector2f(triangles[i].A.x, triangles[i].A.y));
        cpolygon.setPoint(1, sf::Vector2f(triangles[i].B.x, triangles[i].B.y));
        cpolygon.setPoint(2, sf::Vector2f(triangles[i].C.x, triangles[i].C.y));
        cpolygon.setFillColor(sf::Color{static_cast<sf::Uint8>(rand()%255), 0, 0, 255});

        cpolygon.setPosition(0, 0);
        _window.draw(cpolygon);
    }
    std::cout << "EndDraw" << std::endl;
};

void SfmlWindow::drawSprite(graphic::ISprite *sprite) {
    SfmlSprite *sfmlsprite = static_cast<SfmlSprite *>(sprite);
    _window.draw(sfmlsprite->_sprite);
};

#endif /* !SFMLWINDOW_HPP_ */