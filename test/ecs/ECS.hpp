/**
 * @file Registry.hpp
 * @author @Perry-chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 1.0
 * @date 2025-01-21
 * 
 * @copyright Copyright (c) 2025
 * 
 * \addtogroup ECS
 */

/**
 * \addtogroup ECS
 */

#ifndef ECS_HPP
    #define ECS_HPP

  #include <cstddef>
  #include <utility>
  #include <iostream>
  #include <vector>
  #include <optional>
  #include <any>
  #include <unordered_map>
  #include <typeindex>
  #include <functional>

class registry;
using registryRef = registry &;

/**
 * @brief the definition of an entity
 */
class entity_t {
  public:
    entity_t() = delete;
    ~entity_t() = default;

    friend registry;

//    template <class Component>
//    void addComponent(Component&& c, registryRef _ecs) {
//        _ecs.addComponent<Component>(*this, std::forward<Component>(c));
//    }

    private:
        explicit entity_t(size_t idx/*, registryRef ecs*/): _idx(idx)/*, _ecs(ecs)*/ {};

        size_t _idx;
        //registryRef _ecs;
};

/**
 * @brief operator<<
 *
 * @tparam Component
 * @param os
 * @param c std::optional<Component>
 * @return std::ostream&
 */
template <typename Component>
std::ostream& operator<<(std::ostream& os, std::optional<Component> const &c)
{
    if (c)
        os << c.value();
    else
        os << "None";
    return os;
}

/**
 * @brief class sparce_array
 *
 * @tparam Component
 */
template <typename Component>
class sparseArray {

    public :
        using value_type = std::optional<Component>;
        using reference_type = value_type &;
        using const_reference_type = value_type const &;

        using container_t = std::vector<value_type>;

        using size_type = typename container_t::size_type;

        using iterator = typename container_t::iterator ;
        using const_iterator = typename container_t::const_iterator;

    public :

        /**
         * @brief sparseArray - default constructor
         */
        sparseArray() = default;

        /**
         * @brief sparseArray - copy constructor
         *
         * @params sparseArray const &
         */
        sparseArray(sparseArray const &) = default;
        sparseArray(sparseArray &&) noexcept = default;
        ~sparseArray() = default;

        sparseArray &operator=(sparseArray const &) = default;
        sparseArray &operator=(sparseArray &&) noexcept = default;

        /**
         * @brief operator[]
         *
         * @param idx
         * @return reference_type
         */
        inline reference_type operator[](size_t idx) { return _data[idx]; }

        /**
         * @return constReferenceType
         */
        const_reference_type operator[](size_t idx) const { return _data.at(idx); }

        /**
         * @brief begin
         *
         * @return iterator
         */
        inline iterator begin() { return _data.begin(); }

        /**
         * @return constIterator
         */
        inline const_iterator begin() const { return _data.begin(); }
        /**
         * @brief end
         *
         * @return constIterator
         */
        inline const_iterator cbegin() const { return _data.cbegin(); }

        /**
         * @brief end
         *
         * @return iterator
         */
        inline iterator end() { return _data.end(); }

        /**
         * @brief end
         *
         * @return constIterator
         */
        inline const_iterator end() const { return _data.end(); }

        /**
         * @brief cend
         *
         * @return constIterator
         */
        inline const_iterator cend() const { return _data.cend(); }

        /**
         * @brief size
         *
         * @return size_type
         */
        inline size_type size() const { return _data.size(); }

        /**
         * @brief insertAt
         *
         * @param pos
         * @param c //~ rvalue
         * @return reference_type
         */
        reference_type insertAt(size_type pos, Component const &c) {//~ rvalue
            if (_data.size() <= pos)
                _data.resize(pos + 1);
            _data[pos] = std::make_optional (c);
            return _data[pos];
        };

        /**
         * @brief insertAt
         *
         * @param pos
         * @param c //~ lvalue
         * @return reference_type
         */
        reference_type insertAt(size_type pos, Component &&c) { //~ lvalue
            if (_data.size() <= pos)
                _data.resize(pos + 1);
            _data[pos] = std::make_optional (std::move(c));
            return _data[pos];
        };

        /**
         * @brief emplaceAt
         *
         * @tparam Params
         * @param pos
         * @param args
         * @return reference_type
         */
        template <class ... Params>
        reference_type emplaceAt(size_type pos, Params &&...args) {
            container_t vecArgs = {args...};

            size_type i = vecArgs.size();
            if ( _data.size() <= pos + i)
                _data.resize(pos + i);
            i = 0;
            for(value_type v : vecArgs) {
                _data[pos + i] = v;
                ++i;
            }
            return _data[pos];
        };

        /**
         * @brief erase
         *
         * @param pos
         */
        void erase(size_type pos) {
            if (pos >= 0 && pos < _data.size()) {
                _data[pos] = std::nullopt;
            }
        };

        /**
         * @brief getIndex
         *
         * @param v
         * @return size_type
         */
        size_type getIndex(const value_type &v) const {
            auto it = std::find(_data.begin(), _data.end(), v);
            if (it != _data.end())
                return std::distance(_data.begin(), it);
            return -1;  // return 0 if not found
        };

