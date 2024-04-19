/**
 *
 * File: main.cpp (header.v2)
 * Created Date: Tue 14/03/2023
 * Project: PERRY
 * Author: Perry Chouteau
 *
 * Last Modified: Sat 18/03/2023
 * Modified By: Perry Chouteau
 *
 * Copyright (c) 2023-2033 Perry Chouteau
 *
 **/

//Interface
#include "Interfaces/graphic3/window/IWindow.hpp"
#include "Interfaces/graphic3/graphic/IPolygon.hpp"
//EngineCore
#include "Libraries/DynamicSwitchCore/DynamicSwitchCore.hpp"

#include <dlfcn.h>
#include <map>
#include <iostream>
#include <utility>
#include <filesystem>
#include <sys/stat.h>
#include <filesystem>

class FirstGameCore: public DynamicSwitchLibCore/*NoEngineCore*/ {
    public:
        FirstGameCore(std::vector<std::string> files): DynamicSwitchLibCore(files) {}
    protected:

        void initHandler() override {
            std::cout << "initHandler " << std::endl;
            std::vector<__v2f_t> points = {{100, 100}, {200, 100}, {200, 200}, {300, 200}, {300, 300}, {100, 300}};//{50, 300}
            polygon = createPolygon(points);
            sprite = createSprite("./Assets/image.png");
            camera = createCamera();
            model = createModel();
        }

        void eventHandler() override {
            //std::cout << "eventHandler " << std::endl;
        }

        void updateHandler() override {
            //std::cout << "updateHandler " << std::endl;
        }

        void displayHandler() override {
            std::cout << "displayHandler" << std::endl;
            window->drawSprite(sprite);

            //window->beginMode3(camera);
            //    window->draw3(model);
            //window->endMode3();
            window->drawPoly(polygon);
        }

    private:
        graphic3::IPolygon *polygon;
        graphic3::ISprite *sprite;
        graphic3::ICamera *camera;
        graphic3::IModel *model;
};

#include "Libraries/FlagParser.hpp"
#include "Libraries/FileSearcher.hpp"

int main(int ac, char **av) {
    std::cout << "hey" << std::endl;
    //todo need to handle mutliple dynamic file extensions 
    std::vector<std::string> files = FileSearcher::searchPathFiles("./Libraries", "dylib");
    std::cout << "hey" << std::endl;
    FirstGameCore fgc(files);
    std::cout << "hey" << std::endl;

    std::cout << "--------------------" << std::endl;
    for(auto& i: files)
        std::cout << i << std::endl;
    std::cout << "hey" << std::endl;
    std::cout << "--------------------" << std::endl;
    fgc.Run();
    return 0;
}