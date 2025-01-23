#ifndef COMPONENT_MANAGER_HPP
#define COMPONENT_MANAGER_HPP

//global
#include <iostream>

struct Position {
    float x;
    float y;
};

std::ostream& operator<<(std::ostream& os, Position const &p) {
    os << "Position(" << p.x << ", " << p.y << ")";
    return os;
}

struct Velocity {
    float x;
    float y;
};

std::ostream& operator<<(std::ostream& os, Velocity const &v) {
    os << "Velocity(" << v.x << ", " << v.y << ")";
    return os;
}

using config = std::tuple<Position, Velocity>;

#endif // COMPONENT_MANAGER_HPP