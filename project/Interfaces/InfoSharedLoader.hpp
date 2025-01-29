/**
 * @file InfoSharedLoader.hpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-29
 * 
 * @addtogroup dynamic
 * @{
 */

#ifndef INFO_SHARED_LOADER_HPP
#define INFO_SHARED_LOADER_HPP

#include "../../../libraries/finder/DynamicLoader.hpp"
#include <iostream>
#include <string>

//todo make the switchlibcore use dynamicCore and not simple core to auto define simple function;
/**
 * @brief Use to dynamicaly load Any shared library
 * 
 */
class InfoSharedLoader {
    public:
        using Params = std::string;

        /**
         * @brief Construct a new Info Shared Loader object with every symbols from the shared library
         * 
         * @param file 
         */
        InfoSharedLoader(std::string file): dl(file) {
            if (!dl.isReady()) {
                std::cerr << "Failed to retrieve " << file << " info." << std::endl;
                return;
            } else {
                std::cout << "Loaded: " << file << std::endl;
            }

            //Core
            getType = reinterpret_cast<const char *(*)()>(dl.findSymbol("getType"));
            getName = reinterpret_cast<const char *(*)()>(dl.findSymbol("getName"));
            std::cout << "Constructor>> " << file << std::endl;
        }

        /**
         * @brief Destroy the Info Shared Loader object
         */
        ~InfoSharedLoader() = default;

        /**
         * @brief Window
         */
    private:
        DynamicLoader dl;
    public:
        const char *(*getType)();
        const char *(*getName)();
};

#endif //INFO_SHARED_LOADER_HPP