cmake_minimum_required(VERSION 3.27)
project(3)

set(CMAKE_CXX_STANDARD 17)

add_executable(3 src/main.cpp
        src/funcs.cpp
        include/header.h
        include/close_brace.h)
