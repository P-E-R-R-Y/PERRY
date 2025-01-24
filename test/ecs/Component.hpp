#ifndef COMPONENT_HPP_
    #define COMPONENT_HPP_
    
    #include <ostream>
    #include <tuple>

struct Position {
    float x;

    void display()  {
      std::cout << x << std::endl;
    }
};

std::ostream& operator<<(std::ostream& os, Position const &c)
{
    return (os << c.x);
}

struct Velocity {
    float x;

    void display() {
      std::cout << x << std::endl;
    }
};

std::ostream& operator<<(std::ostream& os, Velocity const &c)
{
    return (os << c.x);
}

#endif /* !COMPONENT_HPP_ */