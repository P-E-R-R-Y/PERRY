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


#ifndef RAYCAMERA_HPP_
#define RAYCAMERA_HPP_

//Interface
#include "../../../Interfaces/graphic3/window/ICamera.hpp"

//Raylib
#include "../raylib.h"

class RayCamera : public graphic3::ICamera {

    public:
        RayCamera() {
            _camera = { 0 };
            _camera.position = (Vector3){ 1.0f, 1.0f, 1.0f };    // Camera position
            _camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
            _camera.up = (Vector3){ 0.f, 1.0f, 0.f };          // Camera up vector (rotation towards target)
            _camera.fovy = 60.0f;                                // Camera field-of-view Y
            _camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type
            _mode = CAMERA_FIRST_PERSON;
        }

        ~RayCamera() {}

        //f
        float getFov() const override {
            return _camera.fovy;
        }
        void setFov(float fov) override {
            _camera.fovy = fov;
        }
        //m
        ICamera::Mode getMode() const override {
            return ICamera::Mode(_mode);
        }
        void setMode(ICamera::Mode mode) override {
            _mode = CameraMode(mode);
        }
        
        //p
        __v3f_t getPosition() const override {
            return {_camera.position.x, _camera.position.y, _camera.position.z};
        }
        void setPosition(__v3f_t position) override {
            _camera = {float(position.x), float(position.y), float(position.z)};
        }
        
        ICamera::Projection getProjection() const override {
            switch(_camera.projection) {
                case PERSPECTIVE:
                    return ICamera::PERSPECTIVE;
                case CAMERA_ORTHOGRAPHIC:
                    return ICamera::ORTHOGRAPHIC;
            }
            return ICamera::PERSPECTIVE;
        }

        void setProjection(ICamera::Projection projection) override {
            switch(projection) {
                case ICamera::PERSPECTIVE:
                    _camera.projection = CAMERA_PERSPECTIVE;
                case ICamera::ORTHOGRAPHIC:
                    _camera.projection = CAMERA_ORTHOGRAPHIC;
            }
            _camera.projection = projection;
        }

        //t
          __v3f_t getTarget() const override {
            return {_camera.target.x, _camera.target.y, _camera.target.z};
        }
        void setTarget(__v3f_t target) override {
            _camera = {float(target.x), float(target.y), float(target.z)};
        }

        //u
          __v3f_t getUp() const override {
            return {_camera.up.x, _camera.up.y, _camera.up.z};
        }
        void setUp(__v3f_t up) override {
            _camera.up = {float(up.x), float(up.y), float(up.z)};
        }

        friend class RayWindow;

    private:
        Camera _camera;
        CameraMode _mode;
            //your variables here
};

#endif /* !RAYMODEL2_HPP_ */