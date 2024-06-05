/**
 *
 * File: RayModel2.hpp
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


#ifndef SFMLPOLYGON_HPP_
#define SFMLPOLYGON_HPP_

//Interface
#include "../../../Interfaces/graphic/graphic/IPolygon.hpp"

//Sfml
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class SfmlPolygon : public graphic::IPolygon {

    public:
        SfmlPolygon(std::vector<__v2f_t> points) {
            _color = sf::Color{255, 0, 0, 255};
            _position = {0, 0};
            _points = {};
            _triangles = {};
            std::vector<__v2f_t> tmp = {};

            for (auto point : points) {
                _points.push_back(sf::Vertex(sf::Vector2f{float(point.x), float(point.y)}, _color));
                tmp.push_back(__v2f_t{double(point.x), double(point.y)});
            }
            for (int i = 0; tmp.size() >= 3; i++) {
                std::cout << i << " " << tmp.size() << std::endl;
                __v2f_t pointA = tmp[i % tmp.size()];
                __v2f_t pointB = tmp[(i+1) % tmp.size()];
                __v2f_t pointC = tmp[(i+2) % tmp.size()];
            
                if (is_convex(pointA, pointB, pointC)) {
                    bool isEar = true;

                    for (int j = 0; j < tmp.size(); j++) {
                        if (j == i % tmp.size() || j == (i+1) % tmp.size() || j == (i+2) % tmp.size()) {
                            continue;
                        }
                        if (is_inside_triangle(tmp[j], pointA, pointB, pointC)) {
                            isEar = false;
                            break;
                        }
                    }
                    if (isEar) {
                        std::cout << "ear" << std::endl;
                        _triangles.push_back(graphic::triangle_t{pointA, pointB, pointC});
                        tmp.erase(tmp.begin() + (i+1) % tmp.size());
                    }
                }
            }
            for (int i = 0; i < _triangles.size(); i++) {
                std::cout << "triangle: " << i << " " << _triangles[i].A.x << " " << _triangles[i].A.y << " " << _triangles[i].B.x << " " << _triangles[i].B.y << " " << _triangles[i].C.x << " " << _triangles[i].C.y << std::endl;
            }
            std::cout << "SfmlPolygon created" << std::endl;
        }

        ~SfmlPolygon() {
        }

        bool isReady() const override {
            return true;
        }

        __v2f_t getPosition() const override {
            return {_position.x, _position.y};
        }
        void setPosition(__v2f_t position) override {
            _position = {float(position.x), float(position.y)};
        }

        __color_t getColor() const override {
            return __color_t{
                static_cast<double>(_color.r),
                static_cast<double>(_color.g),
                static_cast<double>(_color.b),
                static_cast<double>(_color.a)};
        }

        void setColor(__color_t color) override {
            _color = sf::Color{
                static_cast<unsigned char>(color.r),
                static_cast<unsigned char>(color.g),
                static_cast<unsigned char>(color.b),
                static_cast<unsigned char>(color.a)};
        }

        std::vector<__v2f_t> getPoints() const override {
            std::vector<__v2f_t> points;
            for (auto point : _points) {
                points.push_back({point.position.x, point.position.y});
            }
            return points;
        }

        friend class SfmlWindow;

    private:
        sf::Color _color;
        sf::Vector2f _position;
        std::vector<sf::Vertex> _points;
        std::vector<graphic::triangle_t> _triangles;
};

#endif /* !SFMLPOLYGON_HPP_ */