cmake_minimum_required(VERSION 3.28)
project(Demo)

set(CMAKE_CXX_STANDARD 17)
set(IMGUI_DIR ../Library)

include_directories(${IMGUI_DIR} ${IMGUI_DIR}/libs/glfw/include)
link_directories(${IMGUI_DIR}/libs/glfw/lib-mingw-w64)
aux_source_directory(${IMGUI_DIR} SRC)

add_executable(Demo WIN32 ${SRC} src/main.cpp)

target_link_libraries(Demo glfw3 opengl32)