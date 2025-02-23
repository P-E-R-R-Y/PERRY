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

#include "IEvent.hpp"
#include "IKeyboard.hpp"

int main() {
    // Load the shared library
    void* handle = dlopen("./libsdlgraphic.dylib", RTLD_NOW);
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
    typedef graphic::IEvent *(*CreateEventType)();
    typedef void (*DeleteEventType)(graphic::IEvent *);
    typedef graphic::IKeyboard *(*CreateKeyboardType)(graphic::IEvent *);
    typedef void (*DeleteKeyboardType)(graphic::IKeyboard *);

    CreateWindowType createWindow = (CreateWindowType)dlsym(handle, "createWindow");
    DeleteWindowType deleteWindow = (DeleteWindowType)dlsym(handle, "deleteWindow");
    CreateTextType createText = (CreateTextType)dlsym(handle, "createText");
    DeleteTextType deleteText = (DeleteTextType)dlsym(handle, "deleteText");
    CreateEventType createEvent = (CreateEventType)dlsym(handle, "createEvent");
    DeleteEventType deleteEvent = (DeleteEventType)dlsym(handle, "deleteEvent");
    CreateKeyboardType createKeyboard = (CreateKeyboardType)dlsym(handle, "createKeyboard");
    DeleteKeyboardType deleteKeyboard = (DeleteKeyboardType)dlsym(handle, "deleteKeyboard");

    if (!createWindow || !deleteWindow || !createText || !deleteText || !createEvent || !deleteEvent || !createKeyboard || !deleteKeyboard) {
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

    std::cout << "A" << std::endl;

    graphic::IText *text = createText("Hello, SDL2!", "assets/noto.ttf");
    if (!text) {
        std::cerr << "Failed to create text" << std::endl;
        deleteWindow(window);
        dlclose(handle);
        return 1;
    }

    graphic::IEvent *event = createEvent();
    if (!event) {
        std::cerr << "Failed to create event" << std::endl;
        deleteText(text);
        deleteWindow(window);
        dlclose(handle);
        return 1;
    }

    window->linkEvent(event);

    graphic::IKeyboard *keyboard = createKeyboard(event);
    if (!keyboard) {
        std::cerr << "Failed to create keyboard" << std::endl;
        deleteEvent(event);
        deleteText(text);
        deleteWindow(window);
        dlclose(handle);
        return 1;
    }

    std::cout << "B" << std::endl;

    while (window->isOpen()) {
        while (window->pollEvent()) {
            if (keyboard->isKeyDown(graphic::IKeyboard::Keys::KEY_ESCAPE)) {
                window->close();
            }
        }
        std::cout << "C" << std::endl;
        window->beginDraw();
        std::cout << "C" << std::endl;
        window->drawText(text);
        std::cout << "D" << std::endl;
        window->endDraw();
    }

    dlclose(handle);

    return 0;
}