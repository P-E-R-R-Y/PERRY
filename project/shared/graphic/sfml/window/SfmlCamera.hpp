/**
 * @file SfmlCamera.hpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-29
 * 
 * @addtogroup SFML
 * @{
 */

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

        /**
         * @brief Construct a new Sfml Camera object
         *
         * @param pos 
         * @param target 
         * @param fov 
         */
        SfmlCamera(sf::Vector3f pos = {0.f, 0.0f, 0.0f}, sf::Vector3f target = {0, 0, -1}, float fov = 90) : _position(pos), _up({0, 1, 0}), _fov(fov) {
            sf::Vector3f usual = {0, 0, -1};
            sf::Vector3f direction = normaliseV3f(target - _position);
            _projection = Projection::PERSPECTIVE;             // Camera projection type

            _quaternion = Quaternion::fromVectors(usual, direction);
        }

        /**
         * @brief Destroy the Sfml Camera object
         */
        ~SfmlCamera() {}

        /**
         * @brief Get the Fov object
         * 
         * @return float 
         */
        float getFov() const override {
            return 0;
        }

        /**
         * @brief Set the Fov object
         * 
         * @param fov 
         */
        void setFov(float fov) override {
            std::cout << "SfmlCamera::setFov not implemented" << std::endl;
        }

        /**
         * @brief Get the Mode object
         * 
         * @return ICamera::Mode 
         */
        ICamera::Mode getMode() const override {
            return ICamera::Mode::FIRST_PERSON;
        }

        /**
         * @brief Set the Mode object
         * 
         * @param mode 
         */
        void setMode(ICamera::Mode mode) override {
            std::cout << "SfmlCamera::setMode not implemented" << std::endl;
        }
        
        /**
         * @brief Get the Position object
         * 
         * @return __v3f_t 
         */
        __v3f_t getPosition() const override {
            return {_position.x, _position.y, _position.z};
        }

        /**
         * @brief Set the Position object
         * 
         * @param position 
         */
        void setPosition(__v3f_t position) override {
            _position = {float(position.x), float(position.y), float(position.z)};
        }

        /**
         * @brief Get the Projection object
         * 
         * @return ICamera::Projection 
         */
        ICamera::Projection getProjection() const override {
            return ICamera::PERSPECTIVE;
        }

        /**
         * @brief Set the Projection object
         * 
         * @param projection 
         */
        void setProjection(ICamera::Projection projection) override {
            std::cout << "SfmlCamera::setProjection not implemented" << std::endl;
        }

        /**
         * @brief Get the Target object
         * 
         * @return __v3f_t 
         */
        __v3f_t getTarget() const override {
            std::cout << "SfmlCamera::getTarget not implemented" << std::endl;
            return {0, 0, 0};
        }

        /**
         * @brief Set the Target object
         * 
         * @param target 
         */
        void setTarget(__v3f_t target) override {
            std::cout << "SfmlCamera::setTarget not implemented" << std::endl;
        }

        /**
         * @brief Get the Up object
         * 
         * @return __v3f_t 
         */
        __v3f_t getUp() const override {
            return {0, 0, 0};
        }

        /**
         * @brief Set the Up object
         * 
         * @param up 
         */
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


/**
 * @brief perspectiveProjection will create a perspective projection matrix
 * 
 * @tparam T 
 * @param fov 
 * @param aspectRatio 
 * @return Matrice<T> 
 */
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

/**
 * @brief orthographicProjection will create an orthographic projection matrix
 * 
 * @tparam T 
 * @param left 
 * @param right 
 * @param bottom 
 * @param top 
 * @param nearPlane 
 * @param farPlane 
 * @return Matrice<T> 
 */
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