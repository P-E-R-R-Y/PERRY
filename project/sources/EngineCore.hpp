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

#ifndef ENGINECORE_HPP
#define ENGINECORE_HPP

#include "GraphicDynamicCore.hpp"

#include "../../Libraries/DynamicLoader.hpp"
#include <typeinfo>
#include "../../Libraries/ECS/Registry.hpp"
#include "../../Libraries/ECS/ComponentExtractor.hpp"
#include "../../Libraries/Clock.hpp"

//todo make the switchlibcore use dynamicCore and not simple core to auto define simple function;
class EngineCore: public ICore, public ComponentExtractor {
    public:
        EngineCore() {
                up = true;                
        }

        ~EngineCore() = default;

        int start () {
            this->initHandler();
            while (up) {
                this->eventHandler();
                this->updateHandler();
                this->displayHandler();
            }
            return 0;
        }

        virtual void initHandler() = 0;
        virtual void eventHandler() = 0;
        virtual void updateHandler() = 0;
        virtual void displayHandler() = 0;

    public:
        registry _ecs;
        bool up;
};

#endif //ENGINECORE_HPP