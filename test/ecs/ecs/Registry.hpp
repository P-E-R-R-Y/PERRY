#ifndef REGISTRY_HPP
#define REGISTRY_HPP

//local
#include "SparseArray.hpp"

//global
#include <any>
#include <functional>
#include <typeindex>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <typeindex>
#include <memory>


class Entity;
class System;

class Registry {

    public:

        /// @brief handling entities (define in Registry.cpp)

        Entity createEntity();

        Entity entityFromIndex(std::size_t idx);

        void killEntity(Entity const &e);

        /// @brief handling components (define in Registry_impl.hpp)

        template <class Component>
        SparseArray<Component> &registerComponent();

        template <class ... Components>
        void registerComponents();

        template <class Tuple>
        void registerComponentsByExtraction();

        template <class Component>
        SparseArray<Component> &getComponents();

        template <class Component>
        const SparseArray<Component> &getComponents() const;

        template <typename Component>
        typename SparseArray<Component>::reference_type addComponent(Entity const &to, Component &&c);

        template <typename Component, typename ... Params>
        typename SparseArray <Component>::reference_type emplaceComponent(Entity const &to, Params &&... p);

        template <typename Component>
        void removeComponent(Entity const &from);

        /// @brief handling systems

        template <typename T, typename... Args>
        size_t addSystem(Args&&... args);

        template <typename T>
        size_t addSystem(std::unique_ptr<T> existingSystem);

        template <typename T>
        void removeSystem();

        template <typename T>
        void callSystem();

        void callSystems();

    private:

        template <typename T>
        struct is_tuple : std::false_type {};

        template <typename... Args>
        struct is_tuple<std::tuple<Args...>> : std::true_type {};

    private:

        size_t _entitiesCount = 0;
        std::vector<Entity> killedEntities;

        std::unordered_map<std::type_index, std::any> componentsArrays;
        std::unordered_map<std::type_index, std::any> systemsArrays;

        std::vector<std::function<void(Registry &, Entity const &)>> componentsRemoves;

        std::unordered_map<std::type_index, std::unique_ptr<System>> systems;
};

#endif // REGISTRY_HPP