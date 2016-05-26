//
// Created by Bruce Houdini on 5/8/2016.
//

#include "BinaryExpression.h"

BinaryExpression::BinaryExpression (ar_op op, Expression* expr1, Expression* expr2){
    this->expr1 = expr1;
    this->expr2 = expr2;
    this->op = op;
}

int BinaryExpression::evaluate(){
    int value;
    if(op == ar_op::ADD_OP)
        value = expr1->evaluate() + expr2->evaluate();
    else if (op == ar_op::MUL_OP)
        value = expr1->evaluate() * expr2->evaluate();
    else if (op == ar_op::SUB_OP)
        value = expr1->evaluate() - expr2->evaluate();
    else
        value = expr1->evaluate()/expr2->evaluate();
    return value;
}