#ifndef LEXER_H
#define LEXER_H
#include <string>
#include <vector>

enum class TokenType
{
    Identifier,
    Number,
    String,
    Equals,
    Minus,
    Plus,
    Semicolon,
    Print,
    EndOfFile
};

struct Token
{
    TokenType type;
    std::string value;
};

std::vector<Token> tokenize(const std::string &filename);

#endif // LEXER_H
