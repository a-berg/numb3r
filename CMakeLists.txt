cmake_minimum_required(VERSION 3.5.0)

#### PROJECT
project(algos LANGUAGES CXX VERSION 0.1.0)

#### C++ standard == 17
set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

#### Set project structure
set(SOURCES
    src/numth.cpp
)
add_library(algos ${SOURCES})

#### Add Catch 2 & CTest
enable_testing()

find_package(Catch2 REQUIRED)
include(Catch)
include(CTest)

add_executable(unit_tests unit_tests.cpp)

#### Targets & executables
target_link_libraries(
    unit_tests
    algos
    Catch2::Catch2
)

add_test(test_all unit_tests)

#### Dunno what this is
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
