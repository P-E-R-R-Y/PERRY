

#include "Snake.hpp"

///Windowing
extern "C" ICore *createGame(std::string title) {
    return new Snake(std::string("SnakeGame " + title));
}

extern "C" const char *getName() {
    return "snake\0";
}

extern "C" const char *getType() {
    return "core\0";
}