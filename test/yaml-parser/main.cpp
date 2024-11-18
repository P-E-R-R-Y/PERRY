#include <iostream>
#include <fstream>
#include <yaml-cpp/yaml.h>
#include <variant>
#include <vector>
#include <string>

struct dynamic_t {
    bool dynamic;
    bool selector;
};

struct config_t {
    int cmake_version;
    std::string name;
    int cpp_version;
    std::vector<std::string> flags;
    dynamic_t dynamic;
    std::vector<std::string> interfaces;
    std::vector<std::string> libraries;
};

using yaml = std::variant<config_t, YAML::Exception>;

yaml retrieveConfig(const std::string& filename) {
    try {
        YAML::Node yaml = YAML::LoadFile(filename);
        config_t config;

        if (yaml["cmake_version"]) {
            config.cmake_version = yaml["cmake_version"].as<int>();
        }

        if (yaml["name"]) {
            config.name = yaml["name"].as<std::string>();
        }

        if (yaml["cpp_version"]) {
            config.cpp_version = yaml["cpp_version"].as<int>();
        }
        if (yaml["flags"]) {
            for (const auto& flag : yaml["flags"]) {
                config.flags.push_back(flag.as<std::string>());
            }
        }
        if (yaml["dynamic"]) {
            if (yaml["dynamic"]["dynamic"]) {
                config.dynamic.dynamic = yaml["dynamic"]["dynamic"].as<bool>();
            }
            if (yaml["dynamic"]["selector"]) {
                config.dynamic.selector = yaml["dynamic"]["selector"].as<bool>();
            }
        }
        if (yaml["interfaces"]) {
            for (const auto& interface : yaml["interfaces"]) {
                config.interfaces.push_back(interface.as<std::string>());
            }
        }
        if (yaml["libraries"]) {
            for (const auto& library : yaml["libraries"]) {
                config.libraries.push_back(library.as<std::string>());
            }
        }
        return config;
    } catch (const YAML::Exception& e) {
        return e;
    }
}

void printConfig(const config_t config) {
    // Successfully loaded config, display information

    std::cout << "CPP Version: " << config.cpp_version << std::endl;

    std::cout << std::endl;
    std::cout << "Flags:" << std::endl;
    for (const auto& flag : config.flags) {
        std::cout << flag << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Dynamic settings" << std::endl << "\tdynamic: " << config.dynamic.dynamic << std::endl << "\tselector: " << config.dynamic.selector << std::endl;
    std::cout << std::endl;

    std::cout << "Interfaces:" << std::endl;
    for (const auto& interface : config.interfaces) {
        std::cout << "\t" << interface << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Libraries:" << std::endl;
    for (const auto& library : config.libraries) {
        std::cout << "\t" << library << std::endl;
    }
}

#include "Cmake.cpp"

void createCmake(const std::string& path,const config_t config) {

    CmakeBuilder cmake;
    cmake.open(path);
    cmake.addCmakeMinimumRequired(config.cmake_version);
    cmake.addProject(config.name);
    cmake.addCMakeCXXStandard(config.cpp_version);
    cmake.addExecutable(config.name, "main.cpp");
    cmake.addTargetCompileOptions(config.flags);
    cmake.addTargetLinkLibraries(config.libraries);
    cmake.close();
}

int main() {
    yaml yaml = retrieveConfig("config.yaml");

    if (std::holds_alternative<YAML::Exception>(yaml)) {
        const auto& e = std::get<YAML::Exception>(yaml);
        std::cerr << "Failed to load config: " << e.what() << std::endl;
        return -1;
    }
    auto config = std::get<config_t>(yaml);
    printConfig(config);
    createCmake("builda",config);
    return 0;
}