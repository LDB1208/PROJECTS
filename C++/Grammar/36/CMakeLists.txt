cmake_minimum_required(VERSION 3.27)
project(36)

set(CMAKE_CXX_STANDARD 17)
include_directories(glfw/include)
link_directories(glfw/lib-mingw-w64)

add_executable(36 src/main.cpp)
target_link_libraries(36 libglfw3dll.a)