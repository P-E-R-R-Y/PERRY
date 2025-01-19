#pragma once

#include <SFML/Graphics.hpp>
#include "Vector3f.hpp"

class Quaternion {
    public:
        Quaternion(): w(1), x(0), y(0), z(0) {}
 
        Quaternion(float w, float x, float y, float z) : w(w), x(x), y(y), z(z) {}
        ~Quaternion() {}

        static Quaternion identity() {
            return Quaternion(1, 0, 0, 0);
        }

        static Quaternion fromEulerAngles(float x, float y, float z) {
            Quaternion q;
            sf::Vector3f half = {x / 2, y / 2, z / 2};

            q.w = std::cos(half.x) * std::cos(half.y) * std::cos(half.z) + std::sin(half.x) * std::sin(half.y) * std::sin(half.z);
            q.x = std::sin(half.x) * std::cos(half.y) * std::cos(half.z) - std::cos(half.x) * std::sin(half.y) * std::sin(half.z);
            q.y = std::cos(half.x) * std::sin(half.y) * std::cos(half.z) + std::sin(half.x) * std::cos(half.y) * std::sin(half.z);
            q.z = std::cos(half.x) * std::cos(half.y) * std::sin(half.z) - std::sin(half.x) * std::sin(half.y) * std::cos(half.z);
            return q;
        }

        /**
         * @brief fromAxisAngle will create a quaternion from an axis and an angle
         * 
         * @param angle 
         * @param axis 
         * @return Quaternion 
         */
        static Quaternion fromAxisAngle(float angle, sf::Vector3f axis) {
            Quaternion q;
            float half = angle / 2; 

            q.w = std::cos(half);
            q.x = axis.x * std::sin(half);
            q.y = axis.y * std::sin(half);
            q.z = axis.z * std::sin(half);
            return q;
        }

        /**
         * @brief quaterninon representing the rotation from one vector to another
         * 
         * @param v1
         * @param v2
         * @return Quaternion
         */
        static Quaternion fromVectors(const sf::Vector3f& v1, const sf::Vector3f& v2) {
            // Normalize the vectors
            sf::Vector3f u1 = normaliseV3f(v1);
            sf::Vector3f u2 = normaliseV3f(v2);

            // give 
            float dot = dotProduct(u1, u2);

            // Compute the axis of rotation (cross product) get axis of rotation
            sf::Vector3f axis = crossProduct(u1, u2);

            // Compute the angle of rotation
            float angle = std::acos(dot);

            // Calculate sin and cos of half the angle
            float sinHalfAngle = std::sin(angle / 2.0f);
            float cosHalfAngle = std::cos(angle / 2.0f);

            // Create the quaternion
            Quaternion q(
                cosHalfAngle,
                axis.x * sinHalfAngle,
                axis.y * sinHalfAngle,
                axis.z * sinHalfAngle
            );

            return {
                cosHalfAngle,
                axis.x * sinHalfAngle,
                axis.y * sinHalfAngle,
                axis.z * sinHalfAngle};
        }

        Quaternion conjugate() const {
            return Quaternion(w, -x, -y, -z);
        }

        void normalize() {
            float magnitude = std::sqrt(w * w + x * x + y * y + z * z);
            if (magnitude == 0) {
                w = 1;
                x = 0;
                y = 0;
                z = 0;
            } else {
                w /= magnitude;
                x /= magnitude;
                y /= magnitude;
                z /= magnitude;
            }
        }

        void normalise() {
            float magnitude = std::sqrt(w * w + x * x + y * y + z * z);
            if (magnitude == 0) {
                w = 1;
                x = 0;
                y = 0;
                z = 0;
            } else {
                w /= magnitude;
                x /= magnitude;
                y /= magnitude;
                z /= magnitude;
            }
        }

        void enforceSign() {
            if (w < 0) {
                w = -w;
                x = -x;
                y = -y;
                z = -z;
            }
        }

        sf::Vector3f rotate(sf::Vector3f point, sf::Vector3f center = {0, 0, 0}) const {
            Quaternion p(0, point.x - center.x, point.y - center.y, point.z - center.z);
            Quaternion q = (*this * p) * conjugate();
            return {q.x + center.x, q.y + center.y, q.z + center.z};
        }

        Quaternion operator*(const Quaternion& other) const {
            Quaternion q(
                w * other.w - x * other.x - y * other.y - z * other.z,
                w * other.x + x * other.w + y * other.z - z * other.y,
                w * other.y - x * other.z + y * other.w + z * other.x,
                w * other.z + x * other.y - y * other.x + z * other.w
            );
            return q;
        }

    float w, x, y, z;
};