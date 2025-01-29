/**
 * @file IKeyboard.hpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-29
 * 
 * @addtogroup graphic
 * @{
 */

#ifndef IKEYBOARD_HPP
#define IKEYBOARD_HPP

#include <vector>
#include "IEvent.hpp"

namespace graphic {

    /**
     * @brief Keyboard interface
     * @interface IKeyboard
     */
    class IKeyboard {
      public:
    //    typedef enum Layout {
    //      LAYOUT_QWERTY = 0,
    //      LAYOUT_AZERTY = 1,
    //    } Layout;

        static const int MAX_KEYS = 87;

        /// Scan codes
        enum Keys {
          KEY_UNKNOWN = -1,

          /// Line 0
          KEY_ESCAPE,
          KEY_F1,
          KEY_F2,
          KEY_F3,
          KEY_F4,
          KEY_F5,
          KEY_F6,
          KEY_F7,
          KEY_F8,
          KEY_F9,
          KEY_F10,
          KEY_F11,
          KEY_F12,

          /// Line 1
          KEY_1,
          KEY_2,
          KEY_3,
          KEY_4,
          KEY_5,
          KEY_6,
          KEY_7,
          KEY_8,
          KEY_9,
          KEY_0,
          KEY_MINUS,
          KEY_EQUAL,
          KEY_BACKSPACE,

          /// Line 2
          KEY_TAB,
          KEY_Q,
          KEY_W,
          KEY_E,
          KEY_R,
          KEY_T,
          KEY_Y,
          KEY_U,
          KEY_I,
          KEY_O,
          KEY_P,
          KEY_LEFT_BRACKET,
          KEY_RIGHT_BRACKET,

          /// Line 3
          KEY_CAPS_LOCK,
          KEY_LEFT_CONTROL,
          KEY_A,
          KEY_S,
          KEY_D,
          KEY_F,
          KEY_G,
          KEY_H,
          KEY_J,
          KEY_K,
          KEY_L,
          KEY_SEMICOLON,
          KEY_APOSTROPHE,
          BACK_TICK,
          KEY_ENTER,
          
          /// Line 4
          KEY_LEFT_SHIFT,
          KEY_BACKSLASH,
          KEY_Z,
          KEY_X,
          KEY_C,
          KEY_V,
          KEY_B,
          KEY_N,
          KEY_M,
          KEY_COMMA,
          KEY_PERIOD,
          KEY_DOT,
          KEY_SLASH,
          KEY_RIGHT_SHIFT,
          /// Line 5
          KEY_LEFT_ALT,
          KEY_SPACE,
          KEY_RIGHT_ALT,
          KEY_RIGHT_CONTROL,

          /// KEYPAD
          KEY_PAD_0,
          KEY_PAD_1,
          KEY_PAD_2,
          KEY_PAD_3,
          KEY_PAD_4,
          KEY_PAD_5,
          KEY_PAD_6,
          KEY_PAD_7,
          KEY_PAD_8,
          KEY_PAD_9,
          KEY_PAD_MINUS,
          KEY_PAD_PLUS,
          KEY_PAD_DOT,
          KEY_PAD_ENTER,

          /// ARROWS
          KEY_UP,
          KEY_DOWN,
          KEY_LEFT,
          KEY_RIGHT,
          //end
          KEY_LENGTH
        };

        /**
         * @brief Destroy the IKeyboard object
         */
        virtual ~IKeyboard() {}

        /**
         * @brief Be careful, this function will check every key of the keyboard and return an array of keys that are pressed
         * it's not recommended to use this function in a loop, use isKeyPressed() instead. it's efficient for key detection & binding. 
         *
         * @return Keys* 
         */
        virtual std::vector<Keys> whichKey() const = 0;

        /**
         * @brief Check if the key is pressed
         *
         * @param key
         * @return bool
         */
        virtual bool isKeyPressed(Keys key) const = 0;

        /**
         * @brief Check if the key is released
         *
         * @param key
         * @return bool
         */
        virtual bool isKeyReleased(Keys key) const = 0;

        /**
         * @brief Check if the key is down
         *
         * @param key
         * @return bool
         */
        virtual bool isKeyDown(Keys key) const = 0;

        /**
         * @brief Check if the key is up
         *
         * @param key
         * @return bool
         */
        virtual bool isKeyUp(Keys key) const = 0;
        
        /**
         * @brief Update the keyboard
         */
        virtual void update() = 0;

      private:
    };

}

#endif /* !IKEYBOARD_HPP */