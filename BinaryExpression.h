//
// Created by Bruce Houdini on 5/8/2016.
//

#ifndef LUAINTERPRETER_BINARYEXPRESSION_H
#define LUAINTERPRETER_BINARYEXPRESSION_H


#include "Expression.h"
#include "ArithmeticOperator.h"

class BinaryExpression: public Expression {
public:
    enum ar_op{
        ADD_OP,
        MUL_OP,
        SUB_OP,
        DIV_OP
    };
    BinaryExpression(ar_op op, Expression* expr1, Expression* expr2);
    virtual int evaluate();
private:
    Expression* expr1;
    Expression* expr2;
    ar_op op;

};


#endif //LUAINTERPRETER_BINARYEXPRESSION_H
