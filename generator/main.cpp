#include <iostream>
#include <fstream>
#include <yaml-cpp/yaml.h>
#include "ISerial.hpp"
#include "YamlSerial.hpp"


int main() {
    ISerial *yaml = new YamlSerial();
    yaml->load("../config.yaml");
    Node node = yaml->getRoot();
    //---------------------------
    std::cout << node["name"].as<std::string>() << std::endl;
    std::cout << node["binary"].as<std::string>() << std::endl;

    //system is c function. how to do in c++?
    std::string folder = node["name"].as<std::string>();
    std::filesystem::create_directories(folder);
    //---------------------------
    //add folder inside (interfaces, libraries, shared, assets)
    std::vector<std::string> defaultfolders = {"interfaces", "libraries", "shared", "assets"};
    for (auto it = defaultfolders.begin(); it != defaultfolders.end(); ++it) {
        std::filesystem::create_directories(folder + "/" + *it);
    }
    //
    //add CMakeList file
    std::ofstream file(folder + "/CMakeLists.txt");
    file << "cmake_minimum_required(VERSION 3.10)\n";
    file << "project(" << node["name"].as<std::string>() << ")\n";
    file << "add_executable(" << node["name"].as<std::string>() << " " << node["binary"].as<std::string>() << ")\n";
    file << "target_include_directories(" << node["name"].as<std::string>() << " PUBLIC interfaces)\n";
    file << "target_include_directories(" << node["name"].as<std::string>() << " PUBLIC libraries)\n";
    file << "target_include_directories(" << node["name"].as<std::string>() << " PUBLIC shared)\n";
    file << "target_include_directories(" << node["name"].as<std::string>() << " PUBLIC assets)\n";
    file << "target_link_libraries(" << node["name"].as<std::string>() << " PUBLIC ";
    //close ?
    file.close();

    std::vector<Node> v = std::get<std::vector<Node>>(node["libraries"].value);
    for (auto it = v.begin(); it != v.end(); ++it) {
//        std::cout << " - " << it->operator[]("name").as<std::string>() << std::endl;
        if (it->operator[]("type").isString()) {
            std::cout << " - " << it->operator[]("type").as<std::string>() << std::endl;
            std::cout << " - " << it->operator[]("name").as<std::string>() << std::endl;
        } else {
            std::cout << " - " << it->operator[]("name").as<std::string>() << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}