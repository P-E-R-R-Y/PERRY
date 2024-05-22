#ifndef EMODEL_HPP_
#define EMODEL_HPP_

#include <string>

class EModel {
    public:
        EModel(std::string str): _str(str) { }

        ~EModel() = default;

        friend class EWindow;

    private:
        std::string _str;
};

#endif /* !EMODEL_HPP_ */
