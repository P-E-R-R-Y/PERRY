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

#include <vector>
#include <iostream>
#include <utility>
#include <cmath>

///Interface
#include "../../../../interfaces/graphic/window/IWindow.hpp"
#include "../../../../libraries/maths/geometry.hpp"

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
        : _window(sf::VideoMode(screenWidth, screenHeight), title), _event(nullptr), _deltaClock() {
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

        //TIME
        void setFrameLimit(__int32_t limit) override {
            _window.setFramerateLimit(limit);
        };

        __int32_t getDelta() override {
            return static_cast<__int32_t>(_deltaTime.asMilliseconds());
        };

        //DRAW
        void beginDraw() override {
            _window.clear();
        };

        virtual void drawPoly(graphic::IPolygon *polygon) override;
        virtual void drawSprite(graphic::ISprite *sprite) override;

        void endDraw() override {
            _window.display();
            _deltaTime = _deltaClock.restart();
        };

        //Draw3 (Carve)
        void beginMode3(graphic::ICamera *camera) override {
            _sfmlcamera = static_cast<SfmlCamera *>(camera);
        }

        virtual void drawModel(graphic::IModel *model) override {
            if (_sfmlcamera == nullptr) {
                throw std::runtime_error("begginMode3d not called");
            }
            //fov calculus from screen & camera
            sf::Vector3f camPos = _sfmlcamera->_position;
            sf::Vector2u size = this->_window.getSize();
            sf::Vector2u center = sf::Vector2u(size.x / 2, size.y / 2);
            std::cout << "->" << size.x << " " << size.y << std::endl;
            std::cout << "->->" << center.x << " " << center.y << std::endl;
            float fovy = _sfmlcamera->_fovy;
            //camera position & target to calculate the Quaternion
            auto m = static_cast<SfmlModel *>(model);

            std::vector<sf::Vector3f> cube = m->_meshes;

            for (int i = 0; i < cube.size(); i++) {
                cube[i].x -= camPos.x;
                cube[i].y -= camPos.y;
                cube[i].z -= camPos.z;
                std::array<double, 3> c = {cube[i].x, cube[i].y, cube[i].z};
                std::array<double, 3> cr= _sfmlcamera->_quaternion.rotatePoint(c);
                cube[i].x = cr[0];
                cube[i].y = cr[1];
                cube[i].z = cr[2];

                cube[i].x += camPos.x;
                cube[i].y += camPos.y;
                cube[i].z += camPos.z;
            }
            

            float mult = 50;

            sf::CircleShape point(1.0f);  // Radius of 1 to make it a small point
            point.setFillColor(sf::Color::Red);  // Set the color of the point
            point.setPosition(center.x, center.y);  // Set the position of the point
            _window.draw(point);
            
            //draw
            for (int i = 0; i < 4; i++) {
                sf::Vertex line [] = {
                    sf::Vertex(sf::Vector2f(cube[i].x, cube[i].y)),
                    sf::Vertex(sf::Vector2f(cube[(i + 1) % 4].x, cube[(i + 1) % 4].y))
                };
                line[0].position.x = line[0].position.x * mult + center.x;
                line[0].position.y = line[0].position.y * mult + center.y;
                line[1].position.x = line[1].position.x * mult + center.x;
                line[1].position.y = line[1].position.y * mult + center.y;

                _window.draw(line, 2, sf::Lines);
            }
            for (int i = 0; i < 4; i++) {
                sf::Vertex line [] = {
                    sf::Vertex(sf::Vector2f(cube[i].x, cube[i].y)),
                    sf::Vertex(sf::Vector2f(cube[i + 4].x, cube[i + 4].y))
                };
                line[0].position.x = line[0].position.x * mult + center.x;
                line[0].position.y = line[0].position.y * mult + center.y;
                line[1].position.x = line[1].position.x * mult + center.x;
                line[1].position.y = line[1].position.y * mult + center.y;
            
                _window.draw(line, 2, sf::Lines);
            }
            for (int i = 0; i < 4; i++) {
                sf::Vertex line [] = {
                    sf::Vertex(sf::Vector2f(cube[i + 4].x, cube[i + 4].y)),
                    sf::Vertex(sf::Vector2f(cube[((i + 1) % 4) + 4].x, cube[((i + 1) % 4) + 4].y))
                };
                line[0].position.x = line[0].position.x * mult + center.x;
                line[0].position.y = line[0].position.y * mult + center.y;
                line[1].position.x = line[1].position.x * mult + center.x;
                line[1].position.y = line[1].position.y * mult + center.y;
            
                _window.draw(line, 2, sf::Lines);
            }
        }

        void endMode3() override {
        };

        //EVENT
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
        SfmlCamera *_sfmlcamera;

        //time
        sf::Clock _deltaClock;
        sf::Time _deltaTime;
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