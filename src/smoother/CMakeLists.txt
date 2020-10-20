set(SRC_FILES smoother.cpp ma.cpp)
set(H_FILES smoother.h ma.h)

add_library(SmoothClass STATIC ${SRC_FILES} ${H_FILES} )

target_include_directories(SmoothClass INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")