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
    #include "../graphic/IText.hpp"

namespace graphic {

    /**
     * @brief Window interface
     * @interface IWindow 
     */
    class IWindow {

        public:

            virtual ~IWindow() = default;
            
            virtual bool isOpen() = 0;
            
            virtual void beginDraw() = 0;

            virtual void drawText(IText *text) = 0;

            virtual void endDraw() = 0;

            virtual bool pollEvent() = 0;

            virtual void close() = 0;
            
        private:
            //your variables here
    };

} // namespace graphic3


#endif /* !IWINDOW_HPP_ */