/**
 *
 * File: SdlPolygon.hpp
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


#ifndef SDLPOLYGON_HPP_
#define SDLPOLYGON_HPP_

//Interface
#include "../../../Interfaces/graphic3/graphic/IPolygon.hpp"

//Sdl
#include <SDL2/SDL.h>

class SdlPolygon : public graphic3::IPolygon {

    public:
        SdlPolygon(std::vector<__v2f_t> points) {
            _color = {255, 0, 0, 255};
            _position = {0, 0};
            _points = {};
            _triangles = {};
            std::vector<__v2f_t> tmp = {};
            for (auto point : points) {
                _points.push_back(SDL_Vertex{SDL_FPoint{float(point.x), float(point.y)}, SDL_Color{255, 255, 255, 255}, SDL_FPoint{0,0}});
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
                        _triangles.push_back(graphic3::triangle_t{pointA, pointB, pointC});
                        tmp.erase(tmp.begin() + (i+1) % tmp.size());
                    }
                }
            }
            for (int i = 0; i < _triangles.size(); i++) {
                std::cout << "triangle: " << i << " " << _triangles[i].A.x << " " << _triangles[i].A.y << " " << _triangles[i].B.x << " " << _triangles[i].B.y << " " << _triangles[i].C.x << " " << _triangles[i].C.y << std::endl;
            }
            std::cout << "SdlPolygon created" << std::endl;
            std::cout << "SdlPolygon not implemented" << std::endl;
        }

        ~SdlPolygon() {
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
            _color = __color_t{
                static_cast<double>(color.r),
                static_cast<double>(color.g),
                static_cast<double>(color.b),
                static_cast<double>(color.a)};
        }

        std::vector<__v2f_t> getPoints() const override {
            std::vector<__v2f_t> points;
            for (auto point : _points) {
                points.push_back({point.position.x, point.position.y});
            }
            return points;
        }

        friend class SdlWindow;

    private:
        __color_t _color;
        __v2f_t _position;
        std::vector<SDL_Vertex> _points;
        std::vector<graphic3::triangle_t> _triangles;
};

#endif /* !SDLPOLYGON_HPP_ */