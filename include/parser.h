// Parser header
#ifndef PARSER_H
#define PARSER_H
#include <vector>
#include <string>
#include "lexer.h"

// AST Node base class
struct ASTNode
{
    virtual ~ASTNode() = default;
};

// AST Node types
struct AssignmentNode : ASTNode
{
    AssignmentNode(const std::string &id, ASTNode *e) : identifier(id), expr(e) {}
    std::string identifier;
    ASTNode *expr;
};

struct PrintNode : ASTNode
{
    PrintNode(ASTNode *e) : expr(e) {}
    ASTNode *expr;
};

struct BinaryOpNode : ASTNode
{
    BinaryOpNode(const std::string &o, ASTNode *l, ASTNode *r) : op(o), left(l), right(r) {}
    std::string op;
    ASTNode *left;
    ASTNode *right;
};

struct NumberNode : ASTNode
{
    NumberNode(const std::string &v) : value(v) {}
    std::string value;
};

struct StringNode : ASTNode
{
    StringNode(const std::string &v) : value(v) {}
    std::string value;
};

struct IdentifierNode : ASTNode
{
    IdentifierNode(const std::string &n) : name(n) {}
    std::string name;
};

// Parser interface
class Parser
{
public:
    Parser(const std::vector<Token> &tokens);
    ASTNode *parseProgram();

private:
    const std::vector<Token> &tokens;
    size_t pos;
    const Token &current();
    void advance();
    bool match(TokenType type, const std::string &value = "");
    void expect(TokenType type, const std::string &value = "");
    ASTNode *parseStatement();
    ASTNode *parseAssignment();
    ASTNode *parsePrint();
    ASTNode *parseExpression();
    ASTNode *parseTerm();
};

#endif // PARSER_H
