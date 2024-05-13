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
#include "../../Interfaces/core/ICore.hpp"
#include "../DynamicLoader.hpp"
#include <typeinfo>

//todo make the switchlibcore use dynamicCore and not simple core to auto define simple function;
class DynamicSwitchLibCore: public ICore/*DynamicCore*/ {
    public:
        DynamicSwitchLibCore(std::vector<std::string> files)/*: DynamicCore()*/ {

                _files = files; 

                up = true;
                nlib = 0;
        }

        ~DynamicSwitchLibCore() = default;

        int Run () override {
            if (_files.empty()) {
                throw std::runtime_error("No libraries to load");
            }
            while (up) {
                DynamicLoader dl(_files[nlib]);
                //Core
                createWindow = reinterpret_cast<graphic3::IWindow *(*)(__int32_t, __int32_t, std::string)>(dl.findSymbol("createWindow"));
                deleteWindow = reinterpret_cast<void (*)(graphic3::IWindow *window)>(dl.findSymbol("deleteWindow"));
                //Event
                createEvent = reinterpret_cast<graphic3::IEvent *(*)()>(dl.findSymbol("createEvent"));
                deleteEvent = reinterpret_cast<void (*)(graphic3::IEvent *event)>(dl.findSymbol("deleteEvent"));
                createKeyboard = reinterpret_cast<graphic3::IKeyboard *(*)()>(dl.findSymbol("createKeyboard"));
                deleteKeyboard = reinterpret_cast<void (*)(graphic3::IKeyboard *keyboard)>(dl.findSymbol("deleteKeyboard"));
                createMouse = reinterpret_cast<graphic3::IMouse *(*)()>(dl.findSymbol("createMouse"));
                deleteMouse = reinterpret_cast<void (*)(graphic3::IMouse *mouse)>(dl.findSymbol("deleteMouse"));
                //Graphics
                createPolygon = reinterpret_cast<graphic3::IPolygon *(*)(std::vector<__v2f_t>)>(dl.findSymbol("createPolygon"));
                deletePolygon = reinterpret_cast<void (*)(graphic3::IPolygon *model)>(dl.findSymbol("deletePolygon"));
                createSprite = reinterpret_cast<graphic3::ISprite *(*)(std::string)>(dl.findSymbol("createSprite"));
                deleteSprite = reinterpret_cast<void (*)(graphic3::ISprite *model)>(dl.findSymbol("deleteSprite"));
                //3D
                createCamera = reinterpret_cast<graphic3::ICamera *(*)()>(dl.findSymbol("createCamera"));
                deleteCamera = reinterpret_cast<void (*)(graphic3::ICamera *camera)>(dl.findSymbol("deleteCamera"));
                createModel = reinterpret_cast<graphic3::IModel *(*)()>(dl.findSymbol("createModel"));
                deleteModel = reinterpret_cast<void (*)(graphic3::IModel *model3)>(dl.findSymbol("deleteModel"));


                std::cout << _files[nlib] << std::endl;
                // if (ml.Init(files[nlib]) == false)
                    // throw std::runtime_error("Failed to load the librarie functions");
                // if (ml.createWindow == nullptr) {
                    // throw std::runtime_error("Failed to find createWindow function in the library");
                // } else
                    // std::cout << "createWindow Isn't broke" << std::endl;
                // std::cout << 5 << std::endl;
                // std::cout << typeid(ml.createWindow).name() << std::endl;

//                IWindow *window = ml.createWindow(800, 500, "Perry");
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

                // ml.deleteWindow(window);

                if (nlib < _files.size() - 1) {
                    nlib++;
                } else {
                    break;
                }
            }
            return 0;
        }

    protected:
        /**
         * @brief Shared Libraries Files Path
         * 
         */
        std::vector<std::string> _files;

        /**
         * @brief Window
         * 
         */

        graphic3::IWindow *(*createWindow)(int, int, std::string);
        void (*deleteWindow)(graphic3::IWindow *window);

        /**
         * @brief Event
         * 
         */

        graphic3::IEvent *(*createEvent)();
        void (*deleteEvent)(graphic3::IEvent *event);
        graphic3::IKeyboard *(*createKeyboard)();
        void (*deleteKeyboard)(graphic3::IKeyboard *keyboard);

        graphic3::IMouse *(*createMouse)();
        void (*deleteMouse)(graphic3::IMouse *mouse);
        
        /**
         * @brief Graphics
         * 
         */

        // polygon
        graphic3::IPolygon *(*createPolygon)(std::vector<__v2f_t> points);
        void (*deletePolygon)(graphic3::IPolygon *polygon);
        // sprite
        graphic3::ISprite *(*createSprite)(std::string);
        void (*deleteSprite)(graphic3::ISprite *sprite);
        //camera
        graphic3::ICamera *(*createCamera)();
        void (*deleteCamera)(graphic3::ICamera *camera);
        //3D
        graphic3::IModel *(*createModel)();
        void (*deleteModel)(graphic3::IModel *model);

        /**
         * @brief Init Handler
         * 
         */
        graphic3::IWindow *window;
        graphic3::IEvent *event;
        bool up;
        std::size_t nlib;
};
