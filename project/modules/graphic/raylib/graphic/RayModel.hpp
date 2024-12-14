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


#ifndef RAYMODEL_HPP_
#define RAYMODEL_HPP_

//Interface
#include "../../../../interfaces/graphic/graphic/IModel.hpp"

//Raylib
#include <raylib.h>

class RayModel : public graphic::IModel {

    public:
        RayModel() {
            _position = {0, 0, 0};
            _size = {1, 1, 1};
        }

        ~RayModel() = default;

        __v3f_t getPosition() const override {
            return {_position.x, _position.y, _position.z};
        }

        void setPosition(__v3f_t position) override {
            _position = {float(position.x), float(position.y), float(position.z)};
        }

        friend class RayWindow;

    private:
        Vector3 _position;
        Vector3 _size;
};

#endif /* !RAYMODEL_HPP_ */