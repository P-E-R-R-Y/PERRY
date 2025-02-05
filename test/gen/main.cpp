/**
 * @file main.cpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-30
 */

#include <iostream>
#include <filesystem>
#include <fstream>
#include "FlagParser.hpp"

static const char* CMAKELISTS_TXT = "cmake_minimum_required(VERSION 3.14) \n\
project(app)\n\
\n\
set(CMAKE_CXX_STANDARD 20)\n\
set(CMAKE_CXX_STANDARD_REQUIRED ON)\n\
\n\
set(SOURCE_FILES\n\
  main.cpp\n\
)\n\
\n\
add_executable(${PROJECT_NAME} ${SOURCE_FILES})\n\
\n\
target_include_directories(${PROJECT_NAME} PUBLIC\n\
  ./\n\
)";

static const char* MAIN_CPP = "/**\n\
 * @file main.cpp\n\
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)\n\
 * @brief \n\
 * @version 0.1\n\
 * @date 2025-01-30\n\
 */\n\
\n\
int main(int ac, char **av) {\n\
    return 0;\n\
}";

int main(int ac, char **av) {
    FlagParser parser(ac, av);

    std::vector<std::string> dir_names = parser.get("f");

    if (dir_names.size() == 0) {
        std::cerr << "./gen_test -f dir1 ...\n";
        return 1;
    }

    for (auto dir_name : dir_names) {
        // Create directory "a"
        if (!std::filesystem::exists(dir_name)) {
            std::filesystem::create_directory(dir_name);
            std::filesystem::create_directory(dir_name + "/build");
            std::cout << "Directory " + dir_name + " created.\n";
        } else {
            std::cerr << "Directory " + dir_name + " already exists.\n";
        }

        //
        std::ofstream mainf(dir_name + "/main.cpp");
        if (mainf) {
            mainf << MAIN_CPP;
            mainf.close();
        } else {
            std::cerr << "Failed to create file " + dir_name + "/main.cpp\n";
        }
        //
        std::ofstream cmakef(dir_name + "/CMakeLists.txt");
        if (cmakef) {
            cmakef << CMAKELISTS_TXT;
            cmakef.close();
        } else {
            std::cerr << "Failed to create file " + dir_name + "/CMakeLists.txt\n";
        }

        system(std::string("cd " + dir_name + "/build && cmake .. && cmake --build .").c_str());
        
    }

    return 0;
}