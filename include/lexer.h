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
    int col = 1;

    std::vector<Token> tokens;

    //helper funcs (add more as you implement)
    
    void scanToken();
    void addToken(TokenType t, const std::string& lexeme, int startCol);

    void handleIdentifier(int tokenStartCol);
    void handleNumber(int tokenStartCol);
    void handleString(int tokenStartCol);

    bool isAtEnd() const;
    char advance();
    char peek();
    bool match(char expected);


};

#endif