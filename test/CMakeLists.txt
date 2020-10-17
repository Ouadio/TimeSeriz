add_executable(test1 myTest.cpp)

target_link_libraries(test1 gtest gmock)

target_link_libraries(test1 TSclass)

add_test(NAME test1 COMMAND test1)

target_include_directories(test1 PUBLIC "${PROJECT_BINARY_DIR}")

