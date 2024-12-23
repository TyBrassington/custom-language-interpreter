cmake_minimum_required(VERSION 3.27)
project(Custom_Language_Interpreter)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Custom_Language_Interpreter
        lexer.cpp
        lexer.h
        main.cpp
        token.h
        token_type.h)
