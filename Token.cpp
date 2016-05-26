//
// Created by Bruce Houdini on 5/8/2016.
//

#include "Token.h"
using namespace std;

Token::Token(string lexeme, TokenType tokType){
    this->lexeme = lexeme;
    this->tokType = tokType;
}
Token::Token(){
}


string Token::getLexeme(){
    return lexeme;
}
Token::TokenType Token::getTokType(){
    return tokType;
}
