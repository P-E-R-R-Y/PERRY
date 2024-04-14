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
#include "Interfaces/graphic3/graphic/IModel2.hpp"
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
            model2 = createModel2("./Assets/image.png");
            camera = createCamera();
            model3 = createModel3();
        }

        void eventHandler() override {
            std::cout << "eventHandler " << std::endl;
        }

        void updateHandler() override {
            std::cout << "updateHandler " << std::endl;
        }

        void displayHandler() override {
            std::cout << "displayHandler" << std::endl;
            window->draw2(model2);
    
            window->beginMode3(camera);
                window->draw3(model3);
            window->endMode3();
        }

    private:
        graphic3::IModel2 *model2;
        graphic3::ICamera *camera;
        graphic3::IModel3 *model3;
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