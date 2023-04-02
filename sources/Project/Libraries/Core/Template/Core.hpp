/**
 *
 * File: Core.hpp (header.v2)
 * Created Date: Sat 18/03/2023
 * Project: PERRY
 * Author: Perry Chouteau
 *
 * Last Modified: Sat 18/03/2023
 * Modified By: Perry Chouteau
 *
 * Copyright (c) 2023-2033 Perry Chouteau
 *
 **/

class Core {
    public:
        virtual ~Core() = default;

        virtual int Run(std::vector<std::string> files) = 0;

    protected:
        virtual void initHandler() = 0;

        virtual void eventHandler() = 0;

        virtual void updateHandler() = 0;

        virtual void displayHandler() = 0;
};
