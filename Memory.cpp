//
// Created by Bruce Houdini on 5/8/2016.
//

#include "Memory.h"

int Memory::mem[57] = {0};
int Memory::fetch(char ch) {
    return mem[getIndex(ch)];
}

void Memory::store(char ch, int value) {
    mem[getIndex(ch)] = value;
}

int Memory::getIndex(char ch){
    return ch - 'A';
}
