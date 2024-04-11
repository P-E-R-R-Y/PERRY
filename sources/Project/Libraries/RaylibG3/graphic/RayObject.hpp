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


#ifndef RAYOBJECT_HPP_
#define RAYOBJECT_HPP_

//Interface
#include "../../Interfaces/graphic/IObject.hpp"

//Raylib
#include "../raylib.h"

class RayObject : public graphic3::IObject {

    public:
        RayObject() {
            _position = {0, 0};
            _scale = {1, 1};
        }

        ~RayObject() {
//            UnloadTexture(_texture);
        }

        __v3f_t getPosition() const override {
            return {_position.x, _position.y, _position.z};
        }
        void setPosition(__v3f_t position) override {
            _position = {float(position.x), float(position.y), float(position.z)};
        }

        friend class RayWindow;

    private:
        Vector3 _position;
        Vector3 _scale;
        //your variables here
};

#endif /* !RAYMODEL2_HPP_ */