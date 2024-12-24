#pragma once

#include <SFML/Graphics.hpp>
#include "Quaternion.hpp"
#include "Vector3f.hpp"
#include "Matrice.hpp"

class Camera {
    public:
        Camera(sf::Vector3f pos = {0, 0, 0}, sf::Vector3f target = {0, 0, -1}, float fov = 90) : position(pos), up({0, 1, 0}), fov(fov) {
            sf::Vector3f usual = {0, 0, -1};
            sf::Vector3f direction = normalize(target - position);

            quaternion = Quaternion::fromVectors(usual, direction);
        }

        sf::Vector3f getPosition() const {
            return position;
        }

        Quaternion getQuaternion() const {
            return quaternion;
        }

        Quaternion getConjugate() const {
            return quaternion.conjugate();
        }

        float getFov() const {
            return fov;
        }

    private:
        sf::Vector3f position;
        sf::Vector3f up;
        Quaternion quaternion;
        float fov;
};

template <typename T>
Matrice<T> perspectiveProjection(T fov, T aspectRatio) {
    // Convert FOV from degrees to radians
    T fovRad = fov * M_PI / 180.0;
    T nearPlane = 0.001;
    T farPlane = 1000.0;

    // Create the perspective projection matrix
    std::vector<std::vector<T>> proj = {{
        {1.0f / (aspectRatio * tan(fovRad / 2.f)), 0.f, 0.f, 0.f},
        {0.f, 1.f / tan(fovRad / 2.f), 0.f, 0.f},
        {0.f, 0.f, (farPlane + nearPlane) / (nearPlane - farPlane), (2 * farPlane * nearPlane) / (nearPlane - farPlane)},
        {0.f, 0.f, -1.f, 0.f}
    }};

    return Matrice<T>(proj);
}

/*template <typename T>
Matrice<T> orthographicProjection(T left, T right, T bottom, T top, T nearPlane, T farPlane) {
    // Create the orthographic projection matrix
    std::array<std::array<T, 4>, 4> proj = {{
        {2.0 / (right - left), 0, 0, -(right + left) / (right - left)},
        {0, 2.0 / (top - bottom), 0, -(top + bottom) / (top - bottom)},
        {0, 0, -2.0 / (farPlane - nearPlane), -(farPlane + nearPlane) / (farPlane - nearPlane)},
        {0, 0, 0, 1}
    }};

    return Matrice<T>(proj);
}*/

/**
 *  Up vector: (0, 1, 0)
 * 
 * • View vector: (0, 0, -1)
 * • Right vector: (0, -1, 0)
 * • Up vector: (1, 0, 0)
 *
 * 
 * Up vector: (0, 1, 0)
 * 
 * • View vector: (0, 0, -1)
 * • Right vector: (1, 0, 0)
 * • Up vector: (0, 1, 0)
 *
 * 
 * Up vector: (0, 0, 1)
 * 
 * • View vector: (0, 0, -1)
 * • Right vector: (1, 0, 0)
 * • Up vector: (0, 1, 0)
 */
