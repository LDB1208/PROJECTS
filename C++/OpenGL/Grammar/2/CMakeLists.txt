cmake_minimum_required(VERSION 3.28)
project(2)

set(CMAKE_CXX_STANDARD 17)
set(GLFW_DIR ../../Library/GLFW)
set(GLEW_DIR ../../Library/GLEW)

include_directories(${GLFW_DIR}/include ${GLEW_DIR}/include)
link_directories(${GLFW_DIR}/lib-mingw-w64 ${GLEW_DIR}/lib)

add_executable(2 src/main.cpp)

target_link_libraries(2 glew32 glfw3 opengl32)
