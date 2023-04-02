#ifndef EWINDOW_HPP_
#define EWINDOW_HPP_

#include "EModel.hpp"
#include <iostream>
//#include <string>

class EWindow {
    public:
        EWindow() {}

        ~EWindow() = default;

        void draw(EModel obj) {
            std::cout << obj._str << std::endl;
        }
};

#endif /* !EWINDOW_HPP_ */