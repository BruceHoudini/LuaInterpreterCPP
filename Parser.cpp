//
// Created by Bruce Houdini on 5/8/2016.
//

#include <c++/iostream>
#include "Parser.h"
#include "Token.h"
#include "BinaryExpression.h"
#include "BooleanExpression.h"
#include "Assignment.h"
#include "Constant.h"

Parser::Parser(string fileName){
                lex = new LexicalAnalyzer(fileName);
}

void Parser::parse(){
    cout<<"Process Initiated."<<endl;
    Token * tok = lex->getNextToken();
    if (tok->getTokType() == Token::FUNCTION_TOK) {
        if (((tok = lex->getNextToken())->getTokType()) == Token::ID_TOK) {
            if (((tok = lex->getNextToken())->getTokType()) == Token::OPENP_TOK) {
                if (((tok = lex->getNextToken())->getTokType()) == Token::CLOSEP_TOK) {
                    getBlock();
                    if (((tok = lex->getNextToken())->getTokType()) != Token::END_TOK) {
                        cout<<"Expected END Token.";
                    }
                }
            }
        }
    }
    cout<<"Process complete."<<endl;
}

void Parser::getBlock(){
    Token * tok = lex->getLookaheadToken();
    if((tok->getTokType() != Token::EOS_TOK) && (tok->getTokType() != Token::END_TOK) && (tok->getTokType() != Token::UNTIL_TOK)){
        getStatement();
        getBlock();
    }
}

void Parser::getStatement() {
    Token * tok = lex->getLookaheadToken();
    if (tok->getTokType() == Token::IF_TOK)
        resolveIf();
    else if (tok->getTokType() == Token::WHILE_TOK)
        resolveWhile();
    else if (tok->getTokType() == Token::REPEAT_TOK)
        resolveRepeat();
    else if (tok->getTokType() == Token::PRINT_TOK)
        printState();
    else if (tok->getTokType() == Token::ID_TOK)
        Assign();
    else if (tok->getTokType() == Token::ELSE_TOK)
        return;
    else if (tok->getTokType() == Token::UNTIL_TOK)
        return;
}

void Parser::resolveIf(){
    Token * tok = lex->getLookaheadToken();
    if (getBooleanExpression()->evaluate() == 1){
        tok = lex->getNextToken();
        if (tok->getTokType() == Token::THEN_TOK){
            getBlock();
            tok = lex->getNextToken();
            if(tok->getTokType() == Token::ELSE_TOK){
                while (tok->getTokType() != Token::END_TOK)
                    tok = lex->getNextToken();
                if (tok->getTokType() == Token::END_TOK)
                    return;
            }
        }
    }
    else{
        while (tok->getTokType() != Token::ELSE_TOK)
            tok = lex->getNextToken();
        getBlock();
        tok = lex->getNextToken();
        if(tok->getTokType() == Token::END_TOK)
            return;
    }
}

void Parser::resolveWhile(){
    Expression * whileCondition = getBooleanExpression();
    int save1;
    int save2;
    Token * tok = lex->getNextToken();
    if(tok->getTokType() == Token::DO_TOK){
        while (whileCondition->evaluate() == 1){
            save1 = lex->saveState();
            getBlock();
            save2 = lex->saveState();
            lex->loadState(save1);
        }
        lex->loadState(save2);
            if(((tok = lex->getNextToken())->getTokType()) == Token::END_TOK)
                return;
    }
}

void Parser::resolveRepeat(){
    int save1 = lex->saveState();
    lex->getNextToken();
    getBlock();
    Expression * repeatCondition = getBooleanExpression();
    if (repeatCondition->evaluate() != 1){
        lex->loadState(save1);
        resolveRepeat();
    }
}
void Parser::printState() {
    Token * tok = lex->getNextToken();
    tok = lex->getNextToken();
    if(tok->getTokType() == Token::OPENP_TOK){
        cout<< getExpression()->evaluate() << endl;
        tok = lex->getNextToken();
    }
}

void Parser::Assign(){
    Id * var = getId();
    Token * tok = lex->getNextToken();
    Expression * expr = getExpression();
    Assignment * a_pointer = new Assignment(var, expr);
    a_pointer->execute();
}


Expression * Parser::getExpression(){
    Expression * expr;
    Token * tok = lex->getLookaheadToken();
    if (tok->getTokType() == Token::ADD_TOK || tok->getTokType() == Token::MUL_TOK || tok->getTokType() == Token::SUB_TOK || tok->getTokType() == Token::DIV_TOK)
        expr = getBinaryExpression();
    else if (tok->getTokType() == Token::ID_TOK)
        expr = getId();
    else
        expr = getConstant();
    return expr;
}


Expression* Parser::getBinaryExpression(){
    BinaryExpression::ar_op op;
    Token * tok = lex->getNextToken();
    if (tok->getTokType() == Token::ADD_TOK)
        op = BinaryExpression::ADD_OP;
    else if (tok->getTokType() == Token::MUL_TOK)
        op = BinaryExpression::MUL_OP;
    else if (tok->getTokType() == Token::SUB_TOK)
        op = BinaryExpression::SUB_OP;
    else if (tok->getTokType() == Token::DIV_TOK)
        op = BinaryExpression::DIV_OP;

    Expression * expr1 = getExpression();
    Expression * expr2 = getExpression();
    return new BinaryExpression (op, expr1, expr2);
}

Expression* Parser::getBooleanExpression() {
    BooleanExpression::bool_op op;
    lex->getNextToken();
    Token * tok = lex->getNextToken();
    if (tok->getTokType() == Token::LE_TOK)
        op = BooleanExpression::LE_OP;
    else if (tok->getTokType() == Token::LT_TOK)
        op = BooleanExpression::LT_OP;
    else if (tok->getTokType() == Token::GE_TOK)
        op = BooleanExpression::GE_OP;
    else if (tok->getTokType() == Token::GT_TOK)
        op = BooleanExpression::GT_OP;
    else if (tok->getTokType() == Token::EQ_TOK)
        op = BooleanExpression::EQ_OP;
    else if (tok->getTokType() == Token::NE_TOK)
        op = BooleanExpression::NE_OP;

    Expression * expr1 = getExpression();
    Expression * expr2 = getExpression();
    return new BooleanExpression(op, expr1, expr2);
}

Id* Parser::getId(){
    Token * tok = lex->getNextToken();
    return new Id (tok->getLexeme()[0]);
}

Expression* Parser::getConstant(){
    Token * tok = lex->getNextToken();
    int value = stoi(tok->getLexeme());
    return new Constant (value);
}
