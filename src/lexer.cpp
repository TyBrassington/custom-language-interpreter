#include "../include/lexer.h"
#include <cctype>
#include <iostream>

Lexer::Lexer(const std::string& src) : src(src) {}

std::vector<Token> Lexer::tokenize(){
    while (!isAtEnd()){
        start = curr;
        scanToken();
    }

    tokens.push_back(Token(TokenType::END_OF_FILE, "", line, column));
    return tokens;
}

bool Lexer::isAtEnd() const {
    return curr >= src.size();
}

void Lexer::scanToken(){
    char c = src[curr++];
    switch (c){
        //implement all the cases later im too lazy right now
        case '(':
            addToken(TokenType::LEFT_PAREN, "(");
            break;
        case ')':
            addToken(TokenType::RIGHT_PAREN, ")");
            break;
        case '{':
            addToken(TokenType::LEFT_BRACE, "{");
            break;
        case '}':
            addToken(TokenType::RIGHT_BRACE, "}");
            break;
        default:
            //add reserved words, identifiers, numbers, strings, etc later
    }   
}

void Lexer::addToken(TokenType t, const std::string& lexeme){
    tokens.push_back(Token(t, lexeme, line, column));
}