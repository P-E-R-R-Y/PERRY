/**
 *
 * File: main.cpp (header.v2)
 * Created Date: Tue 14/03/2023
 * Project: PERRY
 * Author: Perry Chouteau
 *
 * Last Modified: Sat 18/03/2023
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
    protected:
        virtual ~Core() = default;

        virtual int Run(std::vector<std::string> files) = 0;

        virtual void initHandler() = 0;

        virtual void eventHandler() = 0;

        virtual void updateHandler() = 0;

        virtual void displayHandler() = 0;
};

class SwitchCore: public Core{
    public:
        SwitchCore(): Core() {
            up = true;
            nlib = 0;
        }

        int Run (std::vector<std::string> files) override {
            while (up) {
                DynamicLoader dl(files[nlib]);
                std::cout << files[nlib] << std::endl;
                IWindow *(*createWindow)(int, int, std::string) = reinterpret_cast<IWindow *(*)(int, int, std::string)>(dl.findSymbol("createWindow"));
                void (*deleteWindow)(IWindow * window) = reinterpret_cast<void (*)(IWindow * window)>(dl.findSymbol("deleteWindow"));

                if (createWindow == nullptr || deleteWindow == nullptr)
                    continue;
                IWindow *window = createWindow(800, 500, "Perry");
                // main loop
                this->initHandler();
                while (window->isOpen()) {
                    if (window->isPoll()) {
                        while (window->pollEvent()) {
                            window->eventClose();
                            this->eventHandler();
                        }
                    }
                      else {
                        window->eventClose();
                        this->eventHandler();
                    }
                    this->updateHandler();
                    window->beginDraw();
                    this->displayHandler();
                    window->endDraw();

                }
                window->close();

                deleteWindow(window);

                nlib += (nlib < files.size() - 1) ? 1 : -nlib;
            }
            return 0;
        }

    protected:
        bool up;
        std::size_t nlib;
};

class SimpleCore: public Core {
    public:
        SimpleCore(): Core() {
        }

        ~SimpleCore() {};

    protected:
        void initHandler() override {
            std::cout << "initHandler ";
        }

        void eventHandler() override {
            std::cout << "eventHandler ";
        }

        void updateHandler() override {
            std::cout << "updateHandler ";
        }

        void displayHandler() override {
            std::cout << "displayHandler" << std::endl;
        }

    private:
        //vars
};

class SimpleSwitchCore: public SimpleCore, public SwitchCore {
    public:

        SimpleSwitchCore(): SimpleCore(), SwitchCore() { }

        int Run(std::vector<std::string> files) override {
            return SwitchCore::Run(files);
        }

    protected:

        void initHandler() override {
            SimpleCore::initHandler();
        }

        void eventHandler() override {
            SimpleCore::eventHandler();
        }

        void updateHandler() override {
            SimpleCore::updateHandler();
        }

        void displayHandler() override {
            SimpleCore::displayHandler();
        }

};

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

    SimpleSwitchCore ssc;

    ssc.Run(files);

    return 0;
}
