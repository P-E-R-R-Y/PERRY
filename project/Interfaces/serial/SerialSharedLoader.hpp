/**
 *
 * File: SwitchLibCore.hpp (header.v2)
 * Created Date: Fri 29/11/2024
 * Project: PERRY
 * Author: Perry Chouteau
 *
 * Last Modified: Sun 02/04/2023
 * Modified By: Perry Chouteau
 *
 * Copyright (c) 2023-2033 Perry Chouteau
 *
 **/

#ifndef SERIAL_SHARED_LOADER_HPP
#define SERIAL_SHARED_LOADER_HPP

#include "ISerial.hpp"

#include "../../../libraries/finder/DynamicLoader.hpp"
#include "../InfoSharedLoader.hpp"
#include <typeinfo>

//todo make the switchlibcore use dynamicCore and not simple core to auto define simple function;
class SerialSharedLoader {
    public:
        using Params = std::string;

        SerialSharedLoader(Params file) {
            DynamicLoader dl(file);
            // Check if the shared library is a graphic library
            if (!dl.isReady() || std::string(reinterpret_cast<char *(*)()>(dl.findSymbol("getType"))()) != std::string("serial")) {
                std::cerr << "Failed to load: " << file << std::endl;
                return;
            }
            //Core
            createSerial = reinterpret_cast<ISerial *(*)(__int32_t, __int32_t, std::string)>(dl.findSymbol("createSerial"));
            deleteSerial = reinterpret_cast<void (*)(ISerial *serial)>(dl.findSymbol("deleteSerial"));
          
            std::cout << "Loaded: " << file << std::endl;
        }
        
        ~SerialSharedLoader() = default;

    public:
        /**
         * @brief Window
         */
        ISerial *(*createSerial)(int, int, std::string);
        void (*deleteSerial)(ISerial *window);
};

#endif //GRAPHIC_DYNAMIC_LOADER_HPP