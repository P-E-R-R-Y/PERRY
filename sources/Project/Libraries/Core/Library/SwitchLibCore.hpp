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

#include "../Type/DynamicCore.hpp"
#include <typeinfo>

//todo make the switchlibcore use dynamicCore and not simple core to auto define simple function;
class SwitchLibCore: public Core/*DynamicCore*/ {
    public:
        SwitchLibCore()/*: DynamicCore()*/ {
                up = true;
                nlib = 0;
        }

        ~SwitchLibCore() = default;

        int Run (std::vector<std::string> files) override {
                while (up) {
                // if (ml.Init(files[nlib]) == false)
                    // throw std::runtime_error("Failed to load the librarie functions");
                std::cout << files[nlib] << std::endl;
                // if (ml.createWindow == nullptr) {
                    // throw std::runtime_error("Failed to find createWindow function in the library");
                // } else
                    // std::cout << "createWindow Isn't broke" << std::endl;
                // std::cout << 5 << std::endl;
                // std::cout << typeid(ml.createWindow).name() << std::endl;

                DynamicLoader dl(files[nlib]);
                //Core
                createWindow = reinterpret_cast<IWindow *(*)(__int32_t, __int32_t, std::string)>(dl.findSymbol("createWindow"));
                deleteWindow = reinterpret_cast<void (*)(IWindow *window)>(dl.findSymbol("deleteWindow"));
                //Graphics
                createModel2 = reinterpret_cast<IModel2 *(*)(std::string)>(dl.findSymbol("createModel2"));
                deleteModel2 = reinterpret_cast<void (*)(IModel2 *model)>(dl.findSymbol("deleteModel2"));
                //3D
                createCamera = reinterpret_cast<ICamera *(*)()>(dl.findSymbol("createCamera"));
                deleteCamera = reinterpret_cast<void (*)(ICamera *camera)>(dl.findSymbol("deleteCamera"));
                createModel3 = reinterpret_cast<IModel3 *(*)()>(dl.findSymbol("createModel3"));
                deleteModel3 = reinterpret_cast<void (*)(IModel3 *model3)>(dl.findSymbol("deleteModel3"));

//                IWindow *window = ml.createWindow(800, 500, "Perry");
                window = createWindow(800, 500, "Perry");
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

                if (nlib < files.size() - 1) {
                    nlib++;
                } else {
                    break;
                }
            }
            return 0;
        }

    protected:
        //func
        // window
        IWindow *(*createWindow)(int, int, std::string);
        void (*deleteWindow)(IWindow *window);
        // model
        IModel2 *(*createModel2)(std::string);
        void (*deleteModel2)(IModel2 *model);
        //camera
        ICamera *(*createCamera)();
        void (*deleteCamera)(ICamera *camera);
        //3D
        IModel3 *(*createModel3)();
        void (*deleteModel3)(IModel3 *model3);

        //vars
        IWindow *window;
        bool up;
        std::size_t nlib;
};
