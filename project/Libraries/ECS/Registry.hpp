#include <iostream>
#include <vector>
#include <optional>
#include <any>
#include <unordered_map>
#include <typeindex>
#include <functional>

/*!
 *  \addtogroup ECS
 *  @{
 *
 */

//! All of the ECS related stuff
//Step 0:
#ifndef ECS_HPP_
    #define ECS_HPP_

class registry;
using Registry_ref = registry &;

//Step 0:

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
 * @param c
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
class sparse_array {

    public :
        using value_type = std::optional<Component>;
        using reference_type = value_type &;
        using const_reference_type = value_type const &;
        using container_t = std::vector<value_type>;
        using size_type = typename container_t::size_type ;
        using iterator = typename container_t::iterator ;
        using const_iterator = typename container_t::const_iterator ;

    public :

        /**
         * @brief sparse_array - default constructor
         */
        sparse_array() = default;

        /**
         * @brief sparse_array - copy constructor
         *
         * @params sparse_array const &
         */
        sparse_array(sparse_array const &) = default; //

        /**
         * @brief sparse_array - move constructor
         *
         * @param sparse_array &&
         * @
         */
        sparse_array(sparse_array &&) noexcept = default;

        /**
         * @brief sparse_array - default destructor
         *
         */
        ~sparse_array() = default;

        /**
         * @brief operator = - copy assignment operator
         *
         * @param sparse_array const &
         * @return sparse_array&
         */
        sparse_array &operator=(sparse_array const &) = default;

        /**
         * @brief operator = - move assignment operator

         * @param sparse_array &&
         * @return sparse_array&
         */
        sparse_array &operator=(sparse_array &&) noexcept = default;

        /**
         * @brief operator
         *
         * @param idx
         * @return reference_type
         */
        reference_type operator[](size_t idx)
        {
            return _data[idx];
        };

        /**
         * @brief operator
         *
         * @param idx
         * @return const_reference_type
         */
        const_reference_type operator[](size_t idx) const
        {
            return _data.at(idx);
        };

        /**
         * @brief begin
         *
         * @return iterator
         */
        iterator begin() {
            return _data.begin();
        };

        /**
         * @brief begin
         *
         * @return const_iterator
         */
        const_iterator begin() const
        {
            return _data.begin();
        };

        /**
         * @brief end
         *
         * @return const_iterator
         */
        const_iterator cbegin() const
        {
            return _data.cbegin();
        };

        /**
         * @brief end
         *
         * @return iterator
         */
        iterator end()
        {
            return _data.end();
        };

        /**
         * @brief end
         *
         * @return const_iterator
         */
        const_iterator end() const
        {
            return _data.end();
        };

        /**
         * @brief cend
         *
         * @return const_iterator
         */
        const_iterator cend() const
        {
            return _data.cend();
        };

        /**
         * @brief size
         *
         * @return size_type
         */
        size_type size() const
        {
            return _data.size();
        };

        /**
         * @brief insert_at
         *
         * @param pos
         * @param c //~ rvalue
         * @return reference_type
         */
        reference_type insert_at ( size_type pos , Component const &c) //~ rvalue
        {
            if (_data.size() <= pos)
                _data.resize(pos + 1);
            _data[pos] = std::make_optional (c);
            return _data[pos];
        };

        /**
         * @brief insert_at
         *
         * @param pos
         * @param c //~ lvalue
         * @return reference_type
         */
        reference_type insert_at ( size_type pos , Component &&c) //~ lvalue
        {
            if (_data.size() <= pos)
                _data.resize(pos + 1);
            _data[pos] = std::make_optional (std::move(c));
            return _data[pos];
        };

        /**
         * @brief emplace_at
         *
         * @tparam Params
         * @param pos
         * @param args
         * @return reference_type
         */
        template <class ... Params>
        reference_type emplace_at ( size_type pos , Params &&...args)
        {
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
        void erase ( size_type pos ) {
            if (pos >= 0 && pos < _data.size())
                _data[pos] = std::nullopt;
        };

        /**
         * @brief get_index
         *
         * @param v
         * @return size_type
         */
        size_type get_index ( value_type const &v) const
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
         * @brief register_component
         *
         * @tparam Component
         * @return sparse_array<Component>&
         */
        template <class Component>
        sparse_array<Component> &register_component()
        {
            _components_arrays[std::type_index(typeid(Component))] = std::make_any<sparse_array<Component>>();
            _components_removes.push_back([] (registry &r, entity_t const &e) { r.get_components<Component>().erase(e._idx); } );
            return std::any_cast<sparse_array<Component> &>(_components_arrays[std::type_index(typeid(Component))]);
        };

        /**
         * @brief get_components
         *
         * @tparam Component
         * @return sparse_array<Component>&
         */
        template <class Component>
        sparse_array<Component> &get_components()
        {
            return std::any_cast<sparse_array<Component> &>(_components_arrays[std::type_index(typeid(Component))]); //
        };

        /**
         * @brief Get the components object
         *
         * @tparam Component
         * @return sparse_array<Component> const&
         */
        template <class Component>
        sparse_array<Component> const &get_components () const
        {
            return std::any_cast<sparse_array<Component> &>(_components_arrays.at(std::type_index(typeid(Component))));
        };

        /**
         * @brief spawn_entity - create an entity
         *
         * @return entity_t
         */
        entity_t spawn_entity() // ~
        {
            if (!_killed_entities.empty()) {
                entity_t tmp = _killed_entities.back();
                _killed_entities.pop_back();
                return tmp;
            } else {
                    ++_entitys_count;
                    return entity_t(_entitys_count - 1);
            }
        };

        /**
         * @brief
         *
         * @param idx
         * @return entity_t
         */
        // ~
        static entity_t entity_from_index(std::size_t idx) // ~ create an entity
        {
            return entity_t(idx);
        };

        /**
         * @brief kill entity
         *
         * @param e
         *
         */
        void kill_entity(entity_t const &e)
        {
            _killed_entities.push_back(e);
            for (auto f: _components_removes)
                f(*this, e);
        };

        /**
         * @brief
         *
         * @tparam Component
         * @param to
         * @param c
         * @return sparse_array<Component>::reference_type
         */
        template <typename Component>
        typename sparse_array<Component>::reference_type add_component(entity_t const &to, Component &&c)
        {
            get_components<Component>().emplace_at(to._idx, c);
            return get_components<Component>()[to._idx];
        };

        /**
         * @brief
         *
         * @tparam Component
         * @tparam Params
         * @param to
         * @param p
         * @return sparse_array <Component>::reference_type
         */
        template <typename Component, typename ... Params>
        typename sparse_array <Component>::reference_type emplace_component(entity_t const &to, Params &&... p)
        {
            get_components<Component>().emplace_at(to._idx, p...);
            return get_components<Component>()[to._idx];
        };

        /**
         * @brief
         *
         * @tparam Component
         * @param from
         */
        template <typename Component>
        void remove_component(entity_t const &from)
        {
            get_components<Component>().erase(from._idx);
        };

    private :
        size_t _entitys_count = 0;
        std::vector<entity_t> _killed_entities;

        std::unordered_map<std::type_index, std::any> _components_arrays;

        std::vector<std::function<void(registry &, entity_t const &)>> _components_removes;
};

#endif // ECS_HPP_