/**
 * @file DynamicLoader.hpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-29
 * 
 * @addtogroup utility
 * @{
 */

#ifndef DYNAMICLOADER_HPP
#define DYNAMICLOADER_HPP

#include <dlfcn.h>
#include <string>
#include <vector>
#include <iostream>

/**
 * @brief load shared libraries & retrieve symbols
 * 
 */
class DynamicLoader {
    public:
    
        DynamicLoader() {
        }

        DynamicLoader(std::string str): _lib(dlopen(str.c_str(), RTLD_NOW)), _name(str) {
            if (!_lib)
                std::cerr << "dlopen failed: " << dlerror() << std::endl;
        }

        DynamicLoader(const DynamicLoader& other): _lib(other._lib), _name(other._name) {
            if (!this->isReady())
                std::cout << "move other == null" << std::endl;
        }

        DynamicLoader(DynamicLoader&& other): _lib(other._lib), _name(other._name) {
            if (!this->isReady())
                std::cout << "copy other == null" << std::endl;
        }

        ~DynamicLoader() {
            if (_lib != nullptr)
                dlclose(_lib);
        }

        bool isReady() {
            return (_lib);
        }

        void setPath(std::string str) {
            _name = str;
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