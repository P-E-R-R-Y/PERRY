/**
 * @file sdl.cpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief shared graphic/sdl library symbols 
 * @version 0.1
 * @date 2025-01-27
 * 
 * @copyright Copyright (c) 2025
 */


#ifndef SDLLIB_CPP_
#define SDLLIB_CPP_

//window
#include "window/SdlWindow.hpp"
#include "window/SdlCamera.hpp"
//event
#include "event/SdlEvent.hpp"
#include "event/SdlKeyboard.hpp"
#include "event/SdlMouse.hpp"
//graphic
#include "graphic/SdlPolygon.hpp"
#include "graphic/SdlModel.hpp"
#include "graphic/SdlSprite.hpp"

/**
 * @brief create Sdl window 
 * 
 * @param screenWidth
 * @param screenHeight
 * @param title
 * @return graphic::IWindow*
 */
extern "C" graphic::IWindow *createWindow(__int32_t screenWidth, __int32_t screenHeight, std::string title) {
    return new SdlWindow(screenWidth, screenHeight, std::string("Sdl " + title));
}
/**
 * @brief delete Sdl window
 * 
 * @param window
 */
extern "C" void deleteWindow(graphic::IWindow *window) {
    delete window;
}

/**
 * @brief create Sdl camera
 * 
 * @param position
 * @return graphic::ICamera*
 */
extern "C" graphic::ICamera *createCamera(__v3f_t position) {
    return new SdlCamera();
}

/**
 * @brief delete Sdl camera
 * 
 * @param camera
 */
extern "C" void deleteCamera(graphic::ICamera *camera) {
    delete camera;
}

/**
 * @brief Event
 * 
 */

/**
 * @brief create Sdl event
 * 
 * @return graphic::IEvent*
 */
extern "C" graphic::IEvent *createEvent() {
    return new SdlEvent();
}

/**
 * @brief delete Sdl event
 * 
 * @param event
 */
extern "C" void deleteEvent(graphic::IEvent *event) {
    delete event;
}

/**
 * @brief Keyboard
 * 
 * @param event
 * @return graphic::IKeyboard*
 */
extern "C" graphic::IKeyboard *createKeyboard(graphic::IEvent *event) {
    return new SdlKeyboard(event);
}

/**
 * @brief delete Sdl keyboard
 * 
 * @param keyboard
 */
extern "C" void deleteKeyboard(graphic::IKeyboard *keyboard) {
    delete keyboard;
}

/**
 * @brief Mouse
 * 
 * @param event
 * @return graphic::IMouse*
 */
extern "C" graphic::IMouse *createMouse(graphic::IEvent *event) {
    return new SdlMouse(event);
}

/**
 * @brief delete Sdl mouse
 * 
 * @param mouse
 */
extern "C" void deleteMouse(graphic::IMouse *mouse) {
    delete mouse;
}

/**
 * @brief create Sdl polygon
 * 
 * @param points
 * @return graphic::IPolygon*
 */
extern "C" graphic::IPolygon *createPolygon(std::vector<__v2f_t> points) {
    return new SdlPolygon(points);
}

/**
 * @brief delete Sdl polygon
 * 
 * @param polygon
 */
extern "C" void deletePolygon(graphic::IPolygon *polygon) {
    delete polygon;
}

/**
 * @brief create Sdl sprite
 * 
 * @param sprite
 * @return graphic::ISprite*
 */
extern "C" graphic::ISprite *createSprite(std::string sprite) {
    return new SdlSprite(sprite);
}

/**
 * @brief delete Sdl sprite
 * 
 * @param sprite
 */
extern "C" void deleteSprite(graphic::ISprite *sprite) {
    delete sprite;
}

/**
 * @brief create Sdl model
 * 
 * @return graphic::IModel*
 */
extern "C" graphic::IModel *createModel() {
    return new SdlModel();
}

/**
 * @brief delete Sdl model
 * 
 * @param model
 */
extern "C" void deleteModel(graphic::IModel *model) {
    delete model;
}

/**
 * @brief get the name of the library
 * 
 * @return const char*
 */
extern "C" const char *getName() {
    return "sdl\0";
}

/**
 * @brief get the type of the library
 * 
 * @return const char*
 */
extern "C" const char *getType() {
    return "graphic\0";
}

#endif /* !SDLLIB_CPP_ */