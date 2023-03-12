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

#include "../../Interface/Window/ICamera2.hpp"

class SfmlCamera2 : public ICamera2{
    public:
        SfmlCamera2() = default;

        ~SfmlCamera2() = default;

        void setOffset(__v2f_s offset) override {

        }

        void setTarget(__v2f_s target) override {

        }

        void setRotation(double rotation) override {

        }

        void setZoom(double zoom) override {

        }

        __v2f_s getOffset() override {

        }

        __v2f_s getTarget() override {

        }

        double getRotation() override {

        }

        double getZoom() override {

        }

};