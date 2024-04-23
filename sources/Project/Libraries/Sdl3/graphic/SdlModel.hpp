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


#ifndef SDLMODEL_HPP_
#define SDLMODEL_HPP_

//Interface
#include "../../../Interfaces/graphic3/graphic/IModel.hpp"

//Sdl

class SdlModel : public graphic3::IModel {

    public:
        SdlModel() {
            std::cout << "SdlModel::SdlModel not implemented" << std::endl;
            //_position = {-1, -1, -1};
            //_scale = {1, 1, 1};
        }

        ~SdlModel() {
        }

        __v3f_t getPosition() const override {
            std::cout << "SdlModel::getPosition not implemented" << std::endl;
            return {0, 0, 0};
            //return {_position.x, _position.y, _position.z};
        }
        void setPosition(__v3f_t position) override {
            std::cout << "SdlModel::setPosition not implemented" << std::endl;
            //_position = {float(position.x), float(position.y), float(position.z)};
        }

        friend class SdlWindow;

    private:
        //Vector3 _position;
        //Vector3 _scale;
        //your variables here
};

#endif /* !SDLMODEL_HPP_ */