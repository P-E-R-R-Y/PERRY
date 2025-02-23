/**
 * @file main.cpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-06
 */

#include "window/SdlWindow.hpp"

#include "event/SdlEvent.hpp"
#include "event/SdlKeyboard.hpp"
#include "event/SdlMouse.hpp"

#include "graphic/SdlSprite.hpp"
#include "graphic/SdlText.hpp"

#include "audio/SdlSound.hpp"
#include "audio/SdlMusic.hpp"

// window

extern "C" graphic::IWindow *createWindow() {
    return new SdlWindow(800, 600, "SDL2 Text Example");
}

extern "C" void deleteWindow(graphic::IWindow *window) {
    delete window;
}

// event

extern "C" graphic::IEvent *createEvent() {
    return new SdlEvent();
}

extern "C" void deleteEvent(graphic::IEvent *event) {
    delete event;
}

extern "C" graphic::IKeyboard *createKeyboard(graphic::IEvent *event) {
    return new SdlKeyboard(event);
}

extern "C" void deleteKeyboard(graphic::IKeyboard *keyboard) {
    delete keyboard;
}

extern "C" graphic::IMouse *createMouse(graphic::IEvent *event) {
    return new SdlMouse(event);
}

extern "C" void deleteMouse(graphic::IMouse *mouse) {
    delete mouse;
}

// graphic

extern "C" graphic::ISprite *createSprite(std::string path) {
    return new SdlSprite(path);
}

extern "C" void deleteSprite(graphic::ISprite *sprite) {
    delete sprite;
}

extern "C" graphic::IText *createText(std::string data, std::string font) {
    return new SdlText(data, font);
}

extern "C" void deleteText(graphic::IText *text) {
    delete text;
}

// audio

extern "C" graphic::ISound *createSound(std::string sound) {
    return new SdlSound(sound);
}

extern "C" void deleteSound(graphic::ISound *sound) {
    delete sound;
}

extern "C" graphic::IMusic *createMusic(std::string music) {
    return new SdlMusic(music);
}

extern "C" void deleteMusic(graphic::IMusic *music) {
    delete music;
}
