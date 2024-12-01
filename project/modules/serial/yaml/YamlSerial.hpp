#ifndef YAML_SERIAL_HPP
#define YAML_SERIAL_HPP

#include <iostream>
#include <variant>
#include <vector>
#include <map>
#include <yaml-cpp/yaml.h>
#include "ISerial.hpp"

class YamlSerial: public ISerial {
    public:
        YamlSerial() { 
            loaded = false; 
        };

        ~YamlSerial() {};

        void load(const std::string& path) override {
            try {
                YAML::Node yaml = YAML::LoadFile(path);
                node = yaml_converter(yaml);
                loaded = true;
            } catch (YAML::Exception& e) {
                std::cout << e.what() << std::endl;
            }
        }

        bool isLoaded() override{
            return loaded;
        }

        void close() override{
             node = Node();   // Clear the node
            loaded = false;  // Reset the loaded flag
        }

        Node getRoot() override {
            return node;
        }
    
    private:
        Node node;
        bool loaded;

    //private function needed to convert yaml to Node
    private:
        Node yaml_converter(YAML::Node node) {
            Node n;

            if (node.IsMap()) {
                std::map<std::string, Node> m;
                for (auto it = node.begin(); it != node.end(); ++it) {
                    std::cout << it->first << std::endl;
                    m[it->first.as<std::string>()] = yaml_converter(it->second);
                }
                n.value = m;
            } else if (node.IsSequence()) {
                std::vector<Node> v;
                for (auto it = node.begin(); it != node.end(); ++it) {
                    v.push_back(yaml_converter(*it));
                }
                n.value = v;
            } else if (node.IsScalar() == true) {
                std::cout << node << std::endl;
                if (is<int>(node)) {
                    n.value = node.as<int>();
                } else if (is<double>(node)) {
                    n.value = node.as<double>();
                } else if (is<std::string>(node) && (node.as<std::string>() == "true" || node.as<std::string>() == "false")) {
                    n.value = node.as<bool>();
                } else if (is<std::string>(node)) {
                    n.value = node.as<std::string>();
                } else {
                    throw std::runtime_error("Unknown scalar type");
                }
            } else if (node.IsNull()) {
                n.value = static_cast<void *>(nullptr);
            } else {
                throw std::runtime_error("Node is not a scalar, map or sequence");
            }
            return n;
        }

        template <typename T>
        bool is(const YAML::Node& node) {
            std::stringstream ss(node.as<std::string>());
            T temp;
            ss >> std::noskipws >> temp;
            return ss.eof() && !ss.fail();
        }
};

#endif // YAML_SERIAL_HPP