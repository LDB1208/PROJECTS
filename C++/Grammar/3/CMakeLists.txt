cmake_minimum_required(VERSION 3.26)
project(3)

set(CMAKE_CXX_STANDARD 23)

add_executable(3 src/Main.cpp src/Functions.cpp
        include/CloseBrace.h
        include/Header.h)
