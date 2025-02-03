cmake_minimum_required(VERSION 3.25)
project(demo)

set(CMAKE_CXX_STANDARD 17)
set(VULKAN_PATH F:/Programming/SDK/Vulkan)

include_directories(../lib ${VULKAN_PATH}/include ${VULKAN_PATH}/glfw/include)
link_directories(${VULKAN_PATH}/Lib ${VULKAN_PATH}/glfw/lib-mingw-w64)

aux_source_directory(../lib IMGUI)
add_executable(demo ${IMGUI} src/main.cpp)

target_link_libraries(demo glfw3 vulkan-1.lib)
