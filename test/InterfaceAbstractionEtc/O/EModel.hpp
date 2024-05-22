#ifndef EMODEL_HPP_
#define EMODEL_HPP_

class EModel {
    public:
        EModel(std::string str): _str(str) { }

        ~EModel() = default;

        friend class EWindow;

    private:
        void draw(EWindow *obj);

        std::string _str;
};

#include <string>
#include <iostream>
#include "EWindow.hpp"

void EModel::draw(EWinow *obj)
{
    std::cout << obj._str << std::endl;
}

#endif /* !EMODEL_HPP_ */
