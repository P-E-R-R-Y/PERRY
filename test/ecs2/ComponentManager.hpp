#ifndef COMPONENT_MANAGER_HPP_
    #define COMPONENT_MANAGER_HPP_
    
    #include <tuple>
    #include "Component.hpp"
    
struct config {
    using components_list = std::tuple<Position, Velocity>;
};

#endif /* !COMPONENT_MANAGER_HPP_ */