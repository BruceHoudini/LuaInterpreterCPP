//Created by Weston Ford


#include "LexicalAnalyzer.h"
#include "Parser.h"
#include <iostream>
#include <c++/sstream>

using namespace std;

int main() {

    streambuf* oldCoutStreamBuf = cout.rdbuf();
    ostringstream strCout;
    cout.rdbuf( strCout.rdbuf() );
    cout << __FILE__;
    cout.rdbuf(oldCoutStreamBuf);
    string path = strCout.str();
    int len = path.length();
    string absPath = path.substr(0, len-8);
    string fileName = absPath + "testfile.txt";
    string test2 = absPath + "test2.txt";
    string test3 = absPath + "test3.txt";
    string test4 = absPath + "test4.txt";

    Parser* prime = new Parser(fileName);
    prime->parse();
    prime = new Parser(test2);
    prime->parse();
    prime = new Parser(test3);
    prime->parse();
    prime = new Parser(test4);
    prime->parse();

}