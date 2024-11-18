/**
 * @ Author: Perry Chouteau
 * @ Create Time: 2024-05-10 19:59:08
 * @ Modified by: Perry Chouteau
 * @ Modified time: 2024-11-11 12:16:55
 * @ Description: Raylib Encapsulation for IMouse
 */

#ifndef SDLKEYBOARD_HPP_
#define SDLKEYBOARD_HPP_

//Interface
#include "../../../../interfaces/graphic/event/IKeyboard.hpp"
#include "SdlEvent.hpp"

//Sdl
#include <SDL2/SDL.h>

//More
#include <vector>
#include <unordered_map>

class SdlKeyboard : public graphic::IKeyboard {

    public:
        SdlKeyboard(graphic::IEvent *event) {
            _event = static_cast<SdlEvent *>(event);
        }

        ~SdlKeyboard() {
        }

        std::vector<Keys> whichKey() const override {
            std::vector<Keys> keys;
            
            return keys;
        }

        bool isKeyPressed(Keys key) const override {
            return (_event->_event.key.keysym.sym == _keys.at(key));
        }

        bool isKeyDown(Keys key) const override {
            //return true
            return (_event->_event.key.keysym.sym == _keys.at(key));
        }

        bool isKeyReleased(Keys key) const override {
            return (_event->_event.key.keysym.sym == _keys.at(key));
        }


        bool isKeyUp(Keys key) const override {
            return !(_event->_event.key.keysym.sym == _keys.at(key));
        }

        void update() override {};

    private:
        SdlEvent *_event;

