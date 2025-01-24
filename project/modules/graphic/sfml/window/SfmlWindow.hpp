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

//sf::vector3f to std::array<double, 3>
std::array<double, 3> v3toa3(sf::Vector3f point) {
    return {static_cast<double>(point.x),
            static_cast<double>(point.y),
            static_cast<double>(point.z)};
}

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
        void beginMode3(graphic::ICamera *cam) override {
            if (_camera == nullptr && cam != nullptr) {
                _camera = static_cast<SfmlCamera *>(cam);
            }
        }

        void drawPoint(const sf::Vector3f& point) {

            //!make the camera the origin
            sf::Vector3f relativePosition = point - _camera->_position;

            std::cout << "relativePosition: " << relativePosition.x << " " << relativePosition.y << " " << relativePosition.z << std::endl;

            //!rotate the object
            sf::Vector3f relativeRotatedPosition = _camera->_quaternion.conjugate().rotate(relativePosition);

            if (relativeRotatedPosition.z >= 0) {
                return; //skip drawing points that are behind the camera
            }

            //Don't need to move the object back to its original position because the camera is the origin for perspective projection
            sf::Vector3f rotatedPosition = relativeRotatedPosition;
            std::cout << "points: " << rotatedPosition.x << " " << rotatedPosition.y << " " << rotatedPosition.z << std::endl;
            //!perspective projection
            sf::Vector2f screen = _window.getView().getSize();

            Matrice<float> projection = perspectiveProjection<float>(_camera->_fov, screen.x / screen.y);
            Matrice<float> vtom = Matrice<float>({{rotatedPosition.x}, {rotatedPosition.y}, {rotatedPosition.z}, {1.f}});
            Matrice<float> res = projection * vtom;
            //!homogeneous division// convert to normalized device coordinates
            float x_ndc = res(0, 0) / res(3, 0);
            float y_ndc = res(1, 0) / res(3, 0);

            if (x_ndc < -1 || x_ndc > 1 || y_ndc < -1 || y_ndc > 1) {
                return; //skip drawing points that are outside the screen
            }

            //NDC to screen coordinates
            float screenX = (x_ndc + 1.0f) * 0.5f * screen.x;
            float screenY = (1.0f - y_ndc) * 0.5f * screen.y;
            
            // Draw the point
            sf::CircleShape circle(1);
            circle.setPosition(screenX, screenY);
            circle.setFillColor(sf::Color::White);
            circle.setOutlineColor(sf::Color::White);
            circle.setOutlineThickness(1);
            _window.draw(circle);

            return;
        }

        void drawModel(graphic::IModel *model) override {
            if (_camera == nullptr) {
                throw std::runtime_error("begginMode3d not called");
            }

            SfmlModel *sfmlModel = static_cast<SfmlModel *>(model);

            for (sf::Vector3f point : sfmlModel->vertices) {
                std::cout << ">>>" << point.x << " " << point.y << " " << point.z << std::endl;
                drawPoint(point);

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
        SfmlCamera *_camera;

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