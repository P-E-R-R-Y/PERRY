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
#include "Interface/Window/IWindow.hpp"
#include "Interface/Graphics/IModel2.hpp"
//EngineCore
#include "Libraries/Core/Engine/NoEngineCore.hpp"

#include <dlfcn.h>
#include <map>
#include <iostream>
#include <utility>
#include <filesystem>
#include <sys/stat.h>
#include <filesystem>

class FirstGameCore: public SwitchLibCore/*NoEngineCore*/ {
    public:
        FirstGameCore() {

        }
    protected:

        void initHandler() override {
            std::cout << "initHandler " << std::endl;
            model2 = createModel2("./image.png");
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
        }

    private:
        IModel2 *model2;
};

#include "Libraries/FlagParser.hpp"
#include "Libraries/FileSearcher.hpp"

int main(int ac, char **av) {
    std::vector<std::string> files = FileSearcher::searchPathFiles("./Shared/", "so");
    FirstGameCore fgc;

            std::cout << "--------------------" << std::endl;
    for(auto& i: files)
        std::cout << i << std::endl;
            std::cout << "--------------------" << std::endl;
    fgc.Run(files);
    return 0;
}
