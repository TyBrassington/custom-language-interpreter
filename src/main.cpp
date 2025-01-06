#include <fstream>
#include <iterator>
#include <iostream>
#include <vector>
#include "../include/lexer.h"

void writeTokensToFile(const std::vector<Token>& tokens) {
    std::ofstream file;
    file.open("../test.txt");
    for (const auto & token : tokens) {
        file << token.toString() << std::endl;
    }
    file.close();
}

bool testLexer() {
    std::string source = "if (a == 10) print(a);";
    Lexer lexer(source);

    std::vector<Token> tokens = lexer.tokenize();

    std::vector<Token> expectedTokens = {
            Token(TokenType::IF, "if", 1, 1),
            Token(TokenType::LEFT_PAREN, "(", 1, 4),
            Token(TokenType::IDENTIFIER, "a", 1, 5),
            Token(TokenType::EQUAL_EQUAL, "==", 1, 7),
            Token(TokenType::NUMBER, "10", 1, 10),
            Token(TokenType::RIGHT_PAREN, ")", 1, 12),
            Token(TokenType::PRINT, "print", 1, 14),
            Token(TokenType::LEFT_PAREN, "(", 1, 19),
            Token(TokenType::IDENTIFIER, "a", 1, 20),
            Token(TokenType::RIGHT_PAREN, ")", 1, 21),
            Token(TokenType::SEMICOLON, ";", 1, 22),
            Token(TokenType::END_OF_FILE, "", 1, 23)
    };

    if (tokens.size() != expectedTokens.size()) {
        std::cerr << "Token count mismatch: expected " << expectedTokens.size()
                  << ", got " << tokens.size() << std::endl;
        return false;
    }

    for (size_t i = 0; i < tokens.size(); i++) {
        if (tokens[i].type != expectedTokens[i].type ||
            tokens[i].lexeme != expectedTokens[i].lexeme ||
            tokens[i].line != expectedTokens[i].line ||
            tokens[i].column != expectedTokens[i].column) {
            std::cerr << "Mismatch at token index " << i << ":\n";
            std::cerr << "Generated token: [Type: " << tokenTypeToString(tokens[i].type)
                      << ", Lexeme: '" << tokens[i].lexeme
                      << "', Line: " << tokens[i].line
                      << ", Column: " << tokens[i].column << "]\n";
            std::cerr << "Expected token: [Type: " << tokenTypeToString(expectedTokens[i].type)
                      << ", Lexeme: '" << expectedTokens[i].lexeme
                      << "', Line: " << expectedTokens[i].line
                      << ", Column: " << expectedTokens[i].column << "]\n";
            return false;
        }
    }
    writeTokensToFile(tokens);
    return true;
}

bool testLexerWithOperators() {
    std::string source = "a + b - c * d / e;";
    Lexer lexer(source);

    std::vector<Token> tokens = lexer.tokenize();

    std::vector<Token> expectedTokens = {
            Token(TokenType::IDENTIFIER, "a", 1, 1),
            Token(TokenType::PLUS, "+", 1, 3),
            Token(TokenType::IDENTIFIER, "b", 1, 5),
            Token(TokenType::MINUS, "-", 1, 7),
            Token(TokenType::IDENTIFIER, "c", 1, 9),
            Token(TokenType::STAR, "*", 1, 11),
            Token(TokenType::IDENTIFIER, "d", 1, 13),
            Token(TokenType::SLASH, "/", 1, 15),
            Token(TokenType::IDENTIFIER, "e", 1, 17),
            Token(TokenType::SEMICOLON, ";", 1, 18),
            Token(TokenType::END_OF_FILE, "", 1, 19)
    };

    if (tokens.size() != expectedTokens.size()) {
        std::cerr << "Token count mismatch: expected " << expectedTokens.size()
                  << ", got " << tokens.size() << std::endl;
        return false;
    }

    for (size_t i = 0; i < tokens.size(); ++i) {
        if (tokens[i].type != expectedTokens[i].type ||
            tokens[i].lexeme != expectedTokens[i].lexeme ||
            tokens[i].line != expectedTokens[i].line ||
            tokens[i].column != expectedTokens[i].column) {
            std::cerr << "Mismatch at token index " << i << ":\n";
            std::cerr << "Generated token: [Type: " << tokenTypeToString(tokens[i].type)
                      << ", Lexeme: '" << tokens[i].lexeme
                      << "', Line: " << tokens[i].line
                      << ", Column: " << tokens[i].column << "]\n";
            std::cerr << "Expected token: [Type: " << tokenTypeToString(expectedTokens[i].type)
                      << ", Lexeme: '" << expectedTokens[i].lexeme
                      << "', Line: " << expectedTokens[i].line
                      << ", Column: " << expectedTokens[i].column << "]\n";
            return false;
        }
    }

    return true;
}

