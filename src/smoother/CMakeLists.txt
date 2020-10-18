add_library(SmoothClass STATIC smoother.cpp)

target_include_directories(SmoothClass INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")