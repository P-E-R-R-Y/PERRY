/**
 *
 * File: Core.hpp (header.v2)
 * Created Date: Sun 02/04/2023
 * Project: PERRY
 * Author: Perry Chouteau
 *
 * Last Modified: Sun 02/04/2023
 * Modified By: Perry Chouteau
 *
 * Copyright (c) 2023-2033 Perry Chouteau
 *
 **/

#include "ICore.hpp"
#include <iostream>

class Core: public ICore {
    public:
        Core() {
        }

        ~Core() {
        }

        int Run() override {
            this->initHandler();
            while (true) {
                this->updateHandler();
                
                for (int i = 0; i < 1; i++) {
                    this->eventHandler();
                }
                this->displayHandler();
            }
            return 0;
        }
    protected:
        virtual void initHandler();
        virtual void eventHandler();
        virtual void updateHandler();
        virtual void displayHandler();
};

class GameEngine: public Core {
    public:
        GameEngine() {

        }

        ~GameEngine() {

        }

        int Run() override {
            this->initHandler();
            while (true) {
                this->updateHandler();
                for (int i = 0; i < 2; i++) {
                    this->eventHandler(i);
                }
                this->displayHandler();
            }
            return 0;
        }

    protected:
        void initHandler() override {
            std::cout << "initHandler " << std::endl;
        }

        void eventHandler(int i) override {
            std::cout << "eventHandler " << i << std::endl;
        }

        void updateHandler() override {
            std::cout << "updateHandler " << std::endl;
        }

        void displayHandler() override {
            std::cout << "displayHandler " << std::endl;
        }
    private:
};
