#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
#include "Lexer.hpp"

// Base AST Node
struct ASTNode {
    virtual ~ASTNode() = default;
}; 

struct LiteralsNode : public ASTNode {
    std::variant<bool, int, double, std::string> value;
};

struct List : public ASTNode {
    std::vector<std::unique_ptr<ASTNode>> nodes;
    std::vector<std::unique_ptr<ASTNode>> nodes;
};

// Variable Node
struct VariableNode : public ASTNode {
    std::string name;
    std::variant<int, float, std::string, bool> value;
};

struct AssignmentNode : public ASTNode {
    std::unique_ptr<VariableNode> variable;
    std::unique_ptr<ASTNode> value;
};


// Function Node
struct FunctionNode : public ASTNode {
    std::string name;
    std::vector<std::string> parameters;
    std::vector<std::unique_ptr<ASTNode>> body;
};

// Assignment Node
struct AssignmentNode : public ASTNode {
    std::unique_ptr<ASTNode> variable;
    std::unique_ptr<ASTNode> value;
};

class Parser {
  public:
    using ASTFunction = std::function<ASTNode()>;

    Parser() = default;
    ~Parser() = default;

    void addASTFunc(ASTFunction handler) {
    }

    std::unique_ptr<ASTNode> parse(const std::vector<Token>& tokens) {
      std::unique_ptr<ASTNode> root = nullptr;
      size_t current = 0;
    }

  private:
};

#endif // PARSER_HPP