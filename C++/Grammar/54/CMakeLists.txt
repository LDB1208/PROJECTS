cmake_minimum_required(VERSION 3.29)
project(54)

set(CMAKE_CXX_STANDARD 20)

add_executable(54 src/main.cpp
        include/pch.h
        src/pch.cpp)

target_precompile_headers(54 PRIVATE include/pch.h)
