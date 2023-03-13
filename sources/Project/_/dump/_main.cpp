/**
 *
 * File: _main.cpp
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

#include "Sfml/Window/SfmlWindow.hpp"
#include <dlfcn.h>
#include <iostream>

int main() {
    std::vector<std::string> listName = {"sfml"};
    std::vector<void *> listLib;
    std::vector<void (*)(int, int, std::string)> listCreateWindow;
    std::vector<void (*)()> listDeleteWindow;
    std::vector<IWindow *> ListWindow;

    for (int i = 0; i < listName.size(); i++) {
        //listLib
        listLib.push_back(dlopen(std::string("./lib" + listName[i] + ".so").c_str(), RTLD_NOW));
        if (!listLib[i]) {
            std::cerr << "Failed to load shared library: " << dlerror() << std::endl;
            return 84;
        }

        //listFunctions
        listCreateWindow.push_back(reinterpret_cast<void (*)(int, int, std::string)>(dlsym(listLib[i], "createWindow")));
        if (!listCreateWindow[i]) {
            std::cerr << "Failed to load symbol: " << dlerror() << std::endl;
            dlclose(listLib[i]);
            return 84;
        }
        listDeleteWindow.push_back(reinterpret_cast<void (*)()>(dlsym(listLib[i], "deleteWindow")));
        if (!listDeleteWindow[i]) {
            std::cerr << "Failed to load symbol: " << dlerror() << std::endl;
            dlclose(listLib[i]);
            return 84;
        }

        //listWindow
        listCreateWindow[i](1920, 1080, "Perry");
    }

    while (ListWindow[0]->isOpen()) {
        ListWindow[0]->clear();
        if (!ListWindow[0]->isOpen()) {
            ListWindow[0]->close();
        }
        ListWindow[0]->display();
    }

    for (int i = 0; i < listName.size(); i++) {
        listDeleteWindow[i]();
        dlclose(listLib[i]);
    }
    return 0;
}