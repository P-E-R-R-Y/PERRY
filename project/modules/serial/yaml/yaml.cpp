#ifndef YAML_CPP_
#define YAML_CPP_

#include "YamlSerial.hpp"

extern "C" ISerial *createSerial() {
    return new YamlSerial();
}

extern "C" void deleteSerial(ISerial *serial) {
    delete serial;
}

extern "C" const char *getName() {
    return "yaml\0";
}

extern "C" const char *getType() {
    return "serial\0";
}

#endif //YAML_HPP_