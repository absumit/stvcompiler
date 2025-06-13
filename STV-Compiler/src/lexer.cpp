#include "../include/lexer.h"
#include <fstream>
#include <cctype>

std::vector<Token> tokenize(const std::string &filename)
{
    std::vector<Token> tokens;
    std::ifstream file(filename);
    char ch;
    while (file.get(ch))
    {
        if (std::isspace(ch))
            continue;
        if (std::isalpha(ch) || ch == '_')
        {
            std::string ident;
            ident += ch;
            while (file.get(ch) && (std::isalnum(ch) || ch == '_'))
                ident += ch;
            if (!file.eof())
                file.unget();
            if (ident == "print")
                tokens.push_back({TokenType::Print, ident});
            else
                tokens.push_back({TokenType::Identifier, ident});
        }
        else if (std::isdigit(ch))
        {
            std::string number;
            number += ch;
            while (file.get(ch) && std::isdigit(ch))
                number += ch;
            if (!file.eof())
                file.unget();
            tokens.push_back({TokenType::Number, number});
        }
        else if (ch == '"')
        {
            std::string str;
            while (file.get(ch) && ch != '"')
                str += ch;
            tokens.push_back({TokenType::String, str});
        }
        else if (ch == '=')
        {
            tokens.push_back({TokenType::Equals, "="});
        }
        else if (ch == '+')
        {
            tokens.push_back({TokenType::Plus, "+"});
        }
        else if (ch == ';')
        {
            tokens.push_back({TokenType::Semicolon, ";"});
        }
    }
    tokens.push_back({TokenType::EndOfFile, ""});
    return tokens;
}
