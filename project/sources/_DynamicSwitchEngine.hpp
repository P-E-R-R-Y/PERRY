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

#ifndef DYNAMICSWITCHENGINE_HPP
#define DYNAMICSWITCHENGINE_HPP

#include "GraphicDynamicCore.hpp"

#include "../../Libraries/DynamicLoader.hpp"
#include <typeinfo>
#include "../../Libraries/ECS/Registry.hpp"
#include "../../Libraries/ECS/ComponentExtractor.hpp"
#include "../../Libraries/Clock.hpp"

//todo make the switchlibcore use dynamicCore and not simple core to auto define simple function;
class DynamicSwitchEngine: public GraphicDynamicCore, public ComponentExtractor {
    public:
        DynamicSwitchEngine(std::vector<std::string> files): clock(), target_delta(Clock::FpsToMs(15)) {
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
                this->Load(_files[nlib]);
                window = createWindow(800, 500, "Perry");
                event = createEvent();
                window->linkEvent(event);
                std::cout << 6 << std::endl;
                // main loop
                this->initHandler();
                std::cout << 7 << std::endl;
                while (window->isOpen()) {
                    clock.start();
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
                    clock.stop();
                    
                    clock.sleep(target_delta - clock.getDelta());
//                    window->beginDraw3();
//                    window->endDraw3();
                }
                window->close();

                deleteWindow(window);
                deleteEvent(event);

                if (nlib < _files.size() - 1) {
                    nlib++;
                } else {
                    break;
                }
            }
            return 0;
        }

    public:
        registry _ecs;

        graphic::IWindow *window;
        graphic::IEvent *event;

        Clock clock;
        std::chrono::milliseconds target_delta;

    protected:
        bool up;
        std::vector<std::string> _files;
        std::size_t nlib;
};

#endif //DYNAMICSWITCHENGINE_HPP