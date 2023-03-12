/**
 *
 * File: StringPrintModule.hpp
 * Created Date: We Mar 2023
 * Project: PERRY
 * Author: Perry Chouteau
 *
 * Last Modified: Thu Mar 09 2023
 * Modified By: Perry Chouteau
 *
 * Copyright (c) 2023-2033 Perry Chouteau
 *
 **/

#include <iostream>
#include "IPrintModule.hpp"

class StringPrintModule : public IPrintModule {
    public:
        StringPrintModule() { _value = ""; };
        StringPrintModule(std::string str) { _value = str; };
        StringPrintModule(const StringPrintModule &other)  { _value = other._value; };
        StringPrintModule(const StringPrintModule &&other) { _value = other._value; };

        void set(std::string str) override {
            _value = str;
        }

        std::string get() const override {
            return _value;
        }

        virtual void print() const override {
            std::cout << _value << std::endl;
        }

    private:
        std::string _value;
};