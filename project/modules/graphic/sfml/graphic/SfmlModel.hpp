/**
 * @file SfmlModel.hpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-29
 * 
 * @addtogroup SFML
 * @{
 */

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

/**
 * @brief Sfml Model class 
 */
class SfmlModel : public graphic::IModel {

    public:

        /**
         * @brief Construct a new Sfml Model object
         */
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

        /**
         * @brief Destroy the Sfml Model object
         */
        ~SfmlModel() {
        }

        /**
         * @brief Get the Position object
         * 
         * @return __v3f_t 
         */
        __v3f_t getPosition() const override {
            return {position.x, position.y, position.z};
        }

        /**
         * @brief Set the Position object
         * 
         * @param pos 
         */
        void setPosition(__v3f_t pos) override {
            position = {float(pos.x), float(pos.y), float(pos.z)};
        }
        
        /**
         * @brief Get the Vertices object
         * 
         * @return std::vector<sf::Vector3f> 
         */
        std::vector<sf::Vector3f> getVertices() {
            return vertices;
        }

    protected:

        /**
         * @brief rotate will rotate the model
         * 
         * @param angle 
         * @param center 
         */
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