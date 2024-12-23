#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>
#include "token.h"

class Lexer {
public:
    explicit Lexer(const std::string& src);
    std::vector<Token> tokenize();

private:
    const std::string& src;
    int start = 0; //start index of current token
    int curr = 0; 
    int line = 1;
    int column = 1;

    std::vector<Token> tokens;
};

#endif