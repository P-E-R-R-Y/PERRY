/**
 *
 * File: ICamera.hpp
 * Created Date: Fr Mar 2023
 * Project: PERRY
 * Author: Perry Chouteau
 *
 * Last Modified: Fri Mar 10 2023
 * Modified By: Perry Chouteau
 *
 * Copyright (c) 2023-2033 Perry Chouteau
 *
 **/

#ifndef ICamera2_HPP_
#define ICamera2_HPP_

#include "../Systems/Type.hpp"

class ICamera2 {
    public:
        virtual ~ICamera2() = 0;

        virtual void setOffset(__v2f_s offset) = 0;
        virtual void setTarget(__v2f_s target) = 0;
        virtual void setRotation(double rotation) = 0;
        virtual void setZoom(double zoom) = 0;

        virtual __v2f_s getOffset() = 0;
        virtual __v2f_s getTarget() = 0;
        virtual double getRotation() = 0;
        virtual double getZoom() = 0;

};

#endif /* !ICamera2_HPP_ */
