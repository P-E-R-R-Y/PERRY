/**
 *
 * File: main.cpp
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

#include "StringPrintModule.hpp"

int main() {
    const IPrintModule &pm1 = StringPrintModule("Hello World 1");
    IPrintModule *pm2 = new StringPrintModule("Hello World 2");
    StringPrintModule spm("Hello World 3");
    IPrintModule &pm3 = spm;
    //pm1
    pm1.print();
    //pm2
    pm2->set("Hello 2");
    pm2->print();
    //pm3
    pm3.set("Hello 3");
    pm3.print();
    return 0;
}