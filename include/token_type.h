#ifndef TOKEN_TYPE_H
#define TOKEN_TYPE_H

#include <string>

enum class TokenType {
    // single char tokens
    LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
    COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,

    // 1-2 char tokens
    BANG, BANG_EQUAL,
    EQUAL, EQUAL_EQUAL,
    GREATER, GREATER_EQUAL,
    LESS, LESS_EQUAL,

    // literals
    IDENTIFIER, STRING, NUMBER, BOOL,

    IF, ELSE, FOR, WHILE, RETURN, TRUE, FALSE, FUNC, VAR, CLASS, PRINT, INPUT,

    COMMENT_LINE, COMMENT_BLOCK,

    END_OF_FILE
};

inline std::string tokenTypeToString(TokenType t) {
    switch (t) {
        case TokenType::LEFT_PAREN: return "LEFT_PAREN";
        case TokenType::RIGHT_PAREN: return "RIGHT_PAREN";
        case TokenType::LEFT_BRACE: return "LEFT_BRACE";
        case TokenType::RIGHT_BRACE: return "RIGHT_BRACE";
        case TokenType::COMMA: return "COMMA";
        case TokenType::DOT: return "DOT";
        case TokenType::MINUS: return "MINUS";
        case TokenType::PLUS: return "PLUS";
        case TokenType::SEMICOLON: return "SEMICOLON";
        case TokenType::SLASH: return "SLASH";
        case TokenType::STAR: return "STAR";

        case TokenType::BANG: return "BANG";
        case TokenType::BANG_EQUAL: return "BANG_EQUAL";
        case TokenType::EQUAL: return "EQUAL";
        case TokenType::EQUAL_EQUAL: return "EQUAL_EQUAL";
        case TokenType::GREATER: return "GREATER";
        case TokenType::GREATER_EQUAL: return "GREATER_EQUAL";
        case TokenType::LESS: return "LESS";
        case TokenType::LESS_EQUAL: return "LESS_EQUAL";

        case TokenType::IDENTIFIER: return "IDENTIFIER";
        case TokenType::STRING: return "STRING";
        case TokenType::NUMBER: return "NUMBER";
        case TokenType::BOOL: return "BOOL";

        case TokenType::IF: return "IF";
        case TokenType::ELSE: return "ELSE";
        case TokenType::FOR: return "FOR";
        case TokenType::WHILE: return "WHILE";
        case TokenType::RETURN: return "RETURN";
        case TokenType::TRUE: return "TRUE";
        case TokenType::FALSE: return "FALSE";
        case TokenType::FUNC: return "FUNC";
        case TokenType::VAR: return "VAR";
        case TokenType::CLASS: return "CLASS";
        case TokenType::PRINT: return "PRINT";
        case TokenType::INPUT: return "INPUT";

        case TokenType::COMMENT_LINE: return "COMMENT_LINE";
        case TokenType::COMMENT_BLOCK: return "COMMENT_BLOCK";

        case TokenType::END_OF_FILE: return "END_OF_FILE";

        default: return "UNKNOWN";
    }
}

#endif