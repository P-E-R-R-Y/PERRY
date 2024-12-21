#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <chrono>
#include <thread>

#include "Quaternion.hpp"

class Camera {
    public:
        Camera(sf::Vector3f position, sf::Vector3f target, int fov = 60):
          position(position), 
          target(target), 
          fov(fov),
          direction(target - position),
          rotation(Quaternion::fromVector({direction.x, direction.y, direction.z}))
        { }

        sf::Vector3f position;
        sf::Vector3f target;
        int fov;
        sf::Vector3f up = {0, 1, 0};
        sf::Vector3f direction;

        Quaternion rotation;

}