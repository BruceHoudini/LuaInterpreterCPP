//
// Created by Bruce Houdini on 5/8/2016.
//

#ifndef LUAINTERPRETER_BOOLEANEXPRESSION_H
#define LUAINTERPRETER_BOOLEANEXPRESSION_H


#include "Expression.h"

class BooleanExpression : public Expression {
public:
    enum bool_op {
        LE_OP, LT_OP, GE_OP, GT_OP, EQ_OP, NE_OP
    };

    BooleanExpression(bool_op, Expression* expr1, Expression* expr2);

    virtual int evaluate();

private:
    Expression * expr1;
    Expression * expr2;
    bool_op op;
};


#endif //LUAINTERPRETER_BOOLEANEXPRESSION_H
