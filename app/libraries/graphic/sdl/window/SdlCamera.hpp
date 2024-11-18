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


#ifndef SDLCAMERA_HPP_
#define SDLCAMERA_HPP_

//Interface
#include "../../../../interfaces/graphic/window/ICamera.hpp"

//Sdl
#include <SDL2/SDL.h>

class SdlCamera : public graphic::ICamera {

    public:
        SdlCamera() {
            std::cout << "SdlCamera not implemented" << std::endl;
            //_camera = { 0 };
            //_camera.position = (Vector3){ 1.0f, 1.0f, 1.0f };    // Camera position
            //_camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
            //_camera.up = (Vector3){ 0.f, 1.0f, 0.f };          // Camera up vector (rotation towards target)
            //_camera.fovy = 60.0f;                                // Camera field-of-view Y
            //_camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type
            //_mode = CAMERA_FIRST_PERSON;
        }

        ~SdlCamera() {}

        //f
        float getFov() const override {
            return 0;
        }
        void setFov(float fov) override {
            std::cout << "setFov not implemented" << std::endl;
            //_camera.fovy = fov;
        }
        //m
        ICamera::Mode getMode() const override {
            std::cout << "getMode not implemented" << std::endl;
            return ICamera::Mode::CUSTOM;
            //return ICamera::Mode(_mode);
        }
        void setMode(ICamera::Mode mode) override {
            std::cout << "setMode not implemented" << std::endl;
        }
        
        //p
        __v3f_t getPosition() const override {
            std::cout << "getPosition not implemented" << std::endl;
            return {0, 0, 0};
        }
        void setPosition(__v3f_t position) override {
            std::cout << "setPosition not implemented" << std::endl;
            //_camera = {float(position.x), float(position.y), float(position.z)};
        }
        
        ICamera::Projection getProjection() const override {
            std::cout << "getProjection not implemented" << std::endl;
            return ICamera::PERSPECTIVE;

            //switch(_camera.projection) {
            //    case PERSPECTIVE:
            //        return ICamera::PERSPECTIVE;
            //    case CAMERA_ORTHOGRAPHIC:
            //        return ICamera::ORTHOGRAPHIC;
            //}
        }

        void setProjection(ICamera::Projection projection) override {
            std::cout << "setProjection not implemented" << std::endl;
//            switch(projection) {
//                case ICamera::PERSPECTIVE:
//                    _camera.projection = CAMERA_PERSPECTIVE;
//                case ICamera::ORTHOGRAPHIC:
//                    _camera.projection = CAMERA_ORTHOGRAPHIC;
//            }
//            _camera.projection = projection;
        }

        //t
          __v3f_t getTarget() const override {
            std::cout << "getTarget not implemented" << std::endl;
            return {0, 0, 0};
            //return {_camera.target.x, _camera.target.y, _camera.target.z};
        }
        void setTarget(__v3f_t target) override {
            std::cout << "setTarget not implemented" << std::endl;
            //_camera = {float(target.x), float(target.y), float(target.z)};
        }

        //u
          __v3f_t getUp() const override {
            std::cout << "getUp not implemented" << std::endl;
            return {0, 0, 0};
            //return {_camera.up.x, _camera.up.y, _camera.up.z};
        }
        
        void setUp(__v3f_t up) override {
            std::cout << "setUp not implemented" << std::endl;
            //_camera.up = {float(up.x), float(up.y), float(up.z)};
        }

        friend class SdlWindow;

    private:
//        Camera _camera;
//        CameraMode _mode;
            //your variables here
};

#endif /* !SDLMODEL2_HPP_ */