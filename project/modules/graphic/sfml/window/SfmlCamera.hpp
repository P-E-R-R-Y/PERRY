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

class SfmlCamera : public graphic::ICamera {
    public:
        friend class SfmlWindow;

        SfmlCamera() {
            _position = {1.0f, 1.0f, 1.0f };    // Camera position
            _target = { 0.0f, 0.0f, 0.0f };      // Camera looking at point
            _up = { 0.f, 1.0f, 0.f };          // Camera up vector (rotation towards target)
            _fovy = 60.0f;                                // Camera field-of-view Y
            _projection = ICamera::PERSPECTIVE;             // Camera projection type
            _mode = ICamera::FIRST_PERSON;

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
        __v3f_t _position;
        __v3f_t _target;
        __v3f_t _up;
        float _fovy;
        ICamera::Projection _projection;
        ICamera::Mode _mode;
            //your variables here
};

#endif /* !RAYMODEL2_HPP_ */