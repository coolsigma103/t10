#include "t3.hpp"

enum class TokenType
{
    NONE,

    IDENTIFIER, // identifiers: object, position
    NUMBER,     // numbers: 123, 3.14

    OPERATOR, // + - * / = .
    SYMBOL,   // # @

    LDELIMITER,
    RDELIMITER, // ( ) { } [ ]
    SEPARATOR,  // ; ,
    COLON,

    EOF_TOKEN // end of input
};

struct Token
{
    TokenType type;
    const char* start;
    int len;
    int line;
};
