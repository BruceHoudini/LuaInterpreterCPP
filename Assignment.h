//
// Created by Bruce Houdini on 5/11/2016.
//

#ifndef LUAINTERPRETER_ASSIGNMENT_H
#define LUAINTERPRETER_ASSIGNMENT_H


#include "Expression.h"
#include "Id.h"

class Assignment {
public:
    Assignment(Id* var, Expression* expr);
    void execute();
private:
    Expression* expr;
    Id* var;
};


#endif //LUAINTERPRETER_ASSIGNMENT_H
