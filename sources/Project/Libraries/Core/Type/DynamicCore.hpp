/**
 *
 * File: DynamicCore.hpp (header.v2)
 * Created Date: Fri 31/03/2023
 * Project: PERRY
 * Author: Perry Chouteau
 *
 * Last Modified: Sun 02/04/2023
 * Modified By: Perry Chouteau
 *
 * Copyright (c) 2023-2033 Perry Chouteau
 *
 **/

//Dynamic
#include "../../DynamicLoader.hpp"

//Core
#include "../../../Interface/Core/Core.hpp"
//Multimedia
#include "../../../Interface/Window/IWindow.hpp"
#include "../../../Interface/Graphics/IModel2.hpp"


class MultimediaLibrary {
    public:
        MultimediaLibrary() {
            createWindow = nullptr;
            deleteWindow = nullptr;
            createModel2 = nullptr;
            deleteModel2 = nullptr;
        }

        ~MultimediaLibrary() = default;

        bool Init(std::string file) {
            std::cout << 1.1 << std::endl;
            DynamicLoader dl(file);
            std::cout << 1.2 << std::endl;
            //window
            createWindow = reinterpret_cast<IWindow *(*)(__int32_t, __int32_t, std::string)>(dl.findSymbol("createWindow"));
            if (createWindow == nullptr)
                std::cout << "createWindow == null" << std::endl;

            deleteWindow = reinterpret_cast<void (*)(IWindow *window)>(dl.findSymbol("deleteWindow"));
            if (deleteWindow == nullptr)
                std::cout << "deleteWindow == null" << std::endl;
            std::cout << 1.3 << std::endl;
            //model2

            createModel2 = reinterpret_cast<IModel2 *(*)(std::string)>(dl.findSymbol("createModel2"));
            if (createModel2 == nullptr)
                std::cout << "createModel2 == null" << std::endl;
            deleteModel2 = reinterpret_cast<void (*)(IModel2 *model)>(dl.findSymbol("deleteModel2"));
            if (deleteModel2 == nullptr)
                std::cout << "deleteModel2 == null" << std::endl;
            std::cout << 1.4 << std::endl;
            std::cout << "function implementation == " << ((createWindow != nullptr && deleteWindow != nullptr &&
                                                            createModel2 != nullptr && deleteModel2 != nullptr)? "true" : "false") << std::endl;

            return (createWindow != nullptr && deleteWindow != nullptr &&
                    createModel2 != nullptr && deleteModel2 != nullptr);
        }

        //window
        IWindow *(*createWindow)(int, int, std::string);
        void (*deleteWindow)(IWindow *window);
        //model2
        IModel2 *(*createModel2)(std::string);
        void (*deleteModel2)(IModel2 *model);
};

class DynamicCore: public Core {
    public:
        DynamicCore(): ml() {
        }

        virtual ~DynamicCore() = default;

    protected:
        MultimediaLibrary ml;
};
