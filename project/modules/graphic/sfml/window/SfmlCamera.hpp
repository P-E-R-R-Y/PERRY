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


#ifndef SFMLCAMERA_HPP_
#define SFMLCAMERA_HPP_

//Interface
#include "../../../../interfaces/graphic/window/ICamera.hpp"

#include "../../../../libraries/system/type.hpp"
#include "./Quaternion.hpp"
#include "./Matrice.hpp"

#include <iostream>
#include <array>
#include <cmath>

class SfmlCamera : public graphic::ICamera {
    private:


    public:
        friend class SfmlWindow;

        SfmlCamera(sf::Vector3f pos = {0.f, 0.0f, 0.0f}, sf::Vector3f target = {0, 0, -1}, float fov = 90) : _position(pos), _up({0, 1, 0}), _fov(fov) {
            sf::Vector3f usual = {0, 0, -1};
            sf::Vector3f direction = normaliseV3f(target - _position);
            _projection = Projection::PERSPECTIVE;             // Camera projection type

            _quaternion = Quaternion::fromVectors(usual, direction);
        }

        ~SfmlCamera() {}

        //f
        float getFov() const override {
            return 0;
        }

        void setFov(float fov) override {
            std::cout << "SfmlCamera::setFov not implemented" << std::endl;
        }

        //m
        ICamera::Mode getMode() const override {
            return ICamera::Mode::FIRST_PERSON;
        }

        void setMode(ICamera::Mode mode) override {
            std::cout << "SfmlCamera::setMode not implemented" << std::endl;
        }
        
        //p
        __v3f_t getPosition() const override {
            return {_position.x, _position.y, _position.z};
        }

        void setPosition(__v3f_t position) override {
            _position = {float(position.x), float(position.y), float(position.z)};
        }
        
        ICamera::Projection getProjection() const override {
            return ICamera::PERSPECTIVE;
        }

        void setProjection(ICamera::Projection projection) override {
            std::cout << "SfmlCamera::setProjection not implemented" << std::endl;
        }

        //t
          __v3f_t getTarget() const override {
            std::cout << "SfmlCamera::getTarget not implemented" << std::endl;
            return {0, 0, 0};
        }
        void setTarget(__v3f_t target) override {
            std::cout << "SfmlCamera::setTarget not implemented" << std::endl;
        }

        //u
          __v3f_t getUp() const override {
            return {0, 0, 0};
        }
        void setUp(__v3f_t up) override {
            std::cout << "SfmlCamera::setUp not implemented" << std::endl;
        }

        friend class SfmlWindow;

    protected:
        sf::Vector3f _position;
        sf::Vector3f _up;
        Quaternion _quaternion;
        Projection _projection;
        Mode _mode;
        float _fov;
};


template <typename T>
Matrice<T> perspectiveProjection(T fov, T aspectRatio) {
    // Convert FOV from degrees to radians
    T fovRad = fov * M_PI / 180.0;
    T nearPlane = 0.001;
    T farPlane = 1000.0;

    // Create the perspective projection matrix
    std::vector<std::vector<T>> proj = {{
        {1.0f / (aspectRatio * tan(fovRad / 2.f)), 0.f, 0.f, 0.f},
        {0.f, 1.f / tan(fovRad / 2.f), 0.f, 0.f},
        {0.f, 0.f, (farPlane + nearPlane) / (nearPlane - farPlane), (2 * farPlane * nearPlane) / (nearPlane - farPlane)},
        {0.f, 0.f, -1.f, 0.f}
    }};

    return Matrice<T>(proj);
}

template <typename T>
Matrice<T> orthographicProjection(T left, T right, T bottom, T top, T nearPlane, T farPlane) {
    // Create the orthographic projection matrix
    std::array<std::array<T, 4>, 4> proj = {{
        {2.0 / (right - left), 0, 0, -(right + left) / (right - left)},
        {0, 2.0 / (top - bottom), 0, -(top + bottom) / (top - bottom)},
        {0, 0, -2.0 / (farPlane - nearPlane), -(farPlane + nearPlane) / (farPlane - nearPlane)},
        {0, 0, 0, 1}
    }};

    return Matrice<T>(proj);
}

#endif /* !RAYMODEL2_HPP_ */