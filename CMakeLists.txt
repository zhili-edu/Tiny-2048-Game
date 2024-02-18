cmake_minimum_required(VERSION 3.29)
project(tiny2048)

set(CMAKE_CXX_STANDARD 11)

include_directories(src)
add_library(2048_lib STATIC src/2048.cpp)

add_executable(My2048Program src/main.cpp)
target_link_libraries(My2048Program 2048_lib)

enable_testing()
add_subdirectory(tests)