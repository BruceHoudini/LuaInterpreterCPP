//
// Created by Bruce Houdini on 5/8/2016.
//

#include "BooleanExpression.h"

BooleanExpression::BooleanExpression (bool_op op, Expression* expr1, Expression* expr2)
{

    this->op = op;
    this->expr1 = expr1;
    this->expr2 = expr2;

}

int BooleanExpression::evaluate()
{
    int boole;
    if(op == bool_op::LE_OP) {
        if (expr1->evaluate() <= expr2->evaluate())
            boole = 1;
        else
            boole = 0;
    }
    else if(op == bool_op::LT_OP) {
        if (expr1->evaluate() < expr2->evaluate())
            boole = 1;
        else
            boole = 0;
    }
    else if(op == bool_op::GE_OP) {
        if (expr1->evaluate() >= expr2->evaluate())
            boole = 1;
        else
            boole = 0;
    }
    else if(op == bool_op::GT_OP) {
        if (expr1->evaluate() > expr2->evaluate())
            boole = 1;
        else
            boole = 0;
    }
    else if(op == bool_op::EQ_OP) {
        if (expr1->evaluate() == expr2->evaluate())
            boole = 1;
        else
            boole = 0;
    }
    else {
        if (expr1->evaluate() != expr2->evaluate())
            boole = 1;
        else
            boole = 0;
    }

    return boole;
}