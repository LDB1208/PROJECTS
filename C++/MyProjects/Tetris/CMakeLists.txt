cmake_minimum_required(VERSION 3.28)
project(Tetris)

set(CMAKE_CXX_STANDARD 17)

include_directories(libs/glfw/include)
link_directories(libs/glfw/lib-mingw-w64)

add_executable(Tetris WIN32  src/main.cpp)

target_link_libraries(Tetris glfw3 opengl32)
