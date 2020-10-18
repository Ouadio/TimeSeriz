cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)

project(basicTesting C CXX)

add_subdirectory(googletest)
enable_testing()
add_subdirectory(test)
add_subdirectory(src)
