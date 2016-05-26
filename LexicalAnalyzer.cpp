//
// Created by Bruce Houdini on 5/8/2016.
//
#include "LexicalAnalyzer.h"
#include <iostream>
#include <fstream>

using namespace std;



    LexicalAnalyzer::LexicalAnalyzer(string testfile){
        file = testfile;
        cout << "Loading file at location: " << file <<endl;
        programCounter = 0;
        analyze();
        for (int i = 0; i < word.size(); i++)
            makeToken(word[i]);
    }

    void LexicalAnalyzer::makeToken(string s){
        Token newTok = Token();
        Token * tok_p = &newTok;
        getTokenType(s, tok_p);
        newTok.lexeme = s;
        tokens.push_back(newTok);
    }

    //I need to record my struggles within comments so that they won't be forgotten.
    //Here on these lines, Weston Ford spent a non-trivial amount of time, time of which
    //he didn't have, in order to compare these strings using switch statements and
    //then write about his failures so that others will know the truth of what happened here.
    //"Switch only accepts integers as a parameter" they said.
    //"It's easy just develop a hashing algorithm" they said.
    void LexicalAnalyzer::getTokenType(string lexeme, Token * p_tok){
        Token::TokenType tokType;
        if (isalpha(lexeme[0])){
            if (lexeme.length() == 1)
                tokType = Token::ID_TOK;
            else if(lexeme.length() > 1){
                if(!lexeme.compare("print")) tokType = Token::PRINT_TOK;
                else if(!lexeme.compare("if")) tokType = Token::IF_TOK;
                else if(!lexeme.compare("then")) tokType = Token::THEN_TOK;
                else if(!lexeme.compare("else")) tokType = Token::ELSE_TOK;
                else if(!lexeme.compare("while")) tokType = Token::WHILE_TOK;
                else if(!lexeme.compare("do")) tokType = Token::DO_TOK;
                else if(!lexeme.compare("repeat")) tokType = Token::REPEAT_TOK;
                else if(!lexeme.compare("until")) tokType = Token::UNTIL_TOK;
                else if(!lexeme.compare("end")) tokType = Token::END_TOK;
                else if(!lexeme.compare("function")) tokType = Token::FUNCTION_TOK;
            }
        }
        else if (isdigit(lexeme[0])){
                tokType = Token::CONST_TOK;
        }
        else if (lexeme.length() == 1 && ispunct(lexeme[0])){
            if(!lexeme.compare("+")) tokType = Token::ADD_TOK;
            else if(!lexeme.compare("*")) tokType = Token::MUL_TOK;
            else if(!lexeme.compare("-")) tokType = Token::SUB_TOK;
            else if(!lexeme.compare("/")) tokType = Token::DIV_TOK;
            else if(!lexeme.compare("=")) tokType = Token::ASSIGN_TOK;
            else if(!lexeme.compare(">")) tokType = Token::GT_TOK;
            else if(!lexeme.compare("<")) tokType = Token::LT_TOK;
            else if(!lexeme.compare("(")) tokType = Token::OPENP_TOK;
            else if(!lexeme.compare(")")) tokType = Token::CLOSEP_TOK;
        }
        else if (lexeme.length() > 1 && ispunct(lexeme[0])){
            if(!lexeme.compare("==")) tokType = Token::EQ_TOK;
            else if(!lexeme.compare("~=")) tokType = Token::NE_TOK;
            else if(!lexeme.compare(">=")) tokType = Token::GE_TOK;
            else if(!lexeme.compare("<=")) tokType = Token::LE_TOK;
        }
        p_tok->tokType = tokType;
    }

    Token * LexicalAnalyzer::getNextToken(){
        Token * rval;
        if(programCounter < tokens.size()){
            rval = &tokens[programCounter];
            programCounter++;
            return rval;
        }
    }

    Token * LexicalAnalyzer::getLookaheadToken(){
        Token * rval;
        if(programCounter < tokens.size()){
            rval = &tokens[programCounter];
            return rval;
        }
    }


    int LexicalAnalyzer::analyze() {
        ifstream Test(file);
        if (!Test){
            cout << "There was an error opening the file.\n";
            return 0;
        }
        while (Test >> testline)
            word.push_back(testline);
        return 0;
    }

    int LexicalAnalyzer::saveState(){
        return programCounter;
    }
    void LexicalAnalyzer::loadState(int pc){
        programCounter = pc;
    }
