cmake_minimum_required(VERSION 3.29)
project(Music)

set(CMAKE_CXX_STANDARD 20)

add_executable(Music src/main.cpp)

target_link_libraries(Music winmm.lib)
