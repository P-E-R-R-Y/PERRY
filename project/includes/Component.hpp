/**
 * @file Component.hpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-29
 * 
 * @addtogroup user
 * @{
 */

#ifndef COMPONENT_HPP_
    #define COMPONENT_HPP_
    
    #include <ostream>
    #include <tuple>

struct Position {
    float x;
    float y;
};

std::ostream& operator<<(std::ostream& os, Position const &c)
{
    return (os << c.x << ", " << c.y);
}

struct Velocity {
    float x;
    float y;
};

std::ostream& operator<<(std::ostream& os, Velocity const &c)
{
    return (os << c.x << ", " << c.y);
}

/**
 * @brief register every components by extraction from a tuple
 * 
 */
struct config {
    using components = std::tuple<Position, Velocity>;
};

#endif /* !COMPONENT_HPP_ */