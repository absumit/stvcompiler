#include "../include/lexer.h"
#include <iostream>

std::string tokenTypeToString(TokenType type)
{
    switch (type)
    {
    case TokenType::Identifier:
        return "Identifier";
    case TokenType::Number:
        return "Number";
    case TokenType::String:
        return "String";
    case TokenType::Equals:
        return "Equals";
    case TokenType::Plus:
        return "Plus";
    case TokenType::Minus:
        return "Minus";
    case TokenType::Semicolon:
        return "Semicolon";
    case TokenType::Print:
        return "Print";
    case TokenType::EndOfFile:
        return "EndOfFile";
    default:
        return "Unknown";
    }
}

int main(int argc, char*argv[])
{
    if(argc<2){
        std::cerr<<"Usage: "<<argv[0]<<" <input file>"<<std::endl;
        return 1;
    }
    std::string inputFile = argv[1];
    auto tokens = tokenize(inputFile);
    for (const auto &token : tokens)
    {
        std::cout << tokenTypeToString(token.type) << ": '" << token.value << "'\n";
    }
    return 0;
}