        const std::unordered_map<IKeyboard::Keys, int> _keys = {
            //line 0
            {IKeyboard::Keys::KEY_ESCAPE, SDL_KeyCode::SDLK_ESCAPE},
            {IKeyboard::Keys::KEY_F1, SDL_KeyCode::SDLK_F1},
            {IKeyboard::Keys::KEY_F2, SDL_KeyCode::SDLK_F2},
            {IKeyboard::Keys::KEY_F3, SDL_KeyCode::SDLK_F3},
            {IKeyboard::Keys::KEY_F4, SDL_KeyCode::SDLK_F4},
            {IKeyboard::Keys::KEY_F5, SDL_KeyCode::SDLK_F5},
            {IKeyboard::Keys::KEY_F6, SDL_KeyCode::SDLK_F6},
            {IKeyboard::Keys::KEY_F7, SDL_KeyCode::SDLK_F7},
            {IKeyboard::Keys::KEY_F8, SDL_KeyCode::SDLK_F8},
            {IKeyboard::Keys::KEY_F9, SDL_KeyCode::SDLK_F9},
            {IKeyboard::Keys::KEY_F10, SDL_KeyCode::SDLK_F10},
            {IKeyboard::Keys::KEY_F11, SDL_KeyCode::SDLK_F11},
            {IKeyboard::Keys::KEY_F12, SDL_KeyCode::SDLK_F12},

            //line 1
            {IKeyboard::Keys::KEY_1, SDL_KeyCode::SDLK_1},
            {IKeyboard::Keys::KEY_2, SDL_KeyCode::SDLK_2},
            {IKeyboard::Keys::KEY_3, SDL_KeyCode::SDLK_3},
            {IKeyboard::Keys::KEY_4, SDL_KeyCode::SDLK_4},
            {IKeyboard::Keys::KEY_5, SDL_KeyCode::SDLK_5},
            {IKeyboard::Keys::KEY_6, SDL_KeyCode::SDLK_6},
            {IKeyboard::Keys::KEY_7, SDL_KeyCode::SDLK_7},
            {IKeyboard::Keys::KEY_8, SDL_KeyCode::SDLK_8},
            {IKeyboard::Keys::KEY_9, SDL_KeyCode::SDLK_9},
            {IKeyboard::Keys::KEY_0, SDL_KeyCode::SDLK_0},
            {IKeyboard::Keys::KEY_MINUS, SDL_KeyCode::SDLK_MINUS},
            {IKeyboard::Keys::KEY_EQUAL, SDL_KeyCode::SDLK_EQUALS},
            {IKeyboard::Keys::KEY_BACKSPACE, SDL_KeyCode::SDLK_BACKSPACE},

            //line 2
            {IKeyboard::Keys::KEY_TAB, SDL_KeyCode::SDLK_TAB},
            {IKeyboard::Keys::KEY_Q, SDL_KeyCode::SDLK_q},
            {IKeyboard::Keys::KEY_W, SDL_KeyCode::SDLK_w},
            {IKeyboard::Keys::KEY_E, SDL_KeyCode::SDLK_e},
            {IKeyboard::Keys::KEY_R, SDL_KeyCode::SDLK_r},
            {IKeyboard::Keys::KEY_T, SDL_KeyCode::SDLK_t},
            {IKeyboard::Keys::KEY_Y, SDL_KeyCode::SDLK_y},
            {IKeyboard::Keys::KEY_U, SDL_KeyCode::SDLK_u},
            {IKeyboard::Keys::KEY_I, SDL_KeyCode::SDLK_i},
            {IKeyboard::Keys::KEY_O, SDL_KeyCode::SDLK_o},
            {IKeyboard::Keys::KEY_P, SDL_KeyCode::SDLK_p},
            {IKeyboard::Keys::KEY_LEFT_BRACKET, SDL_KeyCode::SDLK_LEFTBRACKET},
            {IKeyboard::Keys::KEY_RIGHT_BRACKET, SDL_KeyCode::SDLK_RIGHTBRACKET},

            //line 3
            {IKeyboard::Keys::KEY_CAPS_LOCK, SDL_KeyCode::SDLK_CAPSLOCK},
            {IKeyboard::Keys::KEY_LEFT_CONTROL, SDL_KeyCode::SDLK_LCTRL},
            {IKeyboard::Keys::KEY_A, SDL_KeyCode::SDLK_a},
            {IKeyboard::Keys::KEY_S, SDL_KeyCode::SDLK_s},
            {IKeyboard::Keys::KEY_D, SDL_KeyCode::SDLK_d},
            {IKeyboard::Keys::KEY_F, SDL_KeyCode::SDLK_f},
            {IKeyboard::Keys::KEY_G, SDL_KeyCode::SDLK_g},
            {IKeyboard::Keys::KEY_H, SDL_KeyCode::SDLK_h},
            {IKeyboard::Keys::KEY_J, SDL_KeyCode::SDLK_j},
            {IKeyboard::Keys::KEY_K, SDL_KeyCode::SDLK_k},
            {IKeyboard::Keys::KEY_L, SDL_KeyCode::SDLK_l},
            {IKeyboard::Keys::KEY_SEMICOLON, SDL_KeyCode::SDLK_SEMICOLON},
            {IKeyboard::Keys::KEY_APOSTROPHE, SDL_KeyCode::SDLK_QUOTE},
            {IKeyboard::Keys::BACK_TICK, -1},
            {IKeyboard::Keys::KEY_ENTER, SDL_KeyCode::SDLK_KP_ENTER},
            
            //line 4
            {IKeyboard::Keys::KEY_LEFT_SHIFT, SDL_KeyCode::SDLK_LSHIFT},
            {IKeyboard::Keys::KEY_BACKSLASH, SDL_KeyCode::SDLK_BACKSLASH},
            {IKeyboard::Keys::KEY_Z, SDL_KeyCode::SDLK_z},
            {IKeyboard::Keys::KEY_X, SDL_KeyCode::SDLK_x},
            {IKeyboard::Keys::KEY_C, SDL_KeyCode::SDLK_c},
            {IKeyboard::Keys::KEY_V, SDL_KeyCode::SDLK_v},
            {IKeyboard::Keys::KEY_B, SDL_KeyCode::SDLK_b},
            {IKeyboard::Keys::KEY_N, SDL_KeyCode::SDLK_n},
            {IKeyboard::Keys::KEY_M, SDL_KeyCode::SDLK_m},
            {IKeyboard::Keys::KEY_COMMA, SDL_KeyCode::SDLK_KP_COMMA},
            {IKeyboard::Keys::KEY_DOT, SDL_KeyCode::SDLK_KP_DECIMAL},
            {IKeyboard::Keys::KEY_RIGHT_SHIFT, SDL_KeyCode::SDLK_RSHIFT},

            /// Line 5
            {IKeyboard::Keys::KEY_LEFT_ALT, SDL_KeyCode::SDLK_LALT},
            {IKeyboard::Keys::KEY_SPACE, SDL_KeyCode::SDLK_SPACE},
            {IKeyboard::Keys::KEY_RIGHT_ALT, SDL_KeyCode::SDLK_RALT},
            {IKeyboard::Keys::KEY_RIGHT_CONTROL, SDL_KeyCode::SDLK_RCTRL},
    
            /// KEYPAD
            {IKeyboard::Keys::KEY_PAD_0, SDL_KeyCode::SDLK_KP_0},
            {IKeyboard::Keys::KEY_PAD_1, SDL_KeyCode::SDLK_KP_1},
            {IKeyboard::Keys::KEY_PAD_2, SDL_KeyCode::SDLK_KP_2},
            {IKeyboard::Keys::KEY_PAD_3, SDL_KeyCode::SDLK_KP_3},
            {IKeyboard::Keys::KEY_PAD_4, SDL_KeyCode::SDLK_KP_4},
            {IKeyboard::Keys::KEY_PAD_5, SDL_KeyCode::SDLK_KP_5},
            {IKeyboard::Keys::KEY_PAD_6, SDL_KeyCode::SDLK_KP_6},
            {IKeyboard::Keys::KEY_PAD_7, SDL_KeyCode::SDLK_KP_7},
            {IKeyboard::Keys::KEY_PAD_8, SDL_KeyCode::SDLK_KP_8},
            {IKeyboard::Keys::KEY_PAD_9, SDL_KeyCode::SDLK_KP_9},
            {IKeyboard::Keys::KEY_PAD_MINUS, SDL_KeyCode::SDLK_KP_MEMSUBTRACT},
            {IKeyboard::Keys::KEY_PAD_PLUS, SDL_KeyCode::SDLK_KP_PLUS},
            {IKeyboard::Keys::KEY_PAD_DOT, SDL_KeyCode::SDLK_KP_DECIMAL},
            {IKeyboard::Keys::KEY_PAD_ENTER, SDL_KeyCode::SDLK_KP_ENTER},

            //Arrow
            {IKeyboard::Keys::KEY_UP, SDL_KeyCode::SDLK_UP},
            {IKeyboard::Keys::KEY_DOWN, SDL_KeyCode::SDLK_DOWN},
            {IKeyboard::Keys::KEY_LEFT, SDL_KeyCode::SDLK_LEFT},
            {IKeyboard::Keys::KEY_RIGHT, SDL_KeyCode::SDLK_RIGHT},
        };
};

#endif /* !SDLKEYBOARD_HPP_ */