#include "parser.h"
#include <stdexcept>
#include <iostream>

Parser::Parser(const std::vector<Token> &tokens) : tokens(tokens), pos(0) {}

const Token &Parser::current()
{
    if (pos < tokens.size())
        return tokens[pos];
    static Token eof{TokenType::EndOfFile, ""};
    return eof;
}

void Parser::advance()
{
    if (pos < tokens.size())
        ++pos;
}

bool Parser::match(TokenType type, const std::string &value)
{
    if (current().type == type && (value.empty() || current().value == value))
    {
        advance();
        return true;
    }
    return false;
}

void Parser::expect(TokenType type, const std::string &value)
{
    if (!match(type, value))
    {
        throw std::runtime_error("Unexpected token: " + current().value);
    }
}

ASTNode *Parser::parseProgram()
{
    // For now, parse a single statement. You can extend this to a list.
    return parseStatement();
}

ASTNode *Parser::parseStatement()
{
    if (current().type == TokenType::Identifier && current().value == "let")
    {
        return parseAssignment();
    }
    else if (current().type == TokenType::Print)
    {
        return parsePrint();
    }
    else
    {
        throw std::runtime_error("Unknown statement");
    }
}

ASTNode *Parser::parseAssignment()
{
    expect(TokenType::Identifier, "let");
    expect(TokenType::Identifier);
    std::string varName = tokens[pos - 1].value;
    expect(TokenType::Equals);
    ASTNode *expr = parseExpression();
    expect(TokenType::Semicolon);
    return new AssignmentNode(varName, expr);
}

ASTNode *Parser::parsePrint()
{
    expect(TokenType::Print);
    ASTNode *expr = parseExpression();
    expect(TokenType::Semicolon);
    return new PrintNode(expr);
}

ASTNode *Parser::parseExpression()
{
    ASTNode *left = parseTerm();
    while (current().type == TokenType::Plus || current().type == TokenType::Minus)
    {
        std::string op = current().type == TokenType::Plus ? "+" : "-";
        advance();
        ASTNode *right = parseTerm();
        left = new BinaryOpNode(op, left, right);
    }
    return left;
}

ASTNode *Parser::parseTerm()
{
    if (current().type == TokenType::Number)
    {
        std::string val = current().value;
        advance();
        return new NumberNode(val);
    }
    else if (current().type == TokenType::String)
    {
        std::string val = current().value;
        advance();
        return new StringNode(val);
    }
    else if (current().type == TokenType::Identifier)
    {
        std::string name = current().value;
        advance();
        return new IdentifierNode(name);
    }
    throw std::runtime_error("Expected number, string, or identifier");
}
