/**
 * @ Author: Perry Chouteau
 * @ Create Time: 2024-04-27 03:45:38
 * @ Modified by: Perry Chouteau
 * @ Modified time: 2024-11-22 20:42:42
 * @ Description:
 */

#ifndef IMOUSE_HPP_
#define IMOUSE_HPP_
  
#include "../../../libraries/system/type.hpp"

namespace graphic {

  class IMouse {

    public:
      //constructor
      virtual ~IMouse() = default;

      enum Buttons {
            BUTTON_LEFT,
            BUTTON_RIGHT,
            BUTTON_MIDDLE,

            EXTRA_BUTTON_1,
            EXTRA_BUTTON_2,
      };
      //is
      virtual bool isButtonPressed(Buttons key) const = 0;
      virtual bool isButtonDown(Buttons key) const = 0;
      virtual bool isButtonReleased(Buttons key) const = 0;
      virtual bool isButtonUp(Buttons key) const = 0;
      //p
      virtual __v2f_t getPosition() const = 0;
      virtual void setPosition(__v2f_t position) = 0;
      //w
      virtual float GetMouseWheelMove() const = 0;
      //u
      virtual void update() = 0;
    };

} // namespace graphic3

#endif /* !IMOUSE_HPP_ */