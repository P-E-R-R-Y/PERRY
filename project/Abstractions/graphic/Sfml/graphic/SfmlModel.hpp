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


#ifndef SFMLMODEL_HPP_
#define SFMLMODEL_HPP_

//Interface
#include "../../../interfaces/graphic/graphic/IModel.hpp"

//SFML
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class SfmlModel : public graphic::IModel {

    public:
        SfmlModel() {
            _position = {-1, -1, -1};
            _scale = {1, 1, 1};
        }

        ~SfmlModel() {
        }

        __v3f_t getPosition() const override {
            return {_position.x, _position.y, _position.z};
        }
        void setPosition(__v3f_t position) override {
            _position = {float(position.x), float(position.y), float(position.z)};
        }

        friend class SfmlWindow;

    private:
        sf::Vector3f _position;
        sf::Vector3f _scale;
        //your variables here
};

#endif /* !SFMLMODEL_HPP_ */