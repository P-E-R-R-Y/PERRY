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
#include <dlfcn.h>
#include <iostream>

int main() {
    std::string name = "sfml";
    void *lib;
    IWindow *(*createWindow)(int, int, std::string);
    void (*deleteWindow)();
    IWindow *window;

    //listLib
    std::cout << std::string("./lib" + name + ".so").c_str() << std::endl;

    lib = dlopen(std::string("./lib" + name + ".so").c_str(), RTLD_NOW);
    if (!lib) {
        std::cerr << "Failed to load shared library: " << dlerror() << std::endl;
        return 84;
    }

    //listFunctions
    createWindow = reinterpret_cast<IWindow *(*)(int, int, std::string)>(dlsym(lib, "createWindow"));
    if (!createWindow) {
        std::cerr << "Failed to load symbol: " << dlerror() << std::endl;
        dlclose(lib);
        return 84;
    }
    deleteWindow = reinterpret_cast<void (*)()>(dlsym(lib, "deleteWindow"));
    if (!deleteWindow) {
        std::cerr << "Failed to load symbol: " << dlerror() << std::endl;
        dlclose(lib);
        return 84;
    }

        //listWindow
    window = createWindow(1920, 1080, "Perry");

    while (window->isOpen()) {
        window->clear();
        if (!window->isOpen()) {
            window->close();
        }
        window->display();
    }

    deleteWindow();
    return 0;
}