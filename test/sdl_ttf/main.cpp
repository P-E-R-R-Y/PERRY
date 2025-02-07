/**
 * @file main.cpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-06
 */

// #include "staticsdl.hpp"
// 
// int main() {
    // return function();
// }

#include <iostream>
#include <dlfcn.h>

#include "IWindow.hpp"
#include "IText.hpp"

int main() {
    // Load the shared library
    void* handle = dlopen("./libsharedsdl.dylib", RTLD_NOW);
    if (!handle) {
        std::cerr << "Failed to load library: " << dlerror() << std::endl;
        return 1;
    }

    // Load the function
    typedef int (*FunctionType)();
    typedef graphic::IWindow *(*CreateWindowType)(__int32_t, __int32_t, std::string);
    typedef void (*DeleteWindowType)(graphic::IWindow *);
    typedef graphic::IText *(*CreateTextType)(std::string, std::string);
    typedef void (*DeleteTextType)(graphic::IText *);

    CreateWindowType createWindow = (CreateWindowType)dlsym(handle, "createWindow");
    DeleteWindowType deleteWindow = (DeleteWindowType)dlsym(handle, "deleteWindow");
    CreateTextType createText = (CreateTextType)dlsym(handle, "createText");
    DeleteTextType deleteText = (DeleteTextType)dlsym(handle, "deleteText");

    if (!createWindow || !deleteWindow || !createText || !deleteText) {
        std::cerr << "Failed to load function: " << dlerror() << std::endl;
        dlclose(handle);
        return 1;
    }

    // Call the function
    graphic::IWindow *window = createWindow(800, 600, "SDL2 Text Example");
    if (!window) {
        std::cerr << "Failed to create window" << std::endl;
        dlclose(handle);
        return 1;
    }

    graphic::IText *text = createText("Hello, SDL2!", "assets/noto.ttf");
    if (!text) {
        std::cerr << "Failed to create text" << std::endl;
        deleteWindow(window);
        dlclose(handle);
        return 1;
    }

    while (window->isOpen()) {
        while (window->pollEvent()) {
            window->close();
        }
        window->beginDraw();
        window->drawText(text);
        window->endDraw();
    }

    dlclose(handle);

    return 0;
}