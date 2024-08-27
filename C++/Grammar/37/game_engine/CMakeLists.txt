cmake_minimum_required(VERSION 3.29)
project(game_engine)

set(CMAKE_CXX_STANDARD 20)

add_library(game_engine STATIC src/library.cpp
        include/library.h)
