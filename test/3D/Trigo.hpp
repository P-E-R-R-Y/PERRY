#pragma once

#include <cmath> 

constexpr float degreestoRadians(const float degrees) {
    return degrees * M_PI / 180;
}

constexpr float radianstoDegrees(const float radians) {
    return radians * 180 / M_PI;
}