bool testLexerWithKeywords() {
    std::string source = "while (x < 10) { x = x + 1; }";
    Lexer lexer(source);

    std::vector<Token> tokens = lexer.tokenize();

    std::vector<Token> expectedTokens = {
            Token(TokenType::WHILE, "while", 1, 1),
            Token(TokenType::LEFT_PAREN, "(", 1, 7),
            Token(TokenType::IDENTIFIER, "x", 1, 8),
            Token(TokenType::LESS, "<", 1, 10),
            Token(TokenType::NUMBER, "10", 1, 12),
            Token(TokenType::RIGHT_PAREN, ")", 1, 14),
            Token(TokenType::LEFT_BRACE, "{", 1, 16),
            Token(TokenType::IDENTIFIER, "x", 1, 18),
            Token(TokenType::EQUAL, "=", 1, 20),
            Token(TokenType::IDENTIFIER, "x", 1, 22),
            Token(TokenType::PLUS, "+", 1, 24),
            Token(TokenType::NUMBER, "1", 1, 26),
            Token(TokenType::SEMICOLON, ";", 1, 27),
            Token(TokenType::RIGHT_BRACE, "}", 1, 29),
            Token(TokenType::END_OF_FILE, "", 1, 30)
    };

    if (tokens.size() != expectedTokens.size()) {
        std::cerr << "Token count mismatch: expected " << expectedTokens.size()
                  << ", got " << tokens.size() << std::endl;
        return false;
    }

    for (size_t i = 0; i < tokens.size(); ++i) {
        if (tokens[i].type != expectedTokens[i].type ||
            tokens[i].lexeme != expectedTokens[i].lexeme ||
            tokens[i].line != expectedTokens[i].line ||
            tokens[i].column != expectedTokens[i].column) {
            std::cerr << "Mismatch at token index " << i << ":\n";
            std::cerr << "Generated token: [Type: " << tokenTypeToString(tokens[i].type)
                      << ", Lexeme: '" << tokens[i].lexeme
                      << "', Line: " << tokens[i].line
                      << ", Column: " << tokens[i].column << "]\n";
            std::cerr << "Expected token: [Type: " << tokenTypeToString(expectedTokens[i].type)
                      << ", Lexeme: '" << expectedTokens[i].lexeme
                      << "', Line: " << expectedTokens[i].line
                      << ", Column: " << expectedTokens[i].column << "]\n";
            return false;
        }
    }

    return true;
}

bool testLexerWithStrings() {
    std::string source = "print(\"Hello, World!\");";
    Lexer lexer(source);

    std::vector<Token> tokens = lexer.tokenize();

    std::vector<Token> expectedTokens = {
            Token(TokenType::PRINT, "print", 1, 1),
            Token(TokenType::LEFT_PAREN, "(", 1, 6),
            Token(TokenType::STRING, "Hello, World!", 1, 7),
            Token(TokenType::RIGHT_PAREN, ")", 1, 22),
            Token(TokenType::SEMICOLON, ";", 1, 23),
            Token(TokenType::END_OF_FILE, "", 1, 24)
    };

    if (tokens.size() != expectedTokens.size()) {
        std::cerr << "Token count mismatch: expected " << expectedTokens.size()
                  << ", got " << tokens.size() << std::endl;
        return false;
    }

    for (size_t i = 0; i < tokens.size(); ++i) {
        if (tokens[i].type != expectedTokens[i].type ||
            tokens[i].lexeme != expectedTokens[i].lexeme ||
            tokens[i].line != expectedTokens[i].line ||
            tokens[i].column != expectedTokens[i].column) {
            std::cerr << "Mismatch at token index " << i << ":\n";
            std::cerr << "Generated token: [Type: " << tokenTypeToString(tokens[i].type)
                      << ", Lexeme: '" << tokens[i].lexeme
                      << "', Line: " << tokens[i].line
                      << ", Column: " << tokens[i].column << "]\n";
            std::cerr << "Expected token: [Type: " << tokenTypeToString(expectedTokens[i].type)
                      << ", Lexeme: '" << expectedTokens[i].lexeme
                      << "', Line: " << expectedTokens[i].line
                      << ", Column: " << expectedTokens[i].column << "]\n";
            return false;
        }
    }

    return true;
}

int main() {
    bool lexerTestPassed = testLexer();
    bool operatorsTestPassed = testLexerWithOperators();
    bool keywordsTestPassed = testLexerWithKeywords();
    bool stringsTestPassed = testLexerWithStrings();
    std::cout << "Lexer test: " << (lexerTestPassed ? "PASSED" : "FAILED") << std::endl;
    std::cout << "Lexer test with operators: " << (operatorsTestPassed ? "PASSED" : "FAILED") << std::endl;
    std::cout << "Lexer test with keywords: " << (keywordsTestPassed ? "PASSED" : "FAILED") << std::endl;
    std::cout << "Lexer test with strings: " << (stringsTestPassed ? "PASSED" : "FAILED") << std::endl;

    if (lexerTestPassed && operatorsTestPassed && keywordsTestPassed && stringsTestPassed) {
        std::cout << "All tests passed!" << std::endl;
    } else {
        std::cout << "Some tests failed:" << std::endl;
        if (!lexerTestPassed) {
            std::cout << " - testLexer" << std::endl;
        }
        if (!operatorsTestPassed) {
            std::cout << " - testLexerWithOperators" << std::endl;
        }
        if (!keywordsTestPassed) {
            std::cout << " - testLexerWithKeywords" << std::endl;
        }
        if (!stringsTestPassed) {
            std::cout << " - testLexerWithStrings" << std::endl;
        }
    }

    return 0;
}