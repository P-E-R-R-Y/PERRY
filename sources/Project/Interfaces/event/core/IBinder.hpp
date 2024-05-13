// input handler

#ifndef IINPUT_HPP_
#define IINPUT_HPP_

#include <functional>

class IEvent {
    public:
        virtual ~IEvent() = default;

        virtual void addTrigger(std::function<bool(int)>) = 0;

        virtual bool trigger(std::string function) = 0;
};

#endif