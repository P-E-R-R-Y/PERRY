/**
 *
 * File: RayModel3.hpp
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


#ifndef RAYMODEL3_HPP_
#define RAYMODEL3_HPP_

//Interface
#include "../../../Interfaces/graphic3/graphic/IModel3.hpp"

//Raylib
#include "../raylib.h"

class RayModel3 : public graphic3::IModel3 {

    public:
        RayModel3() {
            _position = {-1, -1, -1};
            _scale = {0.5, 0.5, 0.5};
        }

        ~RayModel3() {
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