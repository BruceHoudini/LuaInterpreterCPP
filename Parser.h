//
// Created by Bruce Houdini on 5/8/2016.
//

#ifndef LUAINTERPRETER_PARSER_H
#define LUAINTERPRETER_PARSER_H
#include <string>
#include "Expression.h"
#include "Id.h"
#include "LexicalAnalyzer.h"

using namespace std;
class Parser {
public:
    Parser(string filename);
    void parse();
    void getBlock();
    void getStatement();
    void resolveIf();
    void resolveWhile();
    void resolveRepeat();
    void printState();
    void Assign();
    Expression* getExpression();
    Expression* getBinaryExpression();
    Expression* getBooleanExpression();
    Id* getId();
    Expression* getConstant();
    void match();
    LexicalAnalyzer * lex;
};


#endif //LUAINTERPRETER_PARSER_H
