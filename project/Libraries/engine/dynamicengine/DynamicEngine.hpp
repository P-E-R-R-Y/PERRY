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

#ifndef DYNAMICSWITCH_HPP

#include "../../core/dynamic/DynamicCore.hpp"
#include "../../DynamicLoader.hpp"
#include <typeinfo>

//todo make the switchlibcore use dynamicCore and not simple core to auto define simple function;
class DynamicSwitchEngine: public DynamicCore/*DynamicCore*/ {
    public:
        DynamicSwitchEngine(std::vector<std::string> files) {

                _files = files; 

                up = true;
                nlib = 0;
        }

        ~DynamicSwitchEngine() = default;

        int Run () override {
            if (_files.empty()) {
                throw std::runtime_error("No libraries to load");
            }
            while (up) {
                Load(_files[nlib]);
                window = createWindow(800, 500, "Perry");
                event = createEvent();
                window->linkEvent(event);
                std::cout << 6 << std::endl;
                // main loop
                this->initHandler();
                std::cout << 7 << std::endl;
                while (window->isOpen()) {
                    if (window->isPoll()) {
                        while (window->pollEvent()) {
                            window->eventClose();
                            this->eventHandler();
                        }
                    } else {
                        window->eventClose();
                        this->eventHandler();
                    }
                    this->updateHandler();
                    window->beginDraw();
                    this->displayHandler();
                    window->endDraw();
//                    window->beginDraw3();
                }
                window->close();

                if (nlib < _files.size() - 1) {
                    nlib++;
                } else {
                    break;
                }
            }
            return 0;
        }

    protected:
        bool up;
        std::vector<std::string> _files;
        std::size_t nlib;
};
