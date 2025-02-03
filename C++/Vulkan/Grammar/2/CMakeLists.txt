cmake_minimum_required(VERSION 3.25)
project(2)

set(CMAKE_CXX_STANDARD 17)
set(VULKAN_PATH F:/Programming/SDK/Vulkan)

include_directories(${VULKAN_PATH}/include ${VULKAN_PATH}/glfw/include)
link_directories(${VULKAN_PATH}/Lib ${VULKAN_PATH}/glfw/lib-mingw-w64)

add_executable(2 WIN32 src/main.cpp)

target_link_libraries(2 vulkan-1.lib glfw3)
