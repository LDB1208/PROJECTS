cmake_minimum_required(VERSION 3.28)
project(Example)

set(CMAKE_CXX_STANDARD 17)
set(MYSQL_DIR ../Library)

include_directories(${MYSQL_DIR}/include)
link_directories(${MYSQL_DIR}/lib)

add_executable(Example src/main.cpp)

target_link_libraries(Example libmysql)