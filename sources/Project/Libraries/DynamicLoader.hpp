/**
 *
 * File: DynamicLoader.hpp
 * Created Date: Tu Mar 2023
 * Project: PERRY
 * Author: Perry Chouteau
 *
 * Last Modified: Tue Mar 14 2023
 * Modified By: Perry Chouteau
 *
 * Copyright (c) 2023-2033 Perry Chouteau
 *
 **/

#include <dlfcn.h>
#include <string>
#include <vector>
#include <iostream>

class DynamicLoader {
    public:
        DynamicLoader(std::string str): _lib(dlopen(str.c_str(), RTLD_NOW)) {
            if (_lib == nullptr)
                std::cout << "string str == null" << std::endl;
            else
                std::cout << "string str worked" << std::endl;
        }

        DynamicLoader(const DynamicLoader& other): _lib(other._lib ) {
            if (_lib == nullptr)
                std::cout << "& other == null" << std::endl;
            else
                std::cout << "& other worked" << std::endl;
        }

        DynamicLoader(DynamicLoader&& other): _lib(other._lib) {
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

        void *findSymbol(std::string str) {
            return dlsym(_lib, str.c_str());
        }

    private:
        void *_lib;
};
