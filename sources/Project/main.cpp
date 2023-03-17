/**
 *
 * File: main.cpp
 * Created Date: Su Mar 2023
 * Project: PERRY
 * Author: Perry Chouteau
 *
 * Last Modified: Sun Mar 12 2023
 * Modified By: Perry Chouteau
 *
 * Copyright (c) 2023-2033 Perry Chouteau
 *
 **/

#include "Interface/Window/IWindow.hpp"
#include "Libraries/DynamicLoader.hpp"
#include <dlfcn.h>
#include <map>
#include <iostream>
#include <utility>
#include <filesystem>
#include <sys/stat.h>
class Core {
    public:
        Core() {
            up = true;
            nlib = 1;
        }

        int Run (std::vector<std::string> files) {
//            // load library
//            std::cout << 1 << std::endl;
//            for (auto file: files) {
//            std::string file = files[1];
//            std::string key = file.substr(libPath.size() + std::string("lib").size(), file.size() - (libPath.size() + std::string("lib").size() + std::string(".so").size()));
//
//                std::cout << ">>>" << key << std::endl;
//
//                mdl.emplace(key, DynamicLoader(file));
//            }
//
//            std::cout << "insert: " << key << " " << file << std::endl;
//            keys.push_back(key);
//            mdl.emplace(key, DynamicLoader(file));
//            mdl[key].findSymbol("");
//            mdl.at(key);
//            std::cout << "_" << std::endl;
//            std::cout << 2 << std::endl;
//            // handler
//            while (up) {
//                up = false;
//                // variables
//                std::cout << 2.3 << std::endl;
//                std::cout << keys.at(nlib) << std::endl;
//
//                for (auto pair: mdl) {
//                    std::cout << "|" << pair.first << std::endl;
//                    std::cout << "|" << pair.second.isReady() << std::endl;
//                }
//                std::cout << "|> " << (mdl.at(key/*keys.at(0)*/).isReady()) << std::endl;
//                DynamicLoader dl(files[0]);
//
//                DynamicLoader dl = mdl.at(key/*keys.at(0)*/);
//
//                IWindow *(*createWindow)(int, int, std::string) = reinterpret_cast<IWindow *(*)(int, int, std::string)>(dl.findSymbol("createWindow"));
//                void (*deleteWindow)() = reinterpret_cast<void (*)()>(dl.findSymbol("deleteWindow"));
//
//                if (createWindow == nullptr)
//                    std::cout << "error" << std::endl;
//                IWindow *window = createWindow(800, 500, "Perry");
//                // handle game
//                std::cout << 3 << std::endl;
//                initHandler();
//                while (window->isOpen()) {
//                    //event
//                    if (window->isPoll()) {
//                        while (window->pollEvent())
//                            eventHandler();
//                    } else {
//                        eventHandler();
//                    }
//                    window->beginDraw();
//                    displayHandler();
//                    window->endDraw();
//                }
//               deleteWindow();
//
//                // change librarie
//                nlib += (nlib < mdl.size()) ? 1 : -nlib;
//            }

            while (up) {

                DynamicLoader dl(files[nlib]);
                std::cout << files[nlib] << std::endl;
                IWindow *(*createWindow)(int, int, std::string) = reinterpret_cast<IWindow *(*)(int, int, std::string)>(dl.findSymbol("createWindow"));
                void (*deleteWindow)(IWindow * window) = reinterpret_cast<void (*)(IWindow * window)>(dl.findSymbol("deleteWindow"));

                if (createWindow == nullptr || deleteWindow == nullptr)
                    continue;
                IWindow *window = createWindow(800, 500, "Perry");
                // main loop
                while (window->isOpen()) {
                    if (window->isPoll()) {
                        while (window->pollEvent()) {
                            window->eventClose();
                        }
                    }
                      else {
                        //ask_event()
                        window->eventClose();
                    }
                    window->beginDraw();
                    window->endDraw();
                }
                window->close();

                deleteWindow(window);

                nlib += (nlib < files.size() - 1) ? 1 : -nlib;
            }
            return 0;
        }

    protected:

        virtual void initHandler() = 0;

        virtual void eventHandler() = 0;

        virtual void displayHandler() = 0;

    protected:
        bool up;
        std::size_t nlib;
        std::vector<std::string> keys;
        std::map<std::string, DynamicLoader> mdl;
};

class SimpleCore: public Core {
    public:
        SimpleCore(): Core() {
        }

    protected:
        void initHandler() override {
        }

        void eventHandler() override {

        }

        void displayHandler() override {
            ;
        }

    private:
        //vars
};

/*int dynaLoad(std::vector<std::string> flags) {
//    bool app.isRunning(true);

    void *lib;
    IWindow *(*createWindow)(int, int, std::string);
    void (*deleteWindow)();
    IWindow *window;

    std::map<std::string, DynamicLoader> dl;

     for (auto name: flags)
        dl.emplace(name, DynamicLoader(std::string("./Shared/lib" + name + ".so")));

//    while (close)

    createWindow = reinterpret_cast<IWindow *(*)(int, int, std::string)>(dl.at(flags.at(0)).findSymbol("createWindow"));
    deleteWindow = reinterpret_cast<void (*)()>(dl.at(flags.at(0)).findSymbol("deleteWindow"));
    if (!createWindow || !deleteWindow)
        return 84;

    window = createWindow(800, 500, "Perry");

    while (window->isOpen()) {
        if (!window->isOpen()) {
            window->close();
        }
        window->beginDraw();
        window->endDraw();
    }

    deleteWindow();

    return 0;
}*/

#include "Libraries/FlagParser.hpp"
#include "Libraries/FileSearcher.hpp"

int main(int ac, char **av) {
//    FlagParser fp(ac, av);
//    std::vector<std::string> flagL = fp.get("l");
//    for (auto i: flagL) {
//        std::cout << i << std::endl;
//    }
//    dynaLoad(fp.get("l"));
/*------------------------------------------------------------------------------*/

    std::vector<std::string> files = FileSearcher::searchPathFiles("./Shared/", "so");
    for(auto& i: files)
        std::cout << i << std::endl;

    SimpleCore sc;

    sc.Run(files);

    return 0;
}
