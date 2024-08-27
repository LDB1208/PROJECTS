cmake_minimum_required(VERSION 3.29)
project(37)

set(CMAKE_CXX_STANDARD 20)

link_directories(lib)

add_executable(37 src/main.cpp)

target_link_libraries(37 game_engine)
