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

//Encapsulation
#include "../window/Quaternion.hpp"

class SfmlModel : public graphic::IModel {

    public:
        SfmlModel():
            position({0, 0, 0}),
            rotation(Quaternion::identity()),
            vertices({
              {-0.5, -0.5, 0.5},
              {-0.5, -0.5, -0.5},
              {-0.5, 0.5, 0.5},
              {-0.5, 0.5, -0.5},
              {0.5, -0.5, 0.5},
              {0.5, -0.5, -0.5},
              {0.5, 0.5, 0.5},
              {0.5, 0.5, -0.5},
            }) {

        }

        ~SfmlModel() {
        }

        __v3f_t getPosition() const override {
            return {position.x, position.y, position.z};
        }
        void setPosition(__v3f_t pos) override {
            position = {float(pos.x), float(pos.y), float(pos.z)};
        }
        
        std::vector<sf::Vector3f> getVertices() {
            return vertices;
        }

    protected:
        void rotate(sf::Vector3f angle, sf::Vector3f center = {0, 0, 0}) {
            std::cout << "SfmlModel::rotate not implemented" << std::endl;
        }

        sf::Vector3f position;
        Quaternion rotation;
        std::vector<sf::Vector3f> vertices;
        //your variables here
    public:
        friend class SfmlWindow;
        friend class SfmlCamera;
};

#endif /* !SFMLMODEL_HPP_ */