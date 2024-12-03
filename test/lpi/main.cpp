#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "Lexer.hpp"
//#include "Parser.hpp"

const std::vector<std::pair<std::string, uint16_t>> types = {
    {"keyword", 0},
    {"type", 1},
    {"identifier", 2},
    {"string", 3},
    {"int", 4},
    {"float", 5},
    {"Boolean", 6},
    {"Operator", 7},
    {"Separator", 8}
};

void initLexer(Lexer &lexer ) {
    const std::vector<std::pair<std::string, uint16_t>> types = {
        {"keyword", 0},
        {"type", 1},
        {"identifier", 2},
        {"string", 3},
        {"int", 4},
        {"float", 5},
        {"Boolean", 6},
        {"Operator", 7},
        {"Separator", 8}
    };

    const std::vector<std::pair<std::string, Lexer::RuleFunction>> rules = {
        {"\\b(var|func|if|while|return)\\b", [&lexer](const std::smatch& match) {
            return Token(lexer.at("keyword"), match.str());
        }},
        {"\\b(int|float|string|bool)\\b", [&lexer](const std::smatch& match) {
            return Token(lexer.at("type"), match.str());
        }},
        {"\\b(true|false)\\b", [&lexer](const std::smatch& match) {
            return Token(lexer.at("Boolean"), match.str());
        }},
        {"[a-zA-Z_][a-zA-Z0-9_]*", [&lexer](const std::smatch& match) {
            return Token(lexer.at("identifier"), match.str());
        }},
        {"\".*?\"", [&lexer](const std::smatch& match) {
            return Token(lexer.at("string"), match.str());
        }},
        {"\\b\\d+\\.\\d+\\b", [&lexer](const std::smatch& match) {
            return Token(lexer.at("float"), match.str());
        }},
        {"\\b\\d+\\b", [&lexer](const std::smatch& match) {
            return Token(lexer.at("int"), match.str());
        }},
        {"[=+*-/!]", [&lexer](const std::smatch& match) {
            return Token(lexer.at("Operator"), match.str());
        }},
        {"[;(){}:]", [&lexer](const std::smatch& match) {
            return Token(lexer.at("Separator"), match.str());
        }}
    };

    for (const auto& [name, type] : types) {
        lexer.addType(name, type);
    }

    for (const auto& [pattern, handler] : rules) {
        lexer.addRule(pattern, handler);
    }
}

/*void initParser(Parser &parser) {
    const std::vector<std::pair<std::string, Parser::ASTFunction>> funcs = {
    };
}*/

int main() {
    Lexer lexer;
    //Parser parser;
    initLexer(lexer);
    //initParser(parser);
    // Rule for keywords

    auto tokens = lexer.tokenize("../test.go");

    for (const auto& token : tokens) {
        //inverse of types[token.key];
        std::cout << lexer.at(token.type) << " " << token.value << std::endl;   
    }

    //auto ast = parser.parse(tokens);
    return 0;
}
