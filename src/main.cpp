#include <iostream>
#include <vector>
#include <cassert>
#include "../include/lexer.h"

void testLexer() {
    std::string source = "if (a == 10) print(a);";
    Lexer lexer(source);

    std::vector<Token> tokens = lexer.tokenize();

    std::cout << "Generated Tokens:\n";
    for (const auto &token : tokens) {
        std::cout
                << "[Type: "    << tokenTypeToString(token.type)
                << ", Lexeme: '" << token.lexeme
                << "', Line: "   << token.line
                << ", Col: "     << token.column << "]\n";
    }
    std::cout << std::endl;

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
            Token(TokenType::END_OF_FILE, "", 1, 23),
    };

    assert(tokens.size() == expectedTokens.size());

    for (size_t i = 0; i < tokens.size(); ++i) {
        assert(tokens[i].type == expectedTokens[i].type);
        assert(tokens[i].lexeme == expectedTokens[i].lexeme);
        assert(tokens[i].line == expectedTokens[i].line);
        assert(tokens[i].column == expectedTokens[i].column);
    }

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    testLexer();
    return 0;
}
