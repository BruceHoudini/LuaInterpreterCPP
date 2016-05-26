//
// Created by Bruce Houdini on 5/8/2016.
//

#ifndef LUAINTERPRETER_TOKEN_H
#define LUAINTERPRETER_TOKEN_H
#include <string>
using namespace std;

class Token {
public:
    enum TokenType {
        ID_TOK,
        ADD_TOK,
        MUL_TOK,
        SUB_TOK,
        DIV_TOK,
        ASSIGN_TOK,
        CONST_TOK,
        EOS_TOK,
        LE_TOK,
        LT_TOK,
        GE_TOK,
        GT_TOK,
        EQ_TOK,
        NE_TOK,
        PRINT_TOK,
        IF_TOK,
        THEN_TOK,
        ELSE_TOK,
        WHILE_TOK,
        DO_TOK,
        REPEAT_TOK,
        UNTIL_TOK,
        END_TOK,
        OPENP_TOK,
        CLOSEP_TOK,
        FUNCTION_TOK
    };

    string getLexeme();
    TokenType getTokType();
    string lexeme;
    TokenType tokType;
    Token(string lexeme, TokenType tokType);
    Token();
};

#endif //LUAINTERPRETER_TOKEN_H
