cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

project(basicTesting C CXX)

enable_testing()

add_subdirectory(test)
add_subdirectory(src)