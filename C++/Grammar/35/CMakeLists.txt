cmake_minimum_required(VERSION 3.29)
project(35)

set(CMAKE_CXX_STANDARD 20)

include_directories(glfw/include)
link_directories(glfw/lib-mingw-w64)

add_executable(35 src/main.cpp)

target_link_libraries(35 libglfw3.a)
