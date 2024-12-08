/**
 *
 * File: SwitchLibCore.hpp (header.v2)
 * Created Date: Sun 02/04/2023
 * Project: PERRY
 * Author: Perry Chouteau
 *
 * Last Modified: Sun 02/04/2023
 * Modified By: Perry Chouteau
 *
 * Copyright (c) 2023-2033 Perry Chouteau
 *
 **/

#ifndef INFO_SHARED_LOADER_HPP
#define INFO_SHARED_LOADER_HPP

#include "../../../libraries/finder/DynamicLoader.hpp"
#include <iostream>
#include <string>

//todo make the switchlibcore use dynamicCore and not simple core to auto define simple function;
class InfoSharedLoader {
    public:
        using Params = std::string;

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