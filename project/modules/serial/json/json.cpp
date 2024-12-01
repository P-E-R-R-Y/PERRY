#ifndef JSON_CPP_
#define JSON_CPP_

#include "JsonSerial.hpp"

extern "C" ISerial *createSerial() {
    return new JsonSerial();
}

extern "C" void deleteSerial(ISerial *serial) {
    delete serial;
}

extern "C" const char *getName() {
    return "json\0";
}

extern "C" const char *getType() {
    return "serial\0";
}

#endif //JSON_CPP_