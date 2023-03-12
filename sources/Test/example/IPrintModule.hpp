/**
 *
 * File: IPrintModule.hpp
 * Created Date: We Mar 2023
 * Project: PERRY
 * Author: Perry Chouteau
 *
 * Last Modified: Fri Mar 10 2023
 * Modified By: Perry Chouteau
 *
 * Copyright (c) 2023-2033 Perry Chouteau
 *
 **/

class IPrintModule {
    public:

        virtual ~IPrintModule() = default;
        virtual void set(std::string str) = 0;
        virtual std::string get() const = 0;
        virtual void print() const = 0;
};