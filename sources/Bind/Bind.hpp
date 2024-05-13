// input handler

#ifndef IBIND_HPP_
#define IBIND_HPP_

#include <functional>

class Binder : public IBinder{
    public:
        Binder() {
            _binds = std::vector<std::string, std::function<void()>>();
            _binds.data();
        
        };
        ~Binder() = default;

        void createAction(std::string action);
        void addBind(std::string action, std::function<void()>);
        void setBind(std::string action, std::function<void()>);
        void getBind(std::string action) = 0;
        void deleteBind(std::string action) = 0;
        void deleteAllBinds() = 0;

        std::vector<std::string, std::function<void()>> _binds;

    private:

};

//ecran ->
//action ->

//ecran
  //jeu -> action1
  //menu -> action2

//action -> avancer
//joystick -> avancer

//isAvancer()


#endif /* !IBIND_HPP_ */