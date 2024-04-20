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


#ifndef RAYPOLYGON_HPP_
#define RAYPOLYGON_HPP_

//Interface
#include "../../../Interfaces/graphic3/graphic/IPolygon.hpp"

//Raylib
#include <raylib.h>

typedef struct triangle_s {
    __v2f_t A;
    __v2f_t B;
    __v2f_t C;
} triangle_t;

class RayPolygon : public graphic3::IPolygon {

    public:
        RayPolygon(std::vector<__v2f_t> points) {
            _color = Color{255, 0, 0, 255};
            _position = {0, 0};
            _points = {};
            _triangles = {};
            std::vector<__v2f_t> tmp = {};
            for (auto point : points) {
                _points.push_back(Vector2{float(point.x), float(point.y)});
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
                        _triangles.push_back(triangle_t{pointA, pointB, pointC});
                        tmp.erase(tmp.begin() + (i+1) % tmp.size());
                    }
                }
            }
            for (int i = 0; i < _triangles.size(); i++) {
                std::cout << "triangle: " << i << " " << _triangles[i].A.x << " " << _triangles[i].A.y << " " << _triangles[i].B.x << " " << _triangles[i].B.y << " " << _triangles[i].C.x << " " << _triangles[i].C.y << std::endl;
            }
            std::cout << "RayPolygon created" << std::endl;
        }

        ~RayPolygon() {
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
            _color = Color{
                static_cast<unsigned char>(color.r),
                static_cast<unsigned char>(color.g),
                static_cast<unsigned char>(color.b),
                static_cast<unsigned char>(color.a)};
        }

        std::vector<__v2f_t> getPoints() const override {
            std::vector<__v2f_t> points;
            for (auto point : _points) {
                points.push_back({point.x, point.y});
            }
            return points;
        }

        friend class RayWindow;

    private:
        Color _color;
        Vector2 _position;
        std::vector<Vector2> _points;
        std::vector<triangle_t> _triangles;

};

#endif /* !RAYPOLYGON_HPP_ */