/**
 *
 * File: IModel3.hpp
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

#ifndef IMODEL3_HPP_
#define IMODEL3_HPP_

#include "../Systems/Type.hpp"
#include "../Window/IWindow.hpp"

class IModel3 {
    public:
        virtual ~IModel3() = 0;

        virtual void set(IModel3 &model) = 0;
        virtual void setPositon(__v3f_t pos) = 0;
        virtual void setRotation(__v3f_t rot) = 0;
        virtual void setScale(__v3f_t scale) = 0;

        virtual __v3f_s getPositon() = 0;
        virtual __v3f_s getRotation() = 0;
        virtual __v3f_s getScale() = 0;

    /*    friend class IWindow;

    private:*/
        virtual void _draw(IWindow &window) = 0;

    private:
        //your variables here
};

#endif /* !IMODEL3_HPP_ */
