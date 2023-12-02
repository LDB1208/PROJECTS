cmake_minimum_required(VERSION 3.26)
project(Music)

set(CMAKE_CXX_STANDARD 23)

link_directories(winmm)

add_executable(Music src/Main.cpp)
target_link_libraries(Music winmm)
