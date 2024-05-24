cmake_minimum_required(VERSION 3.27)
project(game_engine)

set(CMAKE_CXX_STANDARD 17)

add_library(game_engine STATIC src/library.cpp)
