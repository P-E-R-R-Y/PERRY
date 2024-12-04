#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "Lexer.hpp"
#include "Parser.hpp"

void initLexer(Lexer &lexer ) {
    const std::vector<std::pair<std::string, uint16_t>> types = {
        //words
        {"key", 0}, //stands for keyword
        {"type", 1},
        {"id", 2}, //stands for identifier
        //types
        {"bool", 3}, //stands for boolean
        {"int", 4}, //stands for integer
        {"float", 5},
        {"string", 6},
        {"void", 7},
        //signs
        {"ope", 8}, //stands for operator
        {"sep", 9} //stands for separator
    };

    const std::vector<std::pair<std::string, Lexer::RuleFunction>> rules = {
        //keywords
        {"\\b(import|struct|var|func|if|while|return)\\b", [&lexer](const std::smatch& match) {
            return Token(lexer.at("key"), match.str());
        }},
        {"\\b(int|float|string|bool)\\b", [&lexer](const std::smatch& match) {
            return Token(lexer.at("type"), match.str());
        }},
        //bool
        {"\\b(true|false)\\b", [&lexer](const std::smatch& match) {
            return Token(lexer.at("bool"), match.str());
        }},
        //id.s
        {"[a-zA-Z_][a-zA-Z0-9_]*", [&lexer](const std::smatch& match) {
            return Token(lexer.at("id"), match.str());
        }},
        //types
        {"\\b\\d+\\b", [&lexer](const std::smatch& match) {
            return Token(lexer.at("int"), match.str());
        }},
        {"\".*?\"", [&lexer](const std::smatch& match) {
            return Token(lexer.at("string"), match.str());
        }},
        {"\\b\\d+\\.\\d+\\b", [&lexer](const std::smatch& match) {
            return Token(lexer.at("float"), match.str());
        }},
        //signs
        {"[=+*-/!]", [&lexer](const std::smatch& match) {
            return Token(lexer.at("ope"), match.str());
        }},
        {"[;(){}:]", [&lexer](const std::smatch& match) {
            return Token(lexer.at("sep"), match.str());
        }}
    };

    for (const auto& [name, type] : types) {
        lexer.addType(name, type);
    }

    for (const auto& [pattern, handler] : rules) {
        lexer.addRule(pattern, handler);
    }
}

void initParser(Parser &parser, Lexer &lexer) {
    parser.addASTFunc(lexer.at("key"), [&parser, &lexer](std::vector<Token>& tokens, size_t& pos) -> std::shared_ptr<AST::Node> {
        if (tokens[pos].value == "import") {
            auto node = std::make_shared<AST::ImportNode>();
            node->path = tokens[++pos].value;
            return node;
        }
        if (tokens[pos].value == "var") {
            std::vector<Token> vars;
            for (int i = 0; tokens[pos + i].value != ";"; ++i) {
                vars.push_back(tokens[pos + i]);
            }
            if (vars.size() == 2) {
                pos += 2;
                return std::make_shared<AST::VariableNode>(
                    vars[1].value,
                    nullptr
                );
            }
            if (vars.size() == 4) {
                pos += vars.size();
                return std::make_shared<AST::VariableNode>(
                    vars[1].value,
                    std::make_shared<AST::Literals>(vars[3].value)
                );
            }
        }
        if (tokens[pos].value == "func") {
            std::string name = tokens[++pos].value;
            std::vector<std::shared_ptr<AST::Node>> args;
            std::shared_ptr<AST::LockType> ret_type = nullptr;
            std::shared_ptr<AST::Node> body = nullptr;
            std::vector<Token> temp;

            if (tokens[++pos].value != "(") {
                return nullptr;
            }
            if (tokens[++pos].value != ")") {
                return nullptr;
            }
            if (tokens[++pos].type == lexer.at("type")) {
                ret_type = std::make_shared<AST::LockType>(tokens[pos].value);
            } else {
                ret_type = nullptr;
                --pos;
            }
            if (tokens[++pos].value != "{") {
                return nullptr;
            }
            while (tokens[++pos].value != "}") {
                temp.push_back(tokens[pos]);
            }
            std::cout << "----size: "<< temp.size() << std::endl;
            for (const auto& token : temp) {
                std::cout << "------: " << lexer.at(token.type) << ": " << token.value << std::endl;
            }
            if (!temp.empty()) {
                body = parser.parse(temp);
            }
            return std::make_shared<AST::FunctionNode>(name, args, ret_type, body);
        }
        return nullptr;
    });
}

int main() {
    Lexer lexer;
    Parser parser;
    initLexer(lexer);
    initParser(parser, lexer);
    // Rule for keywords

    auto tokens = lexer.tokenize("../test.go");

    for (const auto& token : tokens) {
        std::cout << lexer.at(token.type) << ": " << token.value << std::endl;
    }

    auto ast = parser.parse(tokens);

    ast->print();
    return 0;
}
