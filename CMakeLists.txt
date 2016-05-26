cmake_minimum_required(VERSION 3.3)
project(LuaInterpreter)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp ArithmeticOperator.cpp ArithmeticOperator.h BinaryExpression.cpp BinaryExpression.h BooleanExpression.cpp BooleanExpression.h Constant.cpp Constant.h LexicalAnalyzer.cpp LexicalAnalyzer.h Parser.cpp Parser.h Memory.cpp Memory.h Token.cpp Token.h Id.cpp Id.h Assignment.cpp Assignment.h Expression.cpp Expression.h)
add_executable(LuaInterpreter ${SOURCE_FILES})