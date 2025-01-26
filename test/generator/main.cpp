#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Assuming "FlagParser.hpp" is implemented properly elsewhere
#include "FlagParser.hpp"

#define CMAKE_PROJECT_NAME "app"
#define CMAKE "cmake_minimum_required(VERSION 3.14) \n\
project(app) \n\
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
)"
#define MAIN "int main(int ac, char **av) {\n\
    return 0;\n\
}"

int main(int ac, char **av) {
    // Initialize the FlagParser to handle command-line arguments
    FlagParser parser(ac, av);

    // Get the "f" argument (folder list)
    auto folders = parser.get("f");

    // Check if the folders list is empty
    if (folders.empty()) {
        std::cout << "Helper: ./gen_folder -f testX.." << std::endl;
        return 0;
    }

    // Iterate over each folder provided in the argument
    for (const std::string& folder : folders) {
        std::cout << "Creating project in folder: " << folder << std::endl;

        // Create the folder
        std::string command = "mkdir -p " + folder; // Use -p to avoid errors if it already exists
        if (system(command.c_str()) != 0) {
            std::cerr << "Error: Failed to create folder: " << folder << std::endl;
            continue;
        }

        // Create the build/ directory
        command = "mkdir -p " + folder + "/build";
        if (system(command.c_str()) != 0) {
            std::cerr << "Error: Failed to create build folder in: " << folder << std::endl;
            continue;
        }

        // Create a CMakeLists.txt file
        std::string cmakePath = folder + "/CMakeLists.txt";
        std::ofstream cmakeFile(cmakePath);
        if (!cmakeFile) {
            std::cerr << "Error: Could not create CMakeLists.txt in folder: " << folder << std::endl;
            continue;
        }
        cmakeFile << CMAKE;
        cmakeFile.close();

        // Create a main.cpp file
        std::string mainPath = folder + "/main.cpp";
        std::ofstream mainFile(mainPath);
        if (!mainFile) {
            std::cerr << "Error: Could not create main.cpp in folder: " << folder << std::endl;
            continue;
        }
        mainFile << MAIN;
        mainFile.close();

        std::cout << "Project created successfully in folder: " << folder << std::endl;
    }

    return 0;
}