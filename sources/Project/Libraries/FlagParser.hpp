/**
 *
 * File: FlagParser.hpp
 * Created Date: We Mar 2023
 * Project: PERRY
 * Author: Perry Chouteau
 *
 * Last Modified: Wed Mar 15 2023
 * Modified By: Perry Chouteau
 *
 * Copyright (c) 2023-2033 Perry Chouteau
 *
 **/

#include <map>
#include <vector>
#include <string>
#include <iostream>

class FlagParser {
    public:

        FlagParser(int ac, char **av) {
            std::string flag = "";

            for (int i = 0; i < ac; i++) {
                if (std::string(av[i]).find("-") == 0)
                    flag = std::string(av[i]).substr(1);
                else if (flag != "")
                    _keyValue[flag].push_back(av[i]);
            }
        }

        void display() {
            for (auto item : _keyValue) {
                std::cout << item.first << std::endl;
                for (auto it: item.second)
                    std::cout << "\t" << it << std::endl;
            }
        }

        void display(std::string flag) {
            for (auto it: _keyValue[flag])
                std::cout << it << std::endl;
        }

        std::map<std::string, std::vector<std::string>> get() {
            return _keyValue;
        }

        std::vector<std::string> get(std::string flag) {
            std::vector<std::string> res;

            for (auto it: _keyValue[flag])
                res.push_back(it);
            return res;
        }

    private:

        void strToFlags(int ac, char **av, std::string &str) {
//            str.substr(0, str.find(...));
        }

    private:
        std::map<std::string, std::vector<std::string>> _keyValue;
};
