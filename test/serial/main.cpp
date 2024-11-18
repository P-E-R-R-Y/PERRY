#include "ISerial.hpp"
#include "YamlSerial.hpp"
#include "JsonSerial.hpp"

std::string duplicate(std::string str, int n) {
    std::string result = "";
    for (int i = 0; i < n; i++) {
        result += str;
    }
    return result;
}

void yaml_print(YAML::Node node, int level = 0) {
            if (node.IsMap()) {
                for (auto it = node.begin(); it != node.end(); ++it) {
                    std::cout << duplicate("|", level) << it->first.as<std::string>() << ": " << std::endl;
                    yaml_print(it->second , level + 1);
                }
            } else if (node.IsSequence()) {
                for (auto it = node.begin(); it != node.end(); ++it) {
                    yaml_print(*it, level + 1);
                }
            } else if (node.IsScalar() == true) {
                std::cout << duplicate("|", level) << node.as<std::string>() << std::endl;
            } else if (node.IsNull()) {
                std::cout << duplicate("|", level) << "nullptr" << std::endl;
            } else {
                throw std::runtime_error("Node is not a scalar, map or sequence");
            }
        }

void node_print(Node node, int level = 0) {
    if (node.isMap()) {
        std::map<std::string, Node> m = std::get<std::map<std::string, Node>>(node.value);
        for (auto it = m.begin(); it != m.end(); ++it) {
            std::cout << duplicate("  ", level + 1) << "msk " << it->first << ": " << std::endl;
            node_print(it->second, level + 2);
        }
    } else if (node.isSequence()) {
        std::vector<Node> v = std::get<std::vector<Node>>(node.value);
        for (auto it = v.begin(); it != v.end(); ++it) {
            std::cout << duplicate("  ", level +1) << "- " << std::endl;
            node_print(*it, level + 2);
        }
    } else if (node.isScalar()) {
        if (node.isInt()) {
            std::cout << duplicate("  ", level) << "int " << std::get<int>(node.value) << std::endl;
        } else if (node.isDouble()) {
            std::cout << duplicate("  ", level) << "double " << std::get<double>(node.value) << std::endl;
        } else if (node.isBool()) {
            std::cout << duplicate("  ", level) << "bool " << std::get<bool>(node.value) << std::endl;
        } else if (node.isString()) {
            std::cout << duplicate("  ", level) << "str " << std::get<std::string>(node.value) << std::endl;
        } else {
            throw std::runtime_error("Unknown scalar type");
        }
    } else if (node.isNull()) {
        std::cout << duplicate("  ", level) << "null null" << std::endl;
    } else {
        throw std::runtime_error("Node is not a scalar, map or sequence");
    }
}

int main() {
    //YAML
    ISerial* ds = new YamlSerial();
    ds->load("../config.yaml");    
    if (ds->isLoaded()) {
        Node n = ds->getRoot();
        std::cout << "getRoot succeed" << std::endl;
        node_print(n);
        std::cout << n["settings"]["debug"]["start"].as<std::string>() << std::endl;
    }
    delete ds;
    ds = new JsonSerial();
    ds->load("../config.json");
    if (ds->isLoaded()) {
        Node n = ds->getRoot();
        std::cout << "getRoot succeed" << std::endl;
        node_print(n);
        std::cout << n["settings"]["debug"]["start"].as<std::string>() << std::endl;

    }
    delete ds;
    return 0;
}