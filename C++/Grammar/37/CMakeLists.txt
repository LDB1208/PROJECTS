cmake_minimum_required(VERSION 3.27)
project(37)

set(CMAKE_CXX_STANDARD 17)
include_directories(include)
link_directories(lib)

add_executable(37 src/main.cpp)

target_link_libraries(37 libgame_engine.a)
