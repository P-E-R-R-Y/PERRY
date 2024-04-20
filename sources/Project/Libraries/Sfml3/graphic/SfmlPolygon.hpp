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
#include "../../../Interfaces/graphic3/graphic/IPolygon.hpp"

//Sfml
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

typedef struct triangle_s {
    __v2f_t A;
    __v2f_t B;
    __v2f_t C;
} triangle_t;

class SfmlPolygon : public graphic3::IPolygon {

    public:
        SfmlPolygon(std::vector<__v2f_t> points) {
            _color = sf::Color{255, 0, 0, 255};
            _position = {0, 0};
            _points = {};

            for (auto point : points) {
                _points.push_back(sf::Vertex(sf::Vector2f{float(point.x), float(point.y)}, _color));
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

};

#endif /* !SFMLPOLYGON_HPP_ */