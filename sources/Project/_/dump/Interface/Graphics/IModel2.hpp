/**
 *
 * File: IModel2.hpp
 * Created Date: Fr Mar 2023
 * Project: PERRY
 * Author: Perry Chouteau
 *
 * Last Modified: Sat Mar 11 2023
 * Modified By: Perry Chouteau
 *
 * Copyright (c) 2023-2033 Perry Chouteau
 *
 **/

#ifndef IMODEL2_HPP_
#define IMODEL2_HPP_

#include "../Systems/Type.hpp"
#include "../Window/IWindow.hpp"

class IModel2 {
    public:
        virtual ~IModel2() = 0;

        virtual void setPositon(__v2f_t positon) = 0;
        virtual void setScale(__v2f_t scale) = 0;
        virtual void setRect(__v4f_t rect) = 0;
        virtual void setRotation(double rotation) = 0;

        virtual __v2f_s getPositon() = 0;
        virtual __v2f_s getSize() = 0;
        virtual __v2f_s getScale() = 0;
        virtual __v4f_s getRect() = 0;
        virtual double getRotation() = 0;

    /*    friend class IWindow;

    private:*/
        virtual void _draw(IWindow &window) = 0;

    private:
        //your variables here
};

#endif /* !IMODEL2_HPP_ */
