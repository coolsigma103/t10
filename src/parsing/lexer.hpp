#pragma once
#include <cstddef>
#include <cstdint>
#include <fstream>
#include <vector>

namespace t3
{
    enum class TokenType : uint8_t
    {
        TK_INT,
        TK_FLOAT,
        TK_STRING,
        TK_TRUE,
        TK_FALSE,
        TK_NIL,

        TK_FUNC,
        TK_VAR,
        TK_IMPORT,
        TK_MODULE,
        TK_RETURN,
        TK_IF,
        TK_ELSE,
        TK_WHILE,
        TK_FOR,
        TK_CLASS,
        TK_EXTERN,

        TK_ARITH_ADD,
        TK_ARITH_MIN,
        TK_ARITH_MUL,
        TK_ARITH_DIV,
        TK_ARITH_MOD,
        TK_ARITH_ADD_1,
        TK_ARITH_MIN_1,

        TK_LOGIC_EQUAL,
        TK_LOGIC_NOT_EQUAL,
        TK_LOGIC_GREATER,
        TK_LOGIC_LESS,
        TK_LOGIC_GREATER_EQUAL,
        TK_LOGIC_LESS_EQUAL,

        TK_LOGIC_AND,
        TK_LOGIC_OR,
        TK_LOGIC_NOT,

        TK_BIT_AND,
        TK_BIT_OR,
        TK_BIT_XOR,
        TK_BIT_NOT,
        TK_BIT_LSHIFT,
        TK_BIT_RSHIFT,

        TK_EQUAL,
        TK_EQUAL_ADD,
        TK_EQUAL_MIN,
        TK_EQUAL_MUL,
        TK_EQUAL_DIV,
        TK_EQUAL_MOD,
        TK_EQUAL_AND,
        TK_EQUAL_OR,
        TK_EQUAL_XOT,
        TK_EQUAL_LSHIFT,
        TK_EQUAL_RSHIFT,

        TK_DOT,
        TK_ARROW,
        TK_LEFT_PAREN,
        TK_RIGHT_PAREN,
        TK_LEFT_BRACE,
        TK_RIGHT_BRACE,
        TK_LEFT_BRACKET,
        TK_RIGHT_BRACKET,
        TK_COMMA,
        TK_SEMICOLON,

        TK_IDENTIFIER,
        TK_ERROR,
        TK_EOF
    };

    struct Token
    {
        TokenType type;
        std::string_view lexeme;
        uint32_t line; // Code line location tracker for precise debugging maps
    };

    std::vector<Token> tokenize(const char* src);
} // namespace t3