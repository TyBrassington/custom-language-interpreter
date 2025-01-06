cmake_minimum_required(VERSION 3.27)
project(Custom_Language_Interpreter)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(Custom_Language_Interpreter
        src/lexer.cpp
        src/main.cpp
        src/parser.cpp
        include/parser.h
)
