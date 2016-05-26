//
// Created by Bruce Houdini on 5/8/2016.
//

#include "Constant.h"

Constant::Constant(int value){
    this->value = value;
}
int Constant::evaluate(){
    return value;
}