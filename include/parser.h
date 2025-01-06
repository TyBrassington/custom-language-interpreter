//
// Created by tybra on 1/6/2025.
//

#ifndef PARSER_H
#define PARSER_H
#include <vector>
#include "token.h"


class Parser {
public:
    explicit Parser(const std::vector<Token>& tokens);

private:
    const std::vector<Token>& tokens;
    int currToken = 0;

    //helper funcs
    bool isAtEnd() const;
    const Token& peek() const;
    const Token& prev() const;
    const Token& advance();

    bool match(std::initializer_list<TokenType> types);
    bool check(TokenType type) const;
    Token consume(TokenType type);


};



#endif //PARSER_H
