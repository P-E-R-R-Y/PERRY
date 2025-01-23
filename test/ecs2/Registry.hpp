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

class Registry;
using RegistryRef = Registry &;

class Entity;

class Registry {
    public:
        /// @brief handling entities

        Entity createEntity() {
          if (!killedEntities.empty()) {
                Entity tmp = killedEntities.back();
                killedEntities.pop_back();
                return tmp;
            } else {
                ++_entitiesCount;
                return Entity(_entitiesCount - 1, *this);
            }
        };

        Entity entityFromIndex(std::size_t idx) {
            return Entity(idx, *this);
        };

        void killEntity(Entity const &e) {
            killedEntities.push_back(e);
            for (const auto &f: componentsRemoves) {
                f(*this, e);
            }
        };
        /// @brief handling components
        template <class Component>
        SparseArray<Component> &registerComponent() {
            componentsArrays[std::type_index(typeid(Component))] = std::make_any<SparseArray<Component>>();
            componentsRemoves.push_back([] (Registry &r, Entity const &e) { r.getComponents<Component>().erase(e._idx); } );
            return std::any_cast<SparseArray<Component> &>(componentsArrays[std::type_index(typeid(Component))]);
        };

        template <class ... Components>
        void registerComponents() {
            (registerComponent<Components>(), ...);
        };

        template <class Tuple>
        void registerComponentsByExtraction() {
            static_assert(is_tuple<Tuple>::value, "Extraction must a std::tuple of Components.");
            std::apply([this](auto ... components) {
                this->registerComponents<std::decay_t<decltype(components)>...>();
            }, Tuple{});
        }

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
        SparseArray<Component> &getComponents() {
            return std::any_cast<sparseArray<Component> &>(componentsArrays[std::type_index(typeid(Component))]); //
        };

        template <class Component>
        const SparseArray<Component> &getComponents() const {
            return std::any_cast<sparseArray<Component> &>(componentsArrays.at(std::type_index(typeid(Component))));
        };

        template <typename Component>
        typename SparseArray<Component>::reference_type addComponent(Entity const &to, Component &&c) {
            getComponents<Component>().emplaceAt(to._idx, c);
            return getComponents<Component>()[to._idx];
        };

        template <typename Component, typename ... Params>
        typename SparseArray <Component>::reference_type emplaceComponent(Entity const &to, Params &&... p) {
            getComponents<Component>().emplaceAt(to._idx, p...);
            return getComponents<Component>()[to._idx];
        };

        template <typename Component>
        void removeComponent(Entity const &from) {
            getComponents<Component>().erase(from._idx);
        };

        /// @brief handling systems

        size_t addSystem(std::function<void(Registry &)> f) {
            systems.push_back(f);
            return systems.size() - 1;
        };

        void removeSystem(size_t idx) {
            systems.erase(systems.begin() + idx);
        };

        void update() {
            for (auto &f: systems) {
                f(*this);
            }
        };

    private :
        size_t _entitiesCount = 0;
        std::vector<Entity> killedEntities;

        std::unordered_map<std::type_index, std::any> componentsArrays;
        std::unordered_map<std::type_index, std::any> systemsArrays;

        std::vector<std::function<void(Registry &, Entity const &)>> componentsRemoves;

        std::vector<std::function<void(Registry &)>> systems;

};

#endif // REGISTRY_HPP