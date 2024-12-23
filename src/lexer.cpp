#include "../include/lexer.h"
#include <cctype>
#include <iostream>

Lexer::Lexer(const std::string& src) : src(src) {}

std::vector<Token> Lexer::tokenize(){
    while (!isAtEnd()){
        start = curr;
        scanToken();
    }

    tokens.push_back(Token(TokenType::END_OF_FILE, "", line, col));
    return tokens;
}

bool Lexer::isAtEnd() const {
    return curr >= src.size();
}

void Lexer::scanToken(){
    int tokenStartCol = col;
    char c = advance();
    switch (c){
        //implement all the cases later im too lazy right now
        case '(':
            addToken(TokenType::LEFT_PAREN, "(", tokenStartCol);
            break;
        case ')':
            addToken(TokenType::RIGHT_PAREN, ")", tokenStartCol);
            break;
        case '{':
            addToken(TokenType::LEFT_BRACE, "{", tokenStartCol);
            break;
        case '}':
            addToken(TokenType::RIGHT_BRACE, "}", tokenStartCol);
            break;
        case ',':
            addToken(TokenType::COMMA, ",", tokenStartCol);
            break;
        case '.':
            addToken(TokenType::DOT, ".", tokenStartCol);
            break;
        case '-':
            if(match('-')) addToken(TokenType::MINUS_MINUS, "--", tokenStartCol);
            else addToken(TokenType::MINUS, "-", tokenStartCol);
            break;
        case '+':
            if(match('+')) addToken(TokenType::PLUS_PLUS, "++", tokenStartCol);
            else addToken(TokenType::PLUS, "+", tokenStartCol);
            break;
        case ';':
            addToken(TokenType::SEMICOLON, ";", tokenStartCol);
            break;
        case '/':
            addToken(TokenType::SLASH, "/", tokenStartCol);
            break;
        case '*':
            addToken(TokenType::STAR, "*", tokenStartCol);
            break;
        case '!':
            if (match('=')) addToken(TokenType::BANG_EQUAL, "!=", tokenStartCol);
            else addToken(TokenType::BANG, "!", tokenStartCol);
            break;
        case '=':
            if (match('=')) addToken(TokenType::EQUAL_EQUAL, "==", tokenStartCol);
            else addToken(TokenType::EQUAL, "=", tokenStartCol);
            break;
        case '>':
            if (match('=')) addToken(TokenType::GREATER_EQUAL, ">=", tokenStartCol);
            else addToken(TokenType::GREATER, ">", tokenStartCol);
            break;
        case '<':
            if (match('=')) addToken(TokenType::LESS_EQUAL, "<=", tokenStartCol);
            else addToken(TokenType::LESS, "<", tokenStartCol);
            break;
        case '"':
            handleString(tokenStartCol);
            break;
        default:
            if(std::isspace(c)){
                if(c == '\n'){
                    line++;
                    col = 1;
                }
                //ignore whitespace otherwise
            } else if (std::isalpha(c) || c == '_'){
                handleIdentifier(tokenStartCol);
            } else if (std::isdigit(c)){
                handleNumber(tokenStartCol);
            } else {
                std::cerr << "Unexpected character " << c << " at line " << line << ", col " << col << std::endl;
            }
            break;
    }   
}

void Lexer::addToken(TokenType type, const std::string& lexeme, int startCol) {
    tokens.push_back(Token(type, lexeme, line, startCol));
}

void Lexer::handleIdentifier(int tokenStartCol){
    while(!isAtEnd() && (std::isalnum(peek()) || peek() == '_')){
        advance();
    }
    std::string lexeme = src.substr(start, curr - start);

    TokenType type = TokenType::IDENTIFIER;

    if      (lexeme == "if")       type = TokenType::IF;
    else if (lexeme == "else")     type = TokenType::ELSE;
    else if (lexeme == "for")      type = TokenType::FOR;
    else if (lexeme == "while")    type = TokenType::WHILE;
    else if (lexeme == "return")   type = TokenType::RETURN;
    else if (lexeme == "true")     type = TokenType::TRUE;
    else if (lexeme == "false")    type = TokenType::FALSE;
    else if (lexeme == "func")     type = TokenType::FUNC;
    else if (lexeme == "var")      type = TokenType::VAR;
    else if (lexeme == "class")    type = TokenType::CLASS;
    else if (lexeme == "print")    type = TokenType::PRINT;
    else if (lexeme == "input")    type = TokenType::INPUT;
    
    addToken(type, lexeme, tokenStartCol);
}

void Lexer::handleNumber(int tokenStartCol){
    while(!isAtEnd() && std::isdigit(peek())){
        advance();
    }
    if(peek() == '.' && std::isdigit(peek())){
        advance();
        while(!isAtEnd() && std::isdigit(peek())){
            advance();
        }
    }
    addToken(TokenType::NUMBER, src.substr(start, curr - start), tokenStartCol);
}


void Lexer::handleString(int tokenStartCol){
    while(!isAtEnd() && peek() != '"'){
        if(peek() == '\n'){
            line++;
            col = 1;
        }
        advance();
    }
    if(isAtEnd()){
        std::cerr << "Unterminated string at line " << line << ", col " << col << std::endl;
        return;
    }
    advance(); //consume closing "
    addToken(TokenType::STRING, src.substr(start + 1, (curr - 1) - (start + 1)), tokenStartCol);
}



char Lexer::advance(){
    char c = src[curr];
    curr++;
    col++;
    return c;
}

char Lexer::peek(){
    if(isAtEnd()) return '\0';
    return src[curr];
}

bool Lexer::match(char expected){
    if(isAtEnd() || src[curr] != expected) return false;
    curr++;
    col++;
    return true;
}