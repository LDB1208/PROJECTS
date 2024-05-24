cmake_minimum_required(VERSION 3.28)
project(1)

set(CMAKE_CXX_STANDARD 17)
include_directories(../../Library/GLFW/include)
link_directories(../../Library/GLFW/lib-mingw-w64)

add_executable(1 src/main.cpp)

target_link_libraries(1 libglfw3.a opengl32)
