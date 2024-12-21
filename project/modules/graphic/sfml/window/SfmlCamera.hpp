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
#include "../../../interfaces/graphic/graphic/Quaternion.hpp"

#include <iostream>
#include <array>
#include <cmath>

class SfmlCamera : public graphic::ICamera {
    private:
        std::array<double, 3> crossProduct(const std::array<double, 3>& A, const std::array<double, 3>& B) {
            return {
                A[1] * B[2] - A[2] * B[1],
                A[2] * B[0] - A[0] * B[2],
                A[0] * B[1] - A[1] * B[0]
            };
        }

        // Function to calculate the normalized direction vector
        std::array<double, 3> calculateDirection(const std::array<double, 3>& position, const std::array<double, 3>& target) {
            std::array<double, 3> direction = {
                target[0] - position[0],
                target[1] - position[1],
                target[2] - position[2]
            };

            // Normalize the direction vector
            double magnitude = std::sqrt(direction[0] * direction[0] +
                                        direction[1] * direction[1] +
                                        direction[2] * direction[2]);
            if (magnitude == 0.0) {
                throw std::invalid_argument("Position and target cannot be the same.");
            }

            return {direction[0] / magnitude, direction[1] / magnitude, direction[2] / magnitude};
        }

        // Function to calculate Euler angles (yaw and pitch)
        std::array<double, 3> calculateEulerAngles(const std::array<double, 3>& direction, const std::array<double, 3>& up = {0, 1, 0}) {
            // Yaw: rotation about the Y-axis
            double yaw = std::atan2(direction[0], direction[2]);

            // Pitch: rotation about the X-axis
            double pitch = std::asin(-direction[1]);

            // Roll: rotation about the Z-axis
             std::array<double, 3> rightVector = crossProduct(up, direction);
            double roll = std::atan2(rightVector[1], rightVector[0]);
            


            return {yaw, pitch, roll};
        }      

    public:
        friend class SfmlWindow;

        SfmlCamera(): _quaternion(0, 0, 0, 0) {
            _position = {0.0f, 2.0f, 1.f };    // Camera position
            _target = { 0.0f, 0.0f, 0.f };      // Camera looking at point
            _up = { 0.f, 1.0f, 0.f };          // Camera up vector (rotation towards target)
            _fovy = 2.0f;                                // Camera field-of-view Y
            _projection = ICamera::ORTHOGRAPHIC;             // Camera projection type
            _mode = ICamera::FIRST_PERSON;
            // Calculate camera direction vector
            const auto tmpDirection = calculateDirection({_position.x, _position.y, _position.z}, {_target.x, _target.y, _target.z});
            _direction = {static_cast<float>(tmpDirection[0]), static_cast<float>(tmpDirection[1]), static_cast<float>(tmpDirection[2])};

            const auto tmpAngle = calculateEulerAngles({_direction.x, _direction.y, _direction.z});
            _eulerAngle = {static_cast<float>(tmpAngle[0] * 180.0f / M_PI), static_cast<float>(tmpAngle[1] * 180.0f / M_PI), static_cast<float>(tmpAngle[2] * 180.0f / M_PI)};
            std::cout << _eulerAngle.x << " " << _eulerAngle.y << " " << _eulerAngle.z << std::endl;
            
            _quaternion = Quaternion::fromEulerAngles(_eulerAngle.x, _eulerAngle.y, 0);
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
            std::cout << "SfmlCamera::getPosition not implemented" << std::endl;
            return {0, 0, 0};
        }
        void setPosition(__v3f_t position) override {
            std::cout << "SfmlCamera::setPosition not implemented" << std::endl;
        }
        
        ICamera::Projection getProjection() const override {
            return ICamera::PERSPECTIVE;
        }

        void setProjection(ICamera::Projection projection) override {
            std::cout << "SfmlCamera::setProjection not implemented" << std::endl;
        }

        //t
          __v3f_t getTarget() const override {
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
        sf::Vector3f _target;
        sf::Vector3f _direction;
        sf::Vector3f _eulerAngle = {0.0f, 0.0f, 0.0f};
        Quaternion _quaternion;
        // upX -> depth: z, vertical: x, horizontal: z
        // upY -> depth: z, vertical y, horizontal: x (default)
        // upZ -> depth: y, vertical: z, horizontal: x
        sf::Vector3f _up;
        float _fovy;
        ICamera::Projection _projection;
        ICamera::Mode _mode;
            //your variables here
};

#endif /* !RAYMODEL2_HPP_ */