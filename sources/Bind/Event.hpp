// input handler

#ifndef IINPUT_HPP_
#define IINPUT_HPP_

#include <functional>
#include <typeindex>
#include <vector>
#include <string>

class Scope;

class Event {
    public:
        Event() {};
        ~Event() = default;
        void addBool(int value, std::function<bool()> func) {
            _boolTriggers[value] = func;
        }
        void addInt(int value, std::function<int()> func) {
            _intTriggers[value] = func;
        }
        void addFloat(int value, std::function<float()> func) {
            _floatTriggers[value] = func;
        }
        void addString(int value, std::function<std::string()> func) {
            _stringTriggers[value] = func;
        }
        
        bool getBool(int value) {
            return _boolTriggers[value]();
        }
        int getInt(int value) {
            return _intTriggers[value]();
        }
        float getFloat(int value) {
            return _floatTriggers[value]();
        }
        std::string getString(int value) {
            return _stringTriggers[value]();
        }

    private:
        std::unordered_map<int, std::function<bool()>> _boolTriggers;
        std::unordered_map<int, std::function<int()>> _intTriggers;
        std::unordered_map<int, std::function<float()>> _floatTriggers;
        std::unordered_map<int, std::function<std::string()>> _stringTriggers;
};

#endif