#ifndef ENTITY_HPP
#define ENTITY_HPP

//local
#include "Registry.hpp"

//global
#include <cstddef>

class Entity {
    public:

        friend Registry;

    public:

        Entity() = delete;
        ~Entity() = default;

        template <class Component>
        void addComponent(Component&& c) {
            _ecs.addComponent<Component>(*this, std::forward<Component>(c));
        }

        template <class Component>
        void removeComponent() {
            _ecs.removeComponent<Component>(*this);
        }

    private:

        explicit Entity(size_t idx, RegistryRef ecs): _idx(idx), _ecs(ecs) {};

    private:
        size_t _idx;
        RegistryRef _ecs;
};

#endif // ENTITY_HPP