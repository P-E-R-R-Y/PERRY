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

#include "../../Interface/Graphics/IModel3.hpp"

class RayModel3 {
    public:
        ~RayModel3() = default;

        void set(IModel3 &model) = 0;
        void setPositon(__v3f_t pos) = 0;
        void setRotation(__v3f_t rot) = 0;
        void setScale(__v3f_t scale) = 0;

        __v3f_s getPositon() = 0;
        __v3f_s getRotation() = 0;
        __v3f_s getScale() = 0;

    /*    friend class IWindow;

    private:*/
        void _draw(IWindow &window) = 0;

    private:
        //your variables here
};
