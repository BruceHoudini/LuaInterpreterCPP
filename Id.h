//
// Created by Bruce Houdini on 5/8/2016.
//

#ifndef LUAINTERPRETER_ID_H
#define LUAINTERPRETER_ID_H


#include "Expression.h"

class Id: public Expression {
public:
    Id(char ch);
    virtual int evaluate();
    char getChar();
private:
    char ch;


};


#endif //LUAINTERPRETER_ID_H
