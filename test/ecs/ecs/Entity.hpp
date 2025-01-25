#ifndef ENTITY_HPP
#define ENTITY_HPP

//local

//global
#include <cstddef>

class Registry;
using RegistryRef = Registry &;

class Entity {
    public:

        friend Registry;

    public:

        Entity() = delete;
        ~Entity() = default;

        template <class Component>
        void addComponent(Component&& c);

        template <class Component>
        void removeComponent();

    private:

        explicit Entity(size_t idx, RegistryRef ecs);

    private:
        size_t _idx;
        RegistryRef _ecs;
};

#endif // ENTITY_HPP