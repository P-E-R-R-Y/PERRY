
#include "../../../interfaces/core/ICore.hpp"
#include <string>
#include <iostream>

class Snake : public ICore {
    public:
        Snake(const std::string& title) : title(title) {}

        ~Snake() {}

        void start() override {
            initHandler();
            while (!shouldExit) {
                eventHandler();
                updateHandler();
                displayHandler();
            }
        }

        void initHandler() {
            std::cout << "initHandler " << std::endl;
        }

        void eventHandler() {
            std::cout << "eventHandler " << std::endl;
            if (std::cin.get() == 'q') {
                shouldExit = true;
            }
        }

        void updateHandler() {
            std::cout << "updateHandler " << std::endl;
        }

        void displayHandler() {
            std::cout << "displayHandler" << std::endl;
        }
    private:
        std::string title;
        bool shouldExit = false;
};