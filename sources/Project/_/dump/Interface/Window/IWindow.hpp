/**
 *
 * File: IWindow.hpp
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

#ifndef IWindow_HPP_
#define IWindow_HPP_

#include "../Systems/Type.hpp"

#include "../Window/ICamera2.hpp"
#include "../Window/ICamera3.hpp"

#include "../Graphics/IModel2.hpp"
#include "../Graphics/IModel3.hpp"

class IWindow {

    public:
        virtual ~IWindow() = 0;

        virtual void display() = 0;
        virtual void clear() = 0;
        virtual bool isReady() = 0;
        virtual bool isOpen() = 0;
        virtual void close() = 0;

        virtual bool getCursorVisible() = 0;

        virtual void setSize(__v2u_s size) = 0;
        virtual __v2u_s getSize() = 0;

        virtual void setTitle(std::string title) = 0;
        virtual void setVisible(bool enabled) = 0;
        virtual void setFramerateLimit(__int32_t framerate) = 0;
        virtual __int32_t getFramerateLimit() = 0;

        virtual __int32_t getTime() = 0;
        virtual void setCursorVisible(bool enabled) = 0;

        virtual bool pollEvent() = 0;
        virtual void takeScreenshot(std::string path) = 0;

        //beginDraw 2D
        virtual void beginModel2(ICamera2 camera2) = 0;
        virtual void endModel2() = 0;

        //beginMode 3D−
        virtual void beginModel3(ICamera3 camera3) = 0;
        virtual void endModel3() = 0;

        //draw 2D/3D
        virtual void draw(IModel2 &model2) = 0;
        virtual void draw(IModel3 &model3) = 0;

    private:
        //your variables here
};

#endif /* !IWindow_HPP_ */