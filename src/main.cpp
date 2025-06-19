#include "lexer.h"
#include "parser.h"
#include <iostream>

void printAST(ASTNode *node, int indent = 0)
{
    if (!node)
        return;
    std::string ind(indent, ' ');
    if (auto *n = dynamic_cast<AssignmentNode *>(node))
    {
        std::cout << ind << "Assignment: " << n->identifier << std::endl;
        printAST(n->expr, indent + 2);
    }
    else if (auto *n = dynamic_cast<PrintNode *>(node))
    {
        std::cout << ind << "Print:" << std::endl;
        printAST(n->expr, indent + 2);
    }
    else if (auto *n = dynamic_cast<BinaryOpNode *>(node))
    {
        std::cout << ind << "BinaryOp: " << n->op << std::endl;
        printAST(n->left, indent + 2);
        printAST(n->right, indent + 2);
    }
    else if (auto *n = dynamic_cast<NumberNode *>(node))
    {
        std::cout << ind << "Number: " << n->value << std::endl;
    }
    else if (auto *n = dynamic_cast<StringNode *>(node))
    {
        std::cout << ind << "String: " << n->value << std::endl;
    }
    else if (auto *n = dynamic_cast<IdentifierNode *>(node))
    {
        std::cout << ind << "Identifier: " << n->name << std::endl;
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <input file>" << std::endl;
        return 1;
    }
    std::string inputFile = argv[1];
    auto tokens = tokenize(inputFile);
    try
    {
        Parser parser(tokens);
        ASTNode *ast = parser.parseProgram();
        std::cout << "\n--- AST ---\n";
        printAST(ast);
        delete ast;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Parse error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
