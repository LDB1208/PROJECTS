cmake_minimum_required(VERSION 3.29)
project(Sandbox)

set(CMAKE_CXX_STANDARD 20)

include_directories("../Hazel/include")

add_executable(Sandbox src/main.cpp)

target_link_libraries(Sandbox Hazel)
