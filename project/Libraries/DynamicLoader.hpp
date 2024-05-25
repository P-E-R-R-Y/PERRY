/**
 *
 * File: DynamicLoader.hpp (header.v2)
 * Created Date: Tue 14/03/2023
 * Project: PERRY
 * Author: Perry Chouteau
 *
 * Last Modified: Sat 18/03/2023
 * Modified By: Perry Chouteau
 *
 * Copyright (c) 2023-2033 Perry Chouteau
 *
 **/

#ifndef DYNAMICLOADER_HPP
#define DYNAMICLOADER_HPP

#include <dlfcn.h>
#include <string>
#include <vector>
#include <iostream>

class DynamicLoader {
    public:
        DynamicLoader() {
        }

        DynamicLoader(std::string str): _lib(dlopen(str.c_str(), RTLD_NOW)), _name(str) {
             if (_lib == nullptr)
                std::cout << "string str == null" << std::endl;
            else
                std::cout << "string str worked" << std::endl;
        }

        DynamicLoader(const DynamicLoader& other): _lib(other._lib), _name(other._name) {
            if (_lib == nullptr)
                std::cout << "& other == null" << std::endl;
            else
                std::cout << "& other worked" << std::endl;
        }

        DynamicLoader(DynamicLoader&& other): _lib(other._lib), _name(other._name) {
            if (_lib == nullptr)
                std::cout << "&& other == null" << std::endl;
            else
                std::cout << "&& other worked" << std::endl;
        }

        ~DynamicLoader() {
            if (_lib != nullptr)
                dlclose(_lib);
        }

        bool isReady() {
            return (_lib);
        }

        void setPath(std::string str) {
            _lib = dlopen(str.c_str(), RTLD_NOW);
        }

        std::string getPath() const {
            return _name;
        }

        void setLib(void *lib) {
            _lib = lib;
        }

        void *getLib() {
            return _lib;
        }

        void *findSymbol(std::string str) {
            return dlsym(_lib, str.c_str());
        }

    private:
        void *_lib;
        std::string _name;
};

#endif //DYNAMICLOADER_HPP