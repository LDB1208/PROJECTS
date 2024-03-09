cmake_minimum_required(VERSION 3.27)
project(35)

set(CMAKE_CXX_STANDARD 17)
include_directories(glfw/include) #添加头文件路径
link_directories(glfw/lib-mingw-w64) #添加库路径

add_executable(35 src/main.cpp)
target_link_libraries(35 libglfw3.a) #链接库