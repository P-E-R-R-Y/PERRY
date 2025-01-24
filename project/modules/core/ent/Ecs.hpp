/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-zacharie.lawson
** File description:
** ProjectComponent
*/

/*!
 *  \addtogroup ECS
 *  @{
 *
 */

#ifndef ECS_HPP_
    #define ECS_HPP_

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
 *
 * @author perry.chouteau@epitech.eu
 */
struct entity_t {
    size_t _idx;
    entity_t() = delete;
    ~entity_t() = default;

    friend registry;

    private:
        explicit entity_t(size_t idx)
        {
            _idx = idx;
        };
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
 *
 * @author perry.chouteau@epitech.eu
 */
template <typename Component>
class sparseArray {

    public :
        using valueType = std::optional<Component>;
        using reference_type = valueType &;
        using constReferenceType = valueType const &;
        using container_t = std::vector<valueType>;
        using size_type = typename container_t::size_type ;
        using iterator = typename container_t::iterator ;
        using constIterator = typename container_t::const_iterator ;

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

        /**
         * @brief sparseArray - move constructor
         *
         * @param sparse_array &&
         * @
         */
        sparseArray(sparseArray &&) noexcept = default;

        /**
         * @brief sparseArray - default destructor
         *
         */
        ~sparseArray() = default;

        /**
         * @brief operator = - copy assignment operator
         *
         * @param sparse_array const &
         * @return sparseArray&
         */
        sparseArray &operator=(sparseArray const &) = default;

        /**
         * @brief operator = - move assignment operator

         * @param sparse_array &&
         * @return sparseArray&
         */
        sparseArray &operator=(sparseArray &&) noexcept = default;

        /**
         * @brief operator
         *
         * @param idx
         * @return reference_type
         */
        inline reference_type operator[](size_t idx) { return _data[idx]; };

        /**
         * @brief operator
         *
         * @param idx
         * @return constReferenceType
         */
        constReferenceType operator[](size_t idx) const
        {
            return _data.at(idx);
        };

        /**
         * @brief begin
         *
         * @return iterator
         */
        inline iterator begin() { return _data.begin(); };

        /**
         * @brief begin
         *
         * @return constIterator
         */
        inline constIterator begin() const { return _data.begin(); };

        /**
         * @brief end
         *
         * @return constIterator
         */
        inline constIterator cbegin() const { return _data.cbegin(); };

        /**
         * @brief end
         *
         * @return iterator
         */
        inline iterator end() { return _data.end(); };

        /**
         * @brief end
         *
         * @return constIterator
         */
        inline constIterator end() const { return _data.end(); };

        /**
         * @brief cend
         *
         * @return constIterator
         */
        inline constIterator cend() const { return _data.cend(); };

        /**
         * @brief size
         *
         * @return size_type
         */
        inline size_type size() const { return _data.size(); };

        /**
         * @brief insertAt
         *
         * @param pos
         * @param c //~ rvalue
         * @return reference_type
         */
        reference_type insertAt(size_type pos, Component const &c) //~ rvalue
        {
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
        reference_type insertAt(size_type pos, Component &&c) //~ lvalue
        {
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
        reference_type emplaceAt(size_type pos, Params &&...args)
        {
            container_t vecArgs = {args...};

            size_type i = vecArgs.size();
            if ( _data.size() <= pos + i)
                _data.resize(pos + i);
            i = 0;
            for(valueType v : vecArgs) {
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
        void erase(size_type pos)
        {
            if (pos >= 0 && pos < _data.size())
                _data[pos] = std::nullopt;
        };

        /**
         * @brief getIndex
         *
         * @param v
         * @return size_type
         */
        size_type getIndex(valueType const &v) const
        {
            for(unsigned int i = 0; i < _data.size(); i++) {
                if (v == _data[i])
                    return i;
            }
            return 0;
        };

        /**
         * @brief display
         *
         */
        void display() const
        {
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
            std::cout << "}" << std::endl;
        };

    private :
        container_t _data ;
};

/**
 * @brief registry (ECS)
 *
 * @author perry.chouteau@epitech.eu
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
        sparseArray<Component> &registerComponent()
        {
            componentsArrays[std::type_index(typeid(Component))] = std::make_any<sparseArray<Component>>();
            componentsRemoves.push_back([] (registry &r, entity_t const &e) { r.getComponents<Component>().erase(e._idx); } );
            return std::any_cast<sparseArray<Component> &>(componentsArrays[std::type_index(typeid(Component))]);
        };

        /**
         * @brief getComponents
         *
         * @tparam Component
         * @return sparseArray<Component>&
         */
        template <class Component>
        sparseArray<Component> &getComponents()
        {
            return std::any_cast<sparseArray<Component> &>(componentsArrays[std::type_index(typeid(Component))]); //
        };

        /**
         * @brief get the components object
         *
         * @tparam Component
         * @return sparseArray<Component> const&
         */
        template <class Component>
        sparseArray<Component> const &getComponents () const
        {
            return std::any_cast<sparseArray<Component> &>(componentsArrays.at(std::type_index(typeid(Component))));
        };

        /**
         * @brief spawnEntity - create an entity
         *
         * @return entity_t
         */
        entity_t spawnEntity() // ~
        {
            if (!killedEntities.empty()) {
                entity_t tmp = killedEntities.back();
                killedEntities.pop_back();
                return tmp;
            } else {
                ++_entitiesCount;
                return entity_t(_entitiesCount - 1);
            }
        };

        /**
         * @brief
         *
         * @param idx
         * @return entity_t
         */
        // ~
        static entity_t entityFromIndex(std::size_t idx) // ~ create an entity
        {
            return entity_t(idx);
        };

        /**
         * @brief kill entity
         *
         * @param e
         *
         */
        void killEntity(entity_t const &e)
        {
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
        typename sparseArray<Component>::reference_type addComponent(entity_t const &to, Component &&c)
        {
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
        typename sparseArray <Component>::reference_type emplaceComponent(entity_t const &to, Params &&... p)
        {
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
        void removeComponent(entity_t const &from)
        {
            getComponents<Component>().erase(from._idx);
        };

    private :
        size_t _entitiesCount = 0;
        std::vector<entity_t> killedEntities;

        std::unordered_map<std::type_index, std::any> componentsArrays;

        std::vector<std::function<void(registry &, entity_t const &)>> componentsRemoves;
};

#endif /* ECS_HPP_ */