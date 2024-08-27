cmake_minimum_required(VERSION 3.29)
project(3)

set(CMAKE_CXX_STANDARD 20)

add_executable(3 src/main.cpp
        src/func.cpp
        include/close_brace.h
        include/header.h)
