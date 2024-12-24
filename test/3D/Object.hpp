#pragma once

#include <SFML/Graphics.hpp>
#include "Quaternion.hpp"
#include <vector>

class Object {
    public:
        Object(): position({0, 0, 0}), 
          rotation(Quaternion::identity()), 
          vertices({
              {0, 0, 0},
              {1, 0, 0},
          }) {

          }
        
        std::vector<sf::Vector3f> getVertices() {
            return vertices;
        }

        sf::Vector3f getPosition() {
            return position;
        }
        
    private:
        sf::Vector3f position;
        Quaternion rotation;
        std::vector<sf::Vector3f> vertices;
};