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

class FlagParser2 {
    public:

        FlagParser2(int ac, char **av) {
            std::string flag = "";

            for (int i = 0; i < ac; i++) {
                if (std::string(av[i]).find("-") == 0) {
                    flag = std::string(av[i]).substr(1);
                } else if (flag != "") {
                    _keyToPos[flag].push_back(_value.size());
                    _value.push_back(av[i]);
                }
            }
        }

        void display() {
            for (auto item : _keyToPos) {
                std::cout << item.first << std::endl;
                for (auto it: item.second) {
                    std::cout << "\t" << it  << ":"<< _value[it] << std::endl;
                }
            }
        }

        std::vector<std::string> get(std::string flag) {
            std::vector<std::string> res;

            for (auto it: _keyToPos[flag])
                res.push_back(_value[it]);
            return res;
        }

        void display(std::string flag) {
            for (auto it: _keyToPos[flag])
                std::cout << _value[it] << std::endl;
        }

    private:

        void strToFlags(int ac, char **av, std::string &str) {
//            str.substr(0, str.find(...));
        }

    private:
        std::map<std::string, std::vector<int>> _keyToPos;
        std::vector<std::string> _value;
};