/**
 * @file SdlCamera.hpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-29
 * 
 * @addtogroup SDL
 * @{
 */

#ifndef SDLCAMERA_HPP_
#define SDLCAMERA_HPP_

//Interface
#include "../../../../interfaces/graphic/window/ICamera.hpp"

//Sdl
#include <SDL2/SDL.h>

class SdlCamera : public graphic::ICamera {

    public:
        /**
         * @brief Construct a new Sdl Camera object
         */
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

        /**
         * @brief Destroy the Sdl Camera object
         */
        ~SdlCamera() {}

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
            std::cout << "setFov not implemented" << std::endl;
            //_camera.fovy = fov;
        }
        
        /**
         * @brief Get the Mode object
         * 
         * @return ICamera::Mode 
         */
        ICamera::Mode getMode() const override {
            std::cout << "getMode not implemented" << std::endl;
            return ICamera::Mode::CUSTOM;
            //return ICamera::Mode(_mode);
        }

        /**
         * @brief Set the Mode object
         * 
         * @param mode 
         */
        void setMode(ICamera::Mode mode) override {
            std::cout << "setMode not implemented" << std::endl;
        }
        
        /**
         * @brief Get the Position object
         * 
         * @return __v3f_t 
         */
        __v3f_t getPosition() const override {
            std::cout << "getPosition not implemented" << std::endl;
            return {0, 0, 0};
        }

        /**
         * @brief Set the Position object
         * 
         * @param position 
         */
        void setPosition(__v3f_t position) override {
            std::cout << "setPosition not implemented" << std::endl;
            //_camera = {float(position.x), float(position.y), float(position.z)};
        }
        
        /**
         * @brief Get the Projection object
         * 
         * @return ICamera::Projection 
         */
        ICamera::Projection getProjection() const override {
            std::cout << "getProjection not implemented" << std::endl;
            return ICamera::PERSPECTIVE;
        }

        /**
         * @brief Set the Projection object
         * 
         * @param projection 
         */
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

        /**
         * @brief Get the Target object
         * 
         * @return __v3f_t 
         */
        __v3f_t getTarget() const override {
            std::cout << "getTarget not implemented" << std::endl;
            return {0, 0, 0};
            //return {_camera.target.x, _camera.target.y, _camera.target.z};
        }

        /**
         * @brief Set the Target object
         * 
         * @param target 
         */
        void setTarget(__v3f_t target) override {
            std::cout << "setTarget not implemented" << std::endl;
            //_camera = {float(target.x), float(target.y), float(target.z)};
        }

        /**
         * @brief Get the Up object
         * 
         * @return __v3f_t 
         */
        __v3f_t getUp() const override {
            std::cout << "getUp not implemented" << std::endl;
            return {0, 0, 0};
            //return {_camera.up.x, _camera.up.y, _camera.up.z};
        }
        
        /**
         * @brief Set the Up object
         * 
         * @param up 
         */
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