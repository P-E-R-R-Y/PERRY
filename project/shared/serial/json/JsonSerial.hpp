/**
 * @file JsonSerial.hpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-29
 * 
 * @addtogroup serial
 * @{
 * @addtogroup json
 * @{
 */

#ifndef JSON_SERIAL_HPP
#define JSON_SERIAL_HPP

#include <iostream>
#include <variant>
#include <vector>
#include <map>
#include "ISerial.hpp"
#include <nlohmann/json.hpp>
#include <fstream>

using namespace serial;

class JsonSerial: public ISerial {
    public:
        JsonSerial() { 
            loaded = false; 
        };

        ~JsonSerial() {};

        void load(const std::string& path) override {
            try {
                std::ifstream file(path);
                nlohmann::json json = nlohmann::json::parse(file);
                node = json_converter(json);
                loaded = true;
            } catch (nlohmann::json::exception& e) {
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
        Node json_converter(nlohmann::json json) {
            Node n;

            if (json.is_object()) {
                std::map<std::string, Node> m;
                for (auto it = json.begin(); it != json.end(); ++it) {
                    m[it.key()] = json_converter(it.value());
                }
                n.value = m;
            } else if (json.is_array()) {
                std::vector<Node> v;
                for (auto it = json.begin(); it != json.end(); ++it) {
                    v.push_back(json_converter(*it));
                }
                n.value = v;
            } else if (json.is_string()) {
                n.value = Node::node_type(json.get<std::string>());
            } else if (json.is_number_integer()) {
                n.value = Node::node_type(json.get<int>());
            } else if (json.is_number_float()) {
                n.value = Node::node_type(json.get<double>());
            } else if (json.is_boolean()) {
                n.value = Node::node_type(json.get<bool>());
            } else if (json.is_null()) {
                n.value = static_cast<void *>(nullptr);
            } else {
                throw std::runtime_error("Node is not a scalar, map or sequence");
            }
            return n;
        }
};

#endif // JSON_SERIAL_HPP