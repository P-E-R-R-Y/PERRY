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
                std::cout << 4 << std::endl;
                // if (ml.createWindow == nullptr) {
                    // throw std::runtime_error("Failed to find createWindow function in the library");
                // } else
                    // std::cout << "createWindow Isn't broke" << std::endl;
                // std::cout << 5 << std::endl;
                // std::cout << typeid(ml.createWindow).name() << std::endl;

                DynamicLoader dl(files[nlib]);
                createWindow = reinterpret_cast<IWindow *(*)(__int32_t, __int32_t, std::string)>(dl.findSymbol("createWindow"));
                deleteWindow = reinterpret_cast<void (*)(IWindow *window)>(dl.findSymbol("deleteWindow"));
                createModel2 = reinterpret_cast<IModel2 *(*)(std::string)>(dl.findSymbol("createModel2"));
                deleteModel2 = reinterpret_cast<void (*)(IModel2 *model)>(dl.findSymbol("deleteModel2"));

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
        //vars
        IWindow *window;
        bool up;
        std::size_t nlib;
};
