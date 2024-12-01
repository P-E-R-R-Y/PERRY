/**
 *
 * File: ICamera.hpp
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
    

#ifndef ICAMERA_HPP_
    #define ICAMERA_HPP_
    #include "../../../libraries/system/type.hpp"
    #include "IWindow.hpp"

class Module {

};

namespace graphic {

    class ICamera : public Module {

        public:
            typedef enum{
                PERSPECTIVE,
                ORTHOGRAPHIC
            } Projection;

            typedef enum {
                CUSTOM = 0,              // Custom camera
                FREE,                    // Free camera
                ORBITAL,                 // Orbital camera
                FIRST_PERSON,            // First person camera
                THIRD_PERSON             // Third person camera
            } Mode;

            //constructor
            virtual ~ICamera() = default;
            //f
            virtual float getFov() const = 0;
            virtual void setFov(float fov) = 0;

            //m
            virtual Mode getMode() const = 0;
            virtual void setMode(Mode mode) = 0;

            //p
            virtual __v3f_t getPosition() const = 0;
            virtual void setPosition(__v3f_t position) = 0;

            virtual Projection getProjection() const = 0;
            virtual void setProjection(Projection projection) = 0;
            //t
            virtual __v3f_t getTarget() const = 0;
            virtual void setTarget(__v3f_t size) = 0;
            //u
            virtual __v3f_t getUp() const = 0;
            virtual void setUp(__v3f_t up) = 0;

        private:
            //your variables here
    };

} // namespace graphic3

#endif /* !ICAMERA_HPP */