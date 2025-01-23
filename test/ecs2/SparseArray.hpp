#ifndef SPARSE_ARRAY_HPP
#define SPARSE_ARRAY_HPP

//local

//global
#include <iostream>
#include <vector>
#include <optional>

template <typename Component>
std::ostream& operator<<(std::ostream& os, std::optional<Component> const &c)
{
    if (c)
        os << c.value();
    else
        os << "nullopt";
    return os;
}

template <typename Component>
class SparseArray {

    public: 

        using value_type = std::optional<Component>;
        using reference_type = value_type &;
        using const_reference_type = value_type const &;

        using container_t = std::vector<value_type>;

        using size_type = typename container_t::size_type;

        using iterator = typename container_t::iterator;
        using const_iterator = typename container_t::const_iterator;
    
    public:

        SparseArray() = default;
        SparseArray(SparseArray const &) = default;
        SparseArray(SparseArray &&) noexcept = default;
        ~SparseArray() = default;

        SparseArray &operator=(SparseArray const &) = default;
        SparseArray &operator=(SparseArray &&) noexcept = default;

        inline reference_type operator[](size_t idx) { return _data[idx]; }
        const_reference_type operator[](size_t idx) const { return _data.at(idx); }

        inline iterator begin() { return _data.begin(); }
        inline const_iterator begin() const { return _data.begin(); }
        inline const_iterator cbegin() const { return _data.cbegin(); }

        inline iterator end() { return _data.end(); }
        inline const_iterator end() const { return _data.end(); }
        inline const_iterator cend() const { return _data.cend(); }

        inline size_type size() const { return _data.size(); }

        reference_type insertAt(size_type pos, Component const &c) {
            if (_data.size() <= pos)
                _data.resize(pos + 1);
            _data[pos] = std::make_optional(c);
            return _data[pos];
        };

        reference_type insertAt(size_type pos, Component &&c) {
            if (_data.size() <= pos)
                _data.resize(pos + 1);
            _data[pos] = std::make_optional(std::move(c));
            return _data[pos];
        };

        template <class ... Params>
        reference_type emplaceAt(size_type pos, Params &&...args) {
            container_t vecArgs = {args...};

            size_type i = vecArgs.size();
            if (_data.size() <= pos + i)
                _data.resize(pos + i);
            i = 0;
            for (value_type v : vecArgs) {
                _data[pos + i] = v;
                ++i;
            }
            return _data[pos];
        };

        void erase(size_type pos) {
            if (pos >= 0 && pos < _data.size()) {
                _data[pos] = std::nullopt;
            }
        };

        size_type getIndex(const value_type &v) const {
            auto it = std::find(_data.begin(), _data.end(), v);
            if (it != _data.end())
                return std::distance(_data.begin(), it);
            return -1;  // return 0 if not found
        };

        void print() const {
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

    private:

        container_t _data;
};

#endif // SPARSE_ARRAY_HPP