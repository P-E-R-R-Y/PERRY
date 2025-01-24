#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "Registry.hpp"

class System {
    public:
        virtual ~System() = default;

        virtual void lambda(Registry &) = 0;
};

#endif // SYSTEM_HPP