/**
 * @file FlagParser.hpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-29
 * 
 * @addtogroup utility
 * @{
 */

#include <map>
#include <vector>
#include <string>
#include <iostream>

/**
 * @brief 
 * 
 */
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
        std::map<std::string, std::vector<std::string>> _keyValue;
};
