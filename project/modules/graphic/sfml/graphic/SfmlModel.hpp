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
#include "../../../interfaces/graphic/graphic/Quaternion.hpp"

//SFML
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class SfmlModel : public graphic::IModel {

    public:
        SfmlModel() {
            _position = {0, 0, 0};
            _size = {1, 1, 1};
            sf::Vector3f half = _size * 0.5f;
            _meshes = {
                sf::Vector3f(-half.x, half.y, half.z), // left top back
                sf::Vector3f(half.x, half.y, half.z), // right top back
                sf::Vector3f(half.x, -half.y, half.z), // right bottom back
                sf::Vector3f(-half.x, -half.y, half.z), // left bottom back
                //
                sf::Vector3f(-half.x, half.y, -half.z), // left top front
                sf::Vector3f(half.x, half.y, -half.z), // right top front
                sf::Vector3f(half.x, -half.y, -half.z), // right bottom front
                sf::Vector3f(-half.x, -half.y, -half.z), // left bottom front
            };
        }

        ~SfmlModel() {
        }

        __v3f_t getPosition() const override {
            return {_position.x, _position.y, _position.z};
        }
        void setPosition(__v3f_t position) override {
            _position = {float(position.x), float(position.y), float(position.z)};
        }

    protected:
        void rotate(sf::Vector3f angle, sf::Vector3f center = {0, 0, 0}) {
            for (int i = 0; i < _meshes.size(); i++) {
                std::array<double, 3> p = {_meshes[i].x, _meshes[i].y, _meshes[i].z};
                std::array<double, 3> a = {angle.x, angle.y, angle.z};
                std::array<double, 3> cor = {center.x, center.y, center.z};
                std::array<double, 3> result = Quaternion::rotate(p, a, cor);
                _meshes[i].x = result[0];
                _meshes[i].y = result[1];
                _meshes[i].z = result[2];
            }
        }
        
        sf::Vector3f _position;
        sf::Vector3f _size;
        std::vector<sf::Vector3f> _meshes;
        //your variables here
    public:
        friend class SfmlWindow;
        friend class SfmlCamera;
};

#endif /* !SFMLMODEL_HPP_ */