cmake_minimum_required(VERSION 3.27)
project(Formula)

set(CMAKE_CXX_STANDARD 17)

add_executable(Formula src/main.cpp
        src/funcs.cpp
        include/header.h)
