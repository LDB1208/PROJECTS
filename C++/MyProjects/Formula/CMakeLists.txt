cmake_minimum_required(VERSION 3.29)
project(Formula)

set(CMAKE_CXX_STANDARD 20)

add_executable(Formula src/main.cpp
        src/functions.cpp
        include/header.h)
