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

#ifndef GRAPHIC_SHARED_LOADER_HPP
#define GRAPHIC_SHARED_LOADER_HPP

#include "../../../interfaces/core/ICore.hpp"
#include "../../../interfaces/graphic/window/IWindow.hpp"

#include "../../../interfaces/graphic/event/IEvent.hpp"
#include "../../../interfaces/graphic/event/IKeyboard.hpp"
#include "../../../interfaces/graphic/event/IMouse.hpp"

#include "../../../interfaces/graphic/graphic/IPolygon.hpp"
#include "../../../interfaces/graphic/graphic/ISprite.hpp"

#include "../../../interfaces/graphic/window/ICamera.hpp"
#include "../../../interfaces/graphic/graphic/IModel.hpp"

#include "../../../libraries/finder/DynamicLoader.hpp"
#include "../InfoSharedLoader.hpp"
#include <typeinfo>

//todo make the switchlibcore use dynamicCore and not simple core to auto define simple function;
class GraphicSharedLoader {
    public:
        using Params = std::string;

        GraphicSharedLoader(Params file) {
            DynamicLoader dl(file);
            // Check if the shared library is a graphic library
            if (!dl.isReady() || std::string(reinterpret_cast<char *(*)()>(dl.findSymbol("getType"))()) != std::string("graphic")) {
                std::cerr << "Failed to load: " << file << std::endl;
                return;
            }
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
        
        ~GraphicSharedLoader() = default;

    public:
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
};

#endif //GRAPHIC_DYNAMIC_LOADER_HPP