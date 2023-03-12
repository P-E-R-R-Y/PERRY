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

#ifndef ICamera3_HPP_
#define ICamera3_HPP_

#include "../Systems/Type.hpp"

enum CameraMode {
    PERSPECTIVE,
    ORTHOGRAPHIC
};

class ICamera3 {
    public:
        virtual ~ICamera3() = 0;

        virtual void setPositon(__v3f_t pos) = 0;
        virtual void setTarget(__v3f_t rot) = 0;
        virtual void setRotationAxis(__v3f_t fov) = 0;
        virtual void setFov(double fov) = 0;
        virtual void setMode(CameraMode mode) = 0;

        virtual __v3f_s getPositon() = 0;
        virtual __v3f_s getTarget() = 0;
        virtual __v3f_s getRotationAxis() = 0;
        virtual double getFov() = 0;
        virtual CameraMode getMode() = 0;
};

#endif /* !ICamera3_HPP_ */
