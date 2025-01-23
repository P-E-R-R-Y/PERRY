#ifndef REGISTRY_HPP
#define REGISTRY_HPP

//local
#include "SparseArray.hpp"
#include "System.hpp"

//global
#include <any>
#include <functional>
#include <typeindex>
#include <unordered_map>
#include <vector>

class Entity;

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

//        template <typename Tuple>
//        void constexpr registerByExtractingComponents() {
//            static_assert(is_tuple<Tuple>::value, "Input must be a std::tuple");
//
//            for  (size_t i = 0; i < std::tuple_size_v<Tuple>; ++i) {
//                using CurrentType = std::tuple_element_t<Index, Tuple>;
//                myFunction<CurrentType>();  // Call the function for the current type
//            }
//        }

//        template <typename Tuple, std::size_t Index = 0>
//        void registerByExtractingComponents() {
//            static_assert(is_tuple<Tuple>::value, "Input must be a std::tuple");
//
//            if constexpr (Index < std::tuple_size_v<Tuple>) {
//                using CurrentType = std::tuple_element_t<Index, Tuple>;
//                myFunction<CurrentType>();  // Call the function for the current type
//                registerByExtractingComponents<Tuple, Index + 1>();  // Recurse for the next type
//            }
//        }

    private:

        template <typename T>
        struct is_tuple : std::false_type {};

        template <typename... Args>
        struct is_tuple<std::tuple<Args...>> : std::true_type {};

    public:

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

        size_t addSystem(std::function<void(Registry &)> f);

        void removeSystem(size_t idx);

        void update();

    private :
        size_t _entitiesCount = 0;
        std::vector<Entity> killedEntities;

        std::unordered_map<std::type_index, std::any> componentsArrays;
        std::unordered_map<std::type_index, std::any> systemsArrays;

        std::vector<std::function<void(Registry &, Entity const &)>> componentsRemoves;

        std::vector<std::function<void(Registry &)>> systems;

};

#endif // REGISTRY_HPP