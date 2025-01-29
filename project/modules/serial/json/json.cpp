/**
 * @file json.cpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-29
 * 
 * @addtogroup serial
 * @{
 * @addtogroup json
 * @{
 */

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