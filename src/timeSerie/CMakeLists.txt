add_library(TSclass STATIC timeSerie.cpp)

target_include_directories(TSclass INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")