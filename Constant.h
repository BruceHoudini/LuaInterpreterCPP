//
// Created by Bruce Houdini on 5/8/2016.
//

#ifndef LUAINTERPRETER_CONSTANT_H
#define LUAINTERPRETER_CONSTANT_H


#include "Expression.h"

class Constant: public Expression {
public:
    Constant(int value);
    virtual int evaluate();
private:
    int value;
};


#endif //LUAINTERPRETER_CONSTANT_H
