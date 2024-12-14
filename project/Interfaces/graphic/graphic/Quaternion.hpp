
#ifndef QUATERNION_HPP_
#define QUATERNION_HPP_

#include <cmath>
#include <array>
#include <iostream>

class Quaternion {
public:
    double w, x, y, z;

    Quaternion(double w, double x, double y, double z) : w(w), x(x), y(y), z(z) {}

    // Create a quaternion from an axis and an angle
    static Quaternion fromAxisAngle(const std::array<double, 3>& axis, double angle) {
        double half_angle = angle / 2.0;
        double s = std::sin(half_angle);
        double c = std::cos(half_angle);

        // Normalize the axis
        double magnitude = std::sqrt(axis[0] * axis[0] + axis[1] * axis[1] + axis[2] * axis[2]);
        return Quaternion(c, axis[0] * s / magnitude, axis[1] * s / magnitude, axis[2] * s / magnitude);
    }

    static Quaternion fromEulerAngles(double x, double y, double z) {
        // Convert degrees to radians if needed
        double rx = x * M_PI / 180.0;
        double ry = y * M_PI / 180.0;
        double rz = z * M_PI / 180.0;

        // https://en.wikipedia.org/wiki/Flight_dynamics_(fixed-wing_aircraft)
        // Compute half-angles
        double cy = cos(rz * 0.5);
        double sy = sin(rz * 0.5);
        double cp = cos(ry * 0.5);
        double sp = sin(ry * 0.5);
        double cr = cos(rx * 0.5);
        double sr = sin(rx * 0.5);

        // Quaternion product formula
        return Quaternion(
            cr * cp * cy + sr * sp * sy,  // w
            sr * cp * cy - cr * sp * sy,  // x
            cr * sp * cy + sr * cp * sy,  // y
            cr * cp * sy - sr * sp * cy   // z
        );
    }

    // Create a quaternion from a vector
    static Quaternion fromVector(const std::array<double, 3>& vector) {
        return Quaternion(0, vector[0], vector[1], vector[2]);
    }

    // Multiply two quaternions
    Quaternion operator*(const Quaternion& other) const {
        return Quaternion(
            w * other.w - x * other.x - y * other.y - z * other.z,
            w * other.x + x * other.w + y * other.z - z * other.y,
            w * other.y - x * other.z + y * other.w + z * other.x,
            w * other.z + x * other.y - y * other.x + z * other.w
        );
    }

    Quaternion& operator*=(const Quaternion& other) {
        double new_w = w * other.w - x * other.x - y * other.y - z * other.z;
        double new_x = w * other.x + x * other.w + y * other.z - z * other.y;
        double new_y = w * other.y - x * other.z + y * other.w + z * other.x;
        double new_z = w * other.z + x * other.y - y * other.x + z * other.w;

        w = new_w;
        x = new_x;
        y = new_y;
        z = new_z;

        return *this;
    }

    //normalize the quaternion
    void normalize() {
        const double magnitude = std::sqrt(w * w + x * x + y * y + z * z);
        w /= magnitude;
        x /= magnitude;
        y /= magnitude;
        z /= magnitude;
    }

    // Conjugate of the quaternion
    Quaternion conjugate() const {
        return Quaternion(w, -x, -y, -z);
    }

    // Rotate a point using the quaternion
    std::array<double, 3> rotatePoint(const std::array<double, 3>& point) const {
        Quaternion p(0, point[0], point[1], point[2]);
        Quaternion rotated = (*this) * p * conjugate();
        return {rotated.x, rotated.y, rotated.z};
    }

    // Rotate a point around a center of rotation using Euler angles
    static std::array<double, 3> rotate(
        const std::array<double, 3>& point,
        const std::array<double, 3>& angle,
        const std::array<double, 3>& centerOfRotation = {0, 0, 0}
    ) {
        // Translate the point relative to the center of rotation
        std::array<double, 3> translatedPoint = {
            point[0] - centerOfRotation[0],
            point[1] - centerOfRotation[1],
            point[2] - centerOfRotation[2]
        };

        Quaternion rotation = Quaternion::fromEulerAngles(angle[0], angle[1], angle[2]);

        // Rotate the translated point
        std::array<double, 3> rotatedPoint = rotation.rotatePoint(translatedPoint);

        // Translate the point back to its original position
        return {
            rotatedPoint[0] + centerOfRotation[0],
            rotatedPoint[1] + centerOfRotation[1],
            rotatedPoint[2] + centerOfRotation[2]
        };
    }
};

#endif // QUATERNION_HPP_