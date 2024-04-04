/*
class SwitchCore: public Core {
    public:
        SwitchCore(): Core() {
            up = true;
            nlib = 0;
        }

        int Run (std::vector<std::string> files) override {
            while (up) {
                DynamicLoader dl(files[nlib]);
                std::cout << files[nlib] << std::endl;
                //window
                IWindow *(*createWindow)(int, int, std::string) = reinterpret_cast<IWindow *(*)(int, int, std::string)>(dl.findSymbol("createWindow"));
                void (*deleteWindow)(IWindow * window) = reinterpret_cast<void (*)(IWindow *window)>(dl.findSymbol("deleteWindow"));
                //model2
                IModel2 *(*createModel2)(std::string) = reinterpret_cast<IModel2 *(*)(std::string)>(dl.findSymbol("createModel2"));
                void (*deleteModel2)(IModel2 *model2) = reinterpret_cast<void (*)(IModel2 *model2)>(dl.findSymbol("deleteModel2"));

                if (createWindow == nullptr || deleteWindow == nullptr || createModel2 == nullptr || deleteModel2 == nullptr)
                    continue;

                IWindow *window = createWindow(800, 500, "Perry");
                IModel2 *model2 = createModel2("image.png");
                // main loop
                this->initHandler();
                while (window->isOpen()) {
                    if (window->isPoll()) {
                        while (window->pollEvent()) {
                            window->eventClose();
                            this->eventHandler();
                        }
                    } else {
                        window->eventClose();
                        this->eventHandler();
                    }
                    this->updateHandler();
                    window->beginDraw();
                    window->draw2(model2);
                    this->displayHandler();
                    window->endDraw();

                }
                window->close();

                deleteWindow(window);
                deleteModel2(model2);

                nlib += (nlib < files.size() - 1) ? 1 : -nlib;
            }
            return 0;
        }

    protected:
        bool up;
        std::size_t nlib;
};

class SimpleCore: public Core {
    public:
        SimpleCore(): Core() {
        }

        ~SimpleCore() {};

    protected:
        void initHandler() override {
            std::cout << "initHandler ";
        }

        void eventHandler() override {
            std::cout << "eventHandler ";
        }

        void updateHandler() override {
            std::cout << "updateHandler ";
        }

        void displayHandler() override {
            std::cout << "displayHandler" << std::endl;
        }

    private:
        //vars
};

class SimpleSwitchCore: public SimpleCore, public SwitchCore {
    public:

        SimpleSwitchCore(): SimpleCore(), SwitchCore() { }

        int Run(std::vector<std::string> files) override {
            return SwitchCore::Run(files);
        }

    protected:

        void initHandler() override {
            SimpleCore::initHandler();
        }

        void eventHandler() override {
            SimpleCore::eventHandler();
        }

        void updateHandler() override {
            SimpleCore::updateHandler();
        }

        void displayHandler() override {
            SimpleCore::displayHandler();
        }

};*/