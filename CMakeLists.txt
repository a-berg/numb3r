cmake_minimum_required(VERSION 3.5.0)

project(numb3r CXX)

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR} ) # tells CMake to put unit_tests into bin instad of bin/test

find_package(Catch2 REQUIRED)
include(Catch) # doing the includes early, is it good practice?
include(CTest) # needed?

add_subdirectory(test)
add_subdirectory(src)

enable_testing()

add_test( ${PROJECT_NAME}_test_all
    unit_tests
)