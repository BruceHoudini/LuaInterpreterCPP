//
// Created by Bruce Houdini on 5/11/2016.
//

#include "Assignment.h"
#include "Memory.h"

Assignment::Assignment(Id* var, Expression* expr){
    this->var = var;
    this->expr = expr;
}

void Assignment::execute(){
    Memory::store(var->getChar(), expr->evaluate());
};
