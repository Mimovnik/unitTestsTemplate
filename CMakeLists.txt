cmake_minimum_required(VERSION 3.0.0)
project(myProgramName VERSION 0.1.0)

add_subdirectory(googletest)
enable_testing()

add_library(
    programToTest

    src/main.cpp
)

add_subdirectory(tests)