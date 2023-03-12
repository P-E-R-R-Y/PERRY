/**
 *
 * File: Factory.hpp
 * Created Date: Su Mar 2023
 * Project: PERRY
 * Author: Perry Chouteau
 *
 * Last Modified: Sun Mar 12 2023
 * Modified By: Perry Chouteau
 *
 * Copyright (c) 2023-2033 Perry Chouteau
 *
 **/

#include <string>
#include <map>

template <typename T>
class Factory {
    public:
        Factory(std::vector<std::string> list): _list(list) {
            for (auto &it : _list)
                _list[it] =
        };

        ~Factory() = default;

        T &create() {
            return ;
        }

    private:
        std::map<std::string,T> _list;
};