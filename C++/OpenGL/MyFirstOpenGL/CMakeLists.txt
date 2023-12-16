cmake_minimum_required(VERSION 3.27)
project(MyFirstOpenGL)

set(CMAKE_CXX_STANDARD 23)
set(GLFW_DIR F:/Programming/PROJECTS/C++/OpenGL)

include_directories(${GLFW_DIR}/Dependencies/include)
link_directories(${GLFW_DIR}/Dependencies/lib-mingw-w64)

add_executable(MyFirstOpenGL WIN32 src/Main.cpp)
target_link_libraries(MyFirstOpenGL libglfw3.a opengl32)
