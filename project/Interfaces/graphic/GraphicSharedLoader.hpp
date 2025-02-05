/**
 * @file GraphicSharedLoader.hpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-29
 * 
 * @addtogroup graphic
 * @{
 */

#ifndef GRAPHIC_SHARED_LOADER_HPP
#define GRAPHIC_SHARED_LOADER_HPP

#include "../../core/ICore.hpp"
#include "../window/IWindow.hpp"

#include "event/IEvent.hpp"
#include "event/IKeyboard.hpp"
#include "event/IMouse.hpp"

#include "graphic/IPolygon.hpp"
#include "graphic/ISprite.hpp"
#include "graphic/IText.hpp"

#include "audio/ISound.hpp"
#include "audio/IMusic.hpp"

#include "window/ICamera.hpp"
#include "graphic/IModel.hpp"

#include "../../../libraries/finder/DynamicLoader.hpp"
#include "../InfoSharedLoader.hpp"
#include <typeinfo>

/**
 * @brief define graphic interfaces
 */
namespace graphic {

    /**
     * @brief Use to dynamicaly load Graphic shared library
     */
    class GraphicSharedLoader {
        public:
            using Params = std::string;

            /**
             * @brief Construct a new Graphic Shared Loader object with every symbols from the shared library
             * 
             * @param file 
             */
            GraphicSharedLoader(std::string file): dl(file) {
                // Check if the shared library is a graphic library
                std::cout << "A" << std::endl;

                if (!dl.isReady() || std::string(reinterpret_cast<char *(*)()>(dl.findSymbol("getType"))()) != std::string("graphic")) {
                    std::cerr << "Failed to load: " << file << std::endl;
                    return;
                }
                std::cout << "A" << std::endl;
                //Core
                createWindow = reinterpret_cast<graphic::IWindow *(*)(__int32_t, __int32_t, std::string)>(dl.findSymbol("createWindow"));
                deleteWindow = reinterpret_cast<void (*)(graphic::IWindow *window)>(dl.findSymbol("deleteWindow"));

                //Event
                createEvent = reinterpret_cast<graphic::IEvent *(*)()>(dl.findSymbol("createEvent"));
                deleteEvent = reinterpret_cast<void (*)(graphic::IEvent *event)>(dl.findSymbol("deleteEvent"));

                createKeyboard = reinterpret_cast<graphic::IKeyboard *(*)(graphic::IEvent *event)>(dl.findSymbol("createKeyboard"));
                deleteKeyboard = reinterpret_cast<void (*)(graphic::IKeyboard *keyboard)>(dl.findSymbol("deleteKeyboard"));

                createMouse = reinterpret_cast<graphic::IMouse *(*)(graphic::IEvent *event)>(dl.findSymbol("createMouse"));
                deleteMouse = reinterpret_cast<void (*)(graphic::IMouse *mouse)>(dl.findSymbol("deleteMouse"));

                //Graphics
                createPolygon = reinterpret_cast<graphic::IPolygon *(*)(std::vector<__v2f_t>)>(dl.findSymbol("createPolygon"));
                deletePolygon = reinterpret_cast<void (*)(graphic::IPolygon *model)>(dl.findSymbol("deletePolygon"));

                createSprite = reinterpret_cast<graphic::ISprite *(*)(std::string)>(dl.findSymbol("createSprite"));
                deleteSprite = reinterpret_cast<void (*)(graphic::ISprite *model)>(dl.findSymbol("deleteSprite"));

                createText = reinterpret_cast<graphic::IText *(*)(std::string, std::string)>(dl.findSymbol("createText"));
                deleteText = reinterpret_cast<void (*)(graphic::IText *model)>(dl.findSymbol("deleteText"));

                //3D
                createCamera = reinterpret_cast<graphic::ICamera *(*)()>(dl.findSymbol("createCamera"));
                deleteCamera = reinterpret_cast<void (*)(graphic::ICamera *camera)>(dl.findSymbol("deleteCamera"));

                createModel = reinterpret_cast<graphic::IModel *(*)()>(dl.findSymbol("createModel"));
                deleteModel = reinterpret_cast<void (*)(graphic::IModel *model3)>(dl.findSymbol("deleteModel"));

                //Sound
                createSound = reinterpret_cast<graphic::ISound *(*)(std::string)>(dl.findSymbol("createSound"));
                deleteSound = reinterpret_cast<void (*)(graphic::ISound *sound)>(dl.findSymbol("deleteSound"));

                createMusic = reinterpret_cast<graphic::IMusic *(*)(std::string)>(dl.findSymbol("createMusic"));
                deleteMusic = reinterpret_cast<void (*)(graphic::IMusic *music)>(dl.findSymbol("deleteMusic"));

                std::cout << "Loaded: " << file << std::endl;
            }
            
            /**
             * @brief Destroy the Graphic Shared Loader object
             * 
             */
            ~GraphicSharedLoader() = default;

        private:
            DynamicLoader dl;
        public:
            /**
             * @brief Window
             */
            graphic::IWindow *(*createWindow)(int, int, std::string);
            void (*deleteWindow)(graphic::IWindow *window);

            /**
             * @brief Event
             */
            graphic::IEvent *(*createEvent)();
            void (*deleteEvent)(graphic::IEvent *event);
            
            graphic::IKeyboard *(*createKeyboard)(graphic::IEvent *event);
            void (*deleteKeyboard)(graphic::IKeyboard *keyboard);

            graphic::IMouse *(*createMouse)(graphic::IEvent *event);
            void (*deleteMouse)(graphic::IMouse *mouse);
            
            /**
             * @brief 2D
             */
            // polygon
            graphic::IPolygon *(*createPolygon)(std::vector<__v2f_t> points);
            void (*deletePolygon)(graphic::IPolygon *polygon);
            // sprite
            graphic::ISprite *(*createSprite)(std::string);
            void (*deleteSprite)(graphic::ISprite *sprite);

            graphic::IText *(*createText)(std::string text, std::string font);
            void (*deleteText)(graphic::IText *text);

            /**
             * @brief 3D
             * 
             */

            //camera
            graphic::ICamera *(*createCamera)();
            void (*deleteCamera)(graphic::ICamera *camera);
            //model
            graphic::IModel *(*createModel)();
            void (*deleteModel)(graphic::IModel *model);

            /**
             * @brief Sound
             */
            graphic::ISound *(*createSound)(std::string);
            void (*deleteSound)(graphic::ISound *sound);

            graphic::IMusic *(*createMusic)(std::string);
            void (*deleteMusic)(graphic::IMusic *music);
    };

}

#endif //GRAPHIC_DYNAMIC_LOADER_HPP