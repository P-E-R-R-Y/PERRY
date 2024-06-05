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

#ifndef DYNAMICCORE_HPP
#define DYNAMICCORE_HPP

#include "../../../Interfaces/core/ICore.hpp"
#include "../../../Interfaces/graphic/window/IWindow.hpp"

#include "../../../Interfaces/graphic/event/IEvent.hpp"
#include "../../../Interfaces/graphic/event/IKeyboard.hpp"
#include "../../../Interfaces/graphic/event/IMouse.hpp"

#include "../../../Interfaces/graphic/graphic/IPolygon.hpp"
#include "../../../Interfaces/graphic/graphic/ISprite.hpp"

#include "../../../Interfaces/graphic/window/ICamera.hpp"
#include "../../../Interfaces/graphic/graphic/IModel.hpp"
#include "../../Libraries/DynamicLoader.hpp"
#include <typeinfo>

//todo make the switchlibcore use dynamicCore and not simple core to auto define simple function;
class DynamicCore: public ICore {
    public:
        ~DynamicCore() = default;

    protected:
        /**
         * @brief Window
         */
        graphic::IWindow *(*createWindow)(int, int, std::string);
        void (*deleteWindow)(graphic::IWindow *window);

        /**
         * @brief Event
         */
        graphic::IEvent *(*createEvent)();
        void (*deleteEvent)(graphic::IEvent *event);
        
        graphic::IKeyboard *(*createKeyboard)(graphic::IEvent *event);
        void (*deleteKeyboard)(graphic::IKeyboard *keyboard);

        graphic::IMouse *(*createMouse)(graphic::IEvent *event);
        void (*deleteMouse)(graphic::IMouse *mouse);
        
        /**
         * @brief Graphics
         */
        // polygon
        graphic::IPolygon *(*createPolygon)(std::vector<__v2f_t> points);
        void (*deletePolygon)(graphic::IPolygon *polygon);
        // sprite
        graphic::ISprite *(*createSprite)(std::string);
        void (*deleteSprite)(graphic::ISprite *sprite);
        //camera
        graphic::ICamera *(*createCamera)();
        void (*deleteCamera)(graphic::ICamera *camera);
        //model
        graphic::IModel *(*createModel)();
        void (*deleteModel)(graphic::IModel *model);
    
    protected:
        void Load(std::string file) {
            DynamicLoader dl(file);

            //Core
            createWindow = reinterpret_cast<graphic::IWindow *(*)(__int32_t, __int32_t, std::string)>(dl.findSymbol("createWindow"));
            deleteWindow = reinterpret_cast<void (*)(graphic::IWindow *window)>(dl.findSymbol("deleteWindow"));

            //Event
            createEvent = reinterpret_cast<graphic::IEvent *(*)()>(dl.findSymbol("createEvent"));
            deleteEvent = reinterpret_cast<void (*)(graphic::IEvent *event)>(dl.findSymbol("deleteEvent"));

            createKeyboard = reinterpret_cast<graphic::IKeyboard *(*)(graphic::IEvent *event)>(dl.findSymbol("createKeyboard"));
            deleteKeyboard = reinterpret_cast<void (*)(graphic::IKeyboard *keyboard)>(dl.findSymbol("deleteKeyboard"));

            createMouse = reinterpret_cast<graphic::IMouse *(*)(graphic::IEvent *event)>(dl.findSymbol("createMouse"));
            deleteMouse = reinterpret_cast<void (*)(graphic::IMouse *mouse)>(dl.findSymbol("deleteMouse"));

            //Graphics
            createPolygon = reinterpret_cast<graphic::IPolygon *(*)(std::vector<__v2f_t>)>(dl.findSymbol("createPolygon"));
            deletePolygon = reinterpret_cast<void (*)(graphic::IPolygon *model)>(dl.findSymbol("deletePolygon"));

            createSprite = reinterpret_cast<graphic::ISprite *(*)(std::string)>(dl.findSymbol("createSprite"));
            deleteSprite = reinterpret_cast<void (*)(graphic::ISprite *model)>(dl.findSymbol("deleteSprite"));

            //3D
            createCamera = reinterpret_cast<graphic::ICamera *(*)()>(dl.findSymbol("createCamera"));
            deleteCamera = reinterpret_cast<void (*)(graphic::ICamera *camera)>(dl.findSymbol("deleteCamera"));

            createModel = reinterpret_cast<graphic::IModel *(*)()>(dl.findSymbol("createModel"));
            deleteModel = reinterpret_cast<void (*)(graphic::IModel *model3)>(dl.findSymbol("deleteModel"));

            std::cout << "Loaded: " << file << std::endl;
        }
};

#endif //DYNAMICCORE_HPP