/**
 * @file main.cpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-29
 * 
 * @addtogroup user
 * @{
 */

#include <iostream>
#include <ostream>
#include <memory>
#include <vector>
#include <string>
#include <map>
//libraries
#include "libraries/system/std.hpp"
#include "libraries/finder/FileSearcher.hpp"

//interface 
#include "interfaces/InfoSharedLoader.hpp"
 
//  graphic
#include "interfaces/graphic/GraphicSharedLoader.hpp"
#include "interfaces/serial/SerialSharedLoader.hpp"

//ecs
#include "modules/core/ecs/Ecs.hpp"
#include "includes/Component.hpp"
#include "includes/Systems.hpp"

/**
 * @brief Create a Game from CustomisableEngine<GraphicSharedLoader, Registry>
 * - the graphic symbols from the shared library
 * - get the registry methods and 
 * 
 * @tparam GraphicSharedLoader
 * @tparam Registry
 */
class Game: public CustomisableEngine<graphic::GraphicSharedLoader, ecs::Registry> {
    public:
        //todo change vector to variadic template
        /**
         * @brief Construct a new Game object
         * 
         * @param graphic 
         */
        Game(std::string graphic): CustomisableEngine(graphic, nullptr) {};
        ~Game() = default;

        /**
         * @brief start the game
         * 
         * @return int 
         */
        int start() override {
            // main loop
            this->initHandler();
            while (window->isOpen()) {
                while (window->pollEvent()) {
                    window->eventClose();
                    this->eventHandler();
                }
                this->updateHandler();
                window->beginDraw();
                this->displayHandler();
                window->endDraw();
            }
            window->endAudio();
            window->close();

            this->destroyHandler();
            return 0;
        }

    protected:

        /**
         * @brief init the game using inherited methods
         */
        void initHandler() override {
            std::cout << "initHandler " << std::endl;
            window = createWindow(800, 500, "Perry");
            window->beginAudio();
            event = createEvent();
            window->linkEvent(event);
            std::vector<__v2f_t> star_points = {{125, 200}, {175, 200}, {200, 150}, {225, 200}, {275, 200},  {250, 250}, {255, 305}, {200, 285}, {145, 305}, {150, 250}};
            std::vector<__v2f_t> heart_points = {{500, 100}, {600, 100}, {600, 200}, {700, 200}, {700, 300},  {500, 300}};
            poly_star = createPolygon(star_points);
            poly_heart = createPolygon(heart_points);
            sprite = createSprite("./assets/image/image.png");
            camera = createCamera();
            model = createModel();
            keyboard = createKeyboard(event);
            mouse = createMouse(event);
            text = createText("text", "./assets/font/noto.ttf");
            music = createMusic("./assets/music/redSunInTheSky.mp3");
            sound = createSound("./assets/sound/frankySuper.wav");
            music->play();
            window->setFrameLimit(120);
        }

        /**
         * @brief handle event the game using inherited methods
         */
        void eventHandler() override {
            if (keyboard != nullptr) {
                if (keyboard->isKeyDown(graphic::IKeyboard::Keys::KEY_SPACE)) {
                    std::cout << "Jump" << std::endl;
                    __v2f_t pos = sprite->getPosition();
                    sprite->setPosition({pos.x + 1, pos.y});
                    sprite->setRotation(sprite->getRotation() + 1);
                }
                if (keyboard->isKeyDown(graphic::IKeyboard::Keys::KEY_S)) {
                    sound->play();
                }
                if (keyboard->isKeyDown(graphic::IKeyboard::Keys::KEY_P)) {
                    music->pause();
                }
            } else {
                std::cout << "isNULL" << std::endl;
            }
            //std::cout << "eventHandler " << std::endl;
        }

        /**
         * @brief update event the game using inherited methods
         */
        void updateHandler() override {
            std::cout << window->getDelta() << std::endl;
            //std::cout << "updateHandler " << std::endl;
            music->update();
        }

        /**
         * @brief render the game using inherited methods
         */
        void displayHandler() override {
            std::cout << "displayHandler" << std::endl;
            //2D
            window->drawSprite(sprite);
            window->drawPoly(poly_star);
            window->drawPoly(poly_heart);
            window->drawText(text);
            //3D
            window->beginMode3(camera);
            window->drawModel(model);
            window->endMode3();
        }

        /**
         * @brief free game's data using inherited methods
         */
        void destroyHandler() override {
            deleteWindow(window);
            deleteEvent(event);
            deletePolygon(poly_star);
            deletePolygon(poly_heart);
            deleteSprite(sprite);
            deleteCamera(camera);
            deleteModel(model);
            deleteKeyboard(keyboard);
            deleteMouse(mouse);
            deleteText(text);
            deleteMusic(music);
            deleteSound(sound);
        }

    public:
        graphic::IWindow *window;
        graphic::IEvent *event;
        graphic::IPolygon *poly_star;
        graphic::IPolygon *poly_heart;
        graphic::ISprite *sprite;
        graphic::ICamera *camera;
        graphic::IModel *model;
        graphic::IText *text;
        //sound
        graphic::ISound *sound;
        graphic::IMusic *music;

        //event
        graphic::IKeyboard *keyboard;
        graphic::IMouse *mouse;

};

/**
 * @brief sort shared library
 * 
 * @param files 
 * @return std::map<std::string, std::vector<std::string>> 
 */
std::map<std::string, std::vector<std::string>> sortSharedLibrary(std::vector<std::string> files) {
    std::map<std::string, std::vector<std::string>> map;
    for (auto& file: files) {
        std::cout << file << std::endl;
        InfoSharedLoader info_shared(file);
        if (!info_shared.getType()) {
            continue;
        }
        std::cout << info_shared.getType() << std::endl;
        map[info_shared.getType()].push_back(file);
    }
    return map;
}

int main() {
    std::cout << "D" << std::endl;
    std::vector<std::string> files = FileSearcher::searchSharedLibraries("./shared");
    std::cout << "Shared Libraries:" << std::endl;
    std::map<std::string, std::vector<std::string>> map = sortSharedLibrary(files);
    std::cout << "C" << std::endl;
    for (auto& [key, value]: map) {
        std::cout << key << std::endl;
        for (auto& file: value) {
            std::cout << "\t" << file << std::endl;
        }
    }
    std::cout << "B" << std::endl;
    std::cout << map["graphic"].size() << std::endl;
    for (auto& file: map["graphic"]) {
        Game game(file);
        game.start();
    }

    std::cout << "A" << std::endl;
    return 0;
}