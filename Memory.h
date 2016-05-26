//
// Created by Bruce Houdini on 5/8/2016.
//

#ifndef LUAINTERPRETER_MEMORY_H
#define LUAINTERPRETER_MEMORY_H


class Memory {
public:
   static int fetch(char ch);
    static void store(char ch, int value);
    static int getIndex(char ch);
    static int mem [57];
};


#endif //LUAINTERPRETER_MEMORY_H
