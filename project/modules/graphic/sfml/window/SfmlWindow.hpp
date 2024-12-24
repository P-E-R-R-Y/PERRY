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

static sf::Vector2f weak_perspective_projection(sf::Vector3f point, float fov) {
    float epsilon = 0.00001f; // Small value to avoid division by zero
    // Weak perspective projection
    return {(fov * point.x / (point.z + fov + epsilon)), 
            (fov * point.y / (point.z + fov + epsilon))};
}

static sf::Vector2f format_to_screen(sf::Vector2f point, sf::Vector2f window_size) {
    return { (window_size.x / 2.0f) + point.x * (window_size.y / 2.0f),
             (window_size.y / 2.0f) - point.y * (window_size.y / 2.0f) };
}

// std::array<double, 3> to sf::vector3f
sf::Vector3f a3tov3(const std::array<double, 3>& point) {
    return sf::Vector3f(static_cast<float>(point[0]),
                        static_cast<float>(point[1]),
                        static_cast<float>(point[2]));
}

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
        void beginMode3(graphic::ICamera *camera) override {
            _sfmlcamera = static_cast<SfmlCamera *>(camera);
        }

        virtual void drawModel(graphic::IModel *model) override {
            if (_sfmlcamera == nullptr) {
                throw std::runtime_error("begginMode3d not called");
            }
            //Window
            sf::Vector2u windowSize = _window.getSize();
            sf::Vector2f windowCenter = sf::Vector2f(static_cast<float>(windowSize.x / 2), static_cast<float>(windowSize.y / 2));
            //Camera
            auto sfmlcamera = _sfmlcamera;
            //Model
            auto sfmlmodel = static_cast<SfmlModel *>(model);

            //!1. Object Space define object position
                //? Position
                auto modelPoints = sfmlmodel->_meshes;
            std::cout << "1" << std::endl;
            //!2. Camera Space 
                //? Position & Rotation
                    for (int i = 0; i < modelPoints.size(); i++) {
                    // sub camera position to point
                        modelPoints[i] = modelPoints[i] - sfmlcamera->_position;
                    // rotate point inversed to camera rotation
                        modelPoints[i] = a3tov3(sfmlcamera->_quaternion.rotatePoint(v3toa3(modelPoints[i])));
                    }
                    // add camera position to point
            std::cout << "2" << std::endl;
            //!3. Projection Space & Format to Screen
                std::vector<sf::Vector2f> projectionPoints;
                for (int i = 0; i < modelPoints.size(); i++) {
                    //? Weak perspective projection (normalized device coordinates)
                    //? Format to screen
                    projectionPoints.push_back(
                        format_to_screen(
                            weak_perspective_projection(modelPoints[i], sfmlcamera->_fovy), 
                                                        {static_cast<float>(windowSize.x), static_cast<float>(windowSize.y)}));
                }
            std::cout << "3" << std::endl;
            //!4. Draw
                //? Draw point
                for (int i = 0; i < projectionPoints.size(); i++) {
                    sf::CircleShape point(1.0f);  // Radius of 1 to make it a small point
                    point.setFillColor(sf::Color::Green);  // Set the color of the point
                    point.setPosition(projectionPoints[i].x, projectionPoints[i].y);  // Set the position of the point
                    std::cout << projectionPoints[i].x << " " << projectionPoints[i].y << std::endl;
                    _window.draw(point);
                }
            //!5 Draw line
                for (int i = 0; i < 4; i++) {
                    sf::Vertex line[] = {
                        sf::Vertex(projectionPoints[i]),
                        sf::Vertex(projectionPoints[((i+1) % 4)])
                    };
                    _window.draw(line, 2, sf::Lines);
                }
                for (int i = 4; i < 8; i++) {
                    sf::Vertex line[] = {
                        sf::Vertex(projectionPoints[i]),
                        sf::Vertex(projectionPoints[((i+1) % 4) + 4])
                    };
                    _window.draw(line, 2, sf::Lines);
                }

                for (int i = 0; i < 4; i++) {
                    sf::Vertex line[] = {
                        sf::Vertex(projectionPoints[i]),
                        sf::Vertex(projectionPoints[i + 4])
                    };
                    _window.draw(line, 2, sf::Lines);
                }

            //sf::CircleShape point(1.0f);  // Radius of 1 to make it a small point
            //point.setFillColor(sf::Color::Red);  // Set the color of the point
            //point.setPosition(windowCenter.x, windowCenter.y);  // Set the position of the point
            //_window.draw(point);
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