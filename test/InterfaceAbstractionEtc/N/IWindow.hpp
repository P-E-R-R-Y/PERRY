#ifndef IWINDOW_HPP_
    #define IWINDOW_HPP_
    #include "IModel.hpp"

class IWindow {
    public:
        ~IWindow() = default;

        virtual void draw(IModel *model) = 0;
    private:
        //vars
};

#endif /* !IWINDOW_HPP_ */