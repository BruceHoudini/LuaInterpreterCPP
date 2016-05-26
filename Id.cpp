//
// Created by Bruce Houdini on 5/8/2016.
//

#include "Id.h"
#include "Memory.h"

Id::Id(char ch){
    this->ch = ch;
}
int Id::evaluate(){
    return Memory::fetch(ch);
}
char Id::getChar(){
    return ch;
}