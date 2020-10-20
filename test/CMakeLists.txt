add_executable(initTest myTest.cpp)

target_link_libraries(initTest gmock_main)

target_link_libraries(initTest TSclass)
target_link_libraries(initTest SmoothClass)

add_test(NAME initTest COMMAND initTest)

target_include_directories(initTest PUBLIC "${PROJECT_BINARY_DIR}")

