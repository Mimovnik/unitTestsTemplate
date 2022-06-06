cmake_minimum_required(VERSION 3.0.0)
project(Tests VERSION 0.1.0)


add_executable(Tests Tests.cpp)
target_link_libraries(Tests PUBLIC gtest_main programToTest)

add_test(
    NAME Tests 
    COMMAND Tests 
)