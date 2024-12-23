#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include "token_type.h"

struct Token {
    TokenType type;
    std::string lexeme;
    int line;
    int column;

    Token(TokenType t, const std::string& lex, int ln, int col)
        : type(t), lexeme(lex), line(ln), column(col) {}

    std::string toString() const {
        return "Token("
            + tokenTypeToString(type)
            + ", \"" + lexeme
            + "\", line=" + std::to_string(line)
            + ", col=" + std::to_string(column)
            + ")";
    }
};

#endif