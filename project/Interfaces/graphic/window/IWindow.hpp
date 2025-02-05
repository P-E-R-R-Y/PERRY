/**
 * @file IWindow.hpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-29
 * 
 * @addtogroup graphic
 * @{
 */

#ifndef IWINDOW_HPP_
    #define IWINDOW_HPP_
    #include "../graphic/IPolygon.hpp"
    #include "../graphic/IModel.hpp"
    #include "../graphic/ISprite.hpp"
    #include "../graphic/IText.hpp"
    #include "../event/IEvent.hpp"
    #include "ICamera.hpp"

namespace graphic {

    /**
     * @brief Window interface
     * @interface IWindow 
     */
    class IWindow {

        public:

            /**
             * @brief Destroy the IWindow object
             */
            virtual ~IWindow() = default;
            
            /**
             * @brief notice if the window is open
             * 
             * @return bool
             */
            virtual bool isOpen() = 0;

            /**
             * @brief close the window
             */
            virtual void close() = 0;

            /**
             * @brief Set the Frame Limit object
             * 
             * @param limit 
             */
            virtual void setFrameLimit(__int32_t limit) = 0;

            /**
             * @brief Get the Delta object
             * 
             * @return __int32_t 
             */
            virtual __int32_t getDelta() = 0;

            /**
             * @brief link an event to the window
             * 
             * @param event 
             */
            virtual void linkEvent(IEvent *event) = 0;
            
            /**
             * @brief allowing to draw 2D on the window
             */
            virtual void beginDraw() = 0;

            /**
             * @brief draw a polygon
             * 
             * @param polygon 
             */
            virtual void drawPoly(IPolygon *polygon) = 0;

            /**
             * @brief draw a sprite
             * 
             * @param model 
             */
            virtual void drawSprite(ISprite *model) = 0;

            /**
             * @brief draw a text
             * 
             */
            virtual void drawText(IText *text) = 0;

            /**
             * @brief end the 2D drawing
             */
            virtual void endDraw() = 0;

            /**
             * @brief allowing to draw 3D on the window
             * 
             * @param camera 
             */
            virtual void beginMode3(ICamera *camera) = 0;

            /**
             * @brief draw a model
             * 
             * @param model 
             */
            virtual void drawModel(IModel *model) = 0;

            /**
             * @brief end the 3D drawing
             */
            virtual void endMode3() = 0;
            
            /**
             * @brief poll the event
             * 
             * @return bool
             */
            virtual bool pollEvent() = 0;

            /**
             * @brief update the window
             */
            virtual void eventClose() = 0;

            /**
             * @brief begin Audio
             */
            virtual bool beginAudio() = 0;

            /**
             * @brief end Audio
             */
            virtual void endAudio() = 0;

        private:
            //your variables here
    };

} // namespace graphic3


#endif /* !IWINDOW_HPP_ */