        /**
         * @brief display
         */
        void display() const {
            bool first = true;

            std::cout << "{ ";
            for (auto const &v : _data) {
                if (!first) {
                    std::cout << ", " << v;
                } else {
                    std::cout << v;
                    first = false;
                }
            }
            std::cout << " }" << std::endl;
        };

    private :
        container_t _data ;
};

/**
 * @brief registry (ECS)
 */
class registry {
    public :

        /**
         * @brief registerComponent
         *
         * @tparam Component
         * @return sparseArray<Component>&
         */
        template <class Component>
        sparseArray<Component> &registerComponent() {
            componentsArrays[std::type_index(typeid(Component))] = std::make_any<sparseArray<Component>>();
            componentsRemoves.push_back([] (registry &r, entity_t const &e) { r.getComponents<Component>().erase(e._idx); } );
            return std::any_cast<sparseArray<Component> &>(componentsArrays[std::type_index(typeid(Component))]);
        };

        template <class ... Components>
        void registerComponents() {
            (registerComponent<Components>(), ...);
        };

        template <class Tuple>
        void registerComponentsByExtraction() {
            static_assert(is_tuple<Tuple>::value, "Extraction must a std::tuple of Components.");
            std::apply([this](auto... components) {
                this->registerComponents<std::decay_t<decltype(components)>...>();
            }, Tuple{});
        }
        
    private:
        template <typename T>
        struct is_tuple : std::false_type {};

        template <typename... Args>
        struct is_tuple<std::tuple<Args...>> : std::true_type {};
      
    public:
        /**
         * @brief getComponents
         *
         * @tparam Component
         * @return sparseArray<Component>&
         */
        template <class Component>
        sparseArray<Component> &getComponents() {
            return std::any_cast<sparseArray<Component> &>(componentsArrays[std::type_index(typeid(Component))]); //
        };

        /**
         * @brief get the components object
         *
         * @tparam Component
         * @return sparseArray<Component> const&
         */
        template <class Component>
        const sparseArray<Component> &getComponents () const {
            return std::any_cast<sparseArray<Component> &>(componentsArrays.at(std::type_index(typeid(Component))));
        };

        /**
         * @brief spawnEntity - create an entity
         *
         * @return entity_t
         */
        entity_t spawnEntity() {
            if (!killedEntities.empty()) {
                entity_t tmp = killedEntities.back();
                killedEntities.pop_back();
                return tmp;
            } else {
                ++_entitiesCount;
                return entity_t(_entitiesCount - 1/*, *this*/);
            }
        };

        /**
         * @brief
         *
         * @param idx
         * @return entity_t
         */
        // ~
        entity_t entityFromIndex(std::size_t idx) {
            return entity_t(idx/*, *this*/);
        };

        /**
         * @brief kill entity
         *
         * @param e
         *
         */
        void killEntity(entity_t const &e) {
            killedEntities.push_back(e);
            for (const auto& f: componentsRemoves)
                f(*this, e);
        };

        /**
         * @brief
         *
         * @tparam Component
         * @param to
         * @param c
         * @return sparseArray<Component>::reference_type
         */
        template <typename Component>
        typename sparseArray<Component>::reference_type addComponent(entity_t const &to, Component &&c) {
            getComponents<Component>().emplaceAt(to._idx, c);
            return getComponents<Component>()[to._idx];
        };

        /**
         * @brief
         *
         * @tparam Component
         * @tparam Params
         * @param to
         * @param p
         * @return sparseArray <Component>::reference_type
         */
        template <typename Component, typename ... Params>
        typename sparseArray <Component>::reference_type emplaceComponent(entity_t const &to, Params &&... p) {
            getComponents<Component>().emplaceAt(to._idx, p...);
            return getComponents<Component>()[to._idx];
        };

        /**
         * @brief
         *
         * @tparam Component
         * @param from
         */
        template <typename Component>
        void removeComponent(entity_t const &from) {
            getComponents<Component>().erase(from._idx);
        };

        /**
         * @brief addSystem - add a system
         *
         * @param f
         * @return size_t
         */
        size_t addSystem(std::function<void(registry &)> f) {
            systems.push_back(f);
            return systems.size() - 1;
        };

        /**
         * @brief removeSystem - remove a system by index
         *
         * @param idx
         */
        void removeSystem(size_t idx) {
            systems.erase(systems.begin() + idx);
        };

        /**
         * @brief update - update all systems 
         */
        void update() {
            for (auto &f: systems) {
                f(*this);
            }
        };

    private :
        size_t _entitiesCount = 0;
        std::vector<entity_t> killedEntities;

        std::unordered_map<std::type_index, std::any> componentsArrays;
        std::unordered_map<std::type_index, std::any> systemsArrays;

        std::vector<std::function<void(registry &, entity_t const &)>> componentsRemoves;

        std::vector<std::function<void(registry &)>> systems;
};

#endif /* !ECS_HPP */