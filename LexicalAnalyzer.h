//
// Created by Bruce Houdini on 5/8/2016.
//

#ifndef LUAINTERPRETER_LEXICALANALYZER_H
#define LUAINTERPRETER_LEXICALANALYZER_H
#include <string>
#include <vector>
#include "Token.h"

using namespace std;

class LexicalAnalyzer{
    string file;
    string testline;
    vector<string> word;
    vector<Token> tokens;

    string getLexeme();
    void getTokenType(string lexeme, Token * p_tok);
    void makeToken(string s);


public:
    LexicalAnalyzer(string testfile);
    int analyze();
    Token * getNextToken();
    Token * getLookaheadToken();
    int saveState();
    void loadState(int pc);
    int programCounter;



};
#endif //LUAINTERPRETER_LEXICALANALYZER_H
