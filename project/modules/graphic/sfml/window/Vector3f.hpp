#pragma once

#include <SFML/System/Vector3.hpp>
#include <SFML/System/Vector2.hpp>
#include <cmath> //todo: check if adding this lib for just sqrt is necessary or not (optimization purpose)
#include <stdexcept>

/**
 * @brief cross product of two vectors gives you a new vector that is perpendicular to both input vectors
 * 
 * @param a 
 * @param b 
 * @return sf::Vector3f 
 */
sf::Vector3f crossProduct(sf::Vector3f a, sf::Vector3f b) {
    return {
        a.y * b.z - a.z * b.y, 
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    };
}

/**
 * @brief convert a vector to a unit vector
 * 
 * @param vec 
 * @return sf::Vector3f 
 */
sf::Vector3f normaliseV3f(const sf::Vector3f& vec) {
    float magnitude;

    if (vec.x == 0 && vec.y == 0 && vec.z == 0) {
        return vec;
    }
    magnitude = std::sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
    return {vec.x / magnitude, vec.y / magnitude, vec.z / magnitude};
}

/**
 * @brief give an idea about how much two vectors are aligned
 * - If the dot product is positive, the vectors point in roughly the same direction.
 * - If the dot product is zero, the vectors are perpendicular (at a 90° angle to each other).
 * - If the dot product is negative, the vectors point in opposite directions.
 * 
 * need to normalize the vectors before using the dot product
 * 
 * @param a 
 * @param b 
 * @return float 
 */
float dotProduct(sf::Vector3f a, sf::Vector3f b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

/**
 * @brief viewFromUp will return a view vector based on the up vector
 * 
 * @param up 
 * @return sf::Vector3f 
 */
sf::Vector3f viewFromUp(const sf::Vector3f up) {
    if (up.z == 1) {
        return {0, 1, 0};
    } else {
        return {0, 0, -1};
    }
}

/*sf::Vector2f project(sf::Vector3f point, float fov, sf::Vector2u windowSize) {
    float aspectRatio = windowSize.x / windowSize.y;
    float fovRad = fov * 3.14159265 / 180;
    float tanHalfFov = std::tan(fovRad / 2);
    float z = point.z;
    float x = point.x;
    float y = point.y;

    float xProjected = x / (z * tanHalfFov * aspectRatio);
    float yProjected = y / (z * tanHalfFov);

    return {xProjected, yProjected};
}

template <typename T>
Matrice<T> vtom(const sf::Vector3f& v) {
    return Matrice<T>({
        {v.x},
        {v.y},
        {v.z},
        {1}
    });
}

template <typename T>
sf::Vector2<T> mtoV(const Matrice<T>& m) {
    return {m[0][0] * m[3][0], m[1][0]* m[3][0]};
}*/