cmake_minimum_required(VERSION 3.29)
project(1)

set(CMAKE_CXX_STANDARD 20)
set(GLFW_DIR ../../Library/glfw)
set(GLAD_DIR ../../Library/glad)

include_directories(${GLFW_DIR}/include)
include_directories(${GLAD_DIR}/include)
link_directories(${GLFW_DIR}/lib-mingw-w64)

add_executable(1 main.cpp ${GLAD_DIR}/src/glad.c)

target_link_libraries(1 glfw3)
