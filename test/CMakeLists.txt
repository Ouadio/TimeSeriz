add_executable(test1 myTest.cpp)
target_link_libraries(test1 gmock_main)

target_link_libraries(test1 TSclass)
target_link_libraries(test1 SmoothClass)


add_test(NAME test1 COMMAND test1)

target_include_directories(test1 PUBLIC "${PROJECT_BINARY_DIR}")

