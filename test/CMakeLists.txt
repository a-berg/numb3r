# For now, only one executable is generated: the testing utility.
# Moreover
add_executable(
    unit_tests
    unit_tests.cpp
)

target_include_directories( unit_tests
    PUBLIC
        ../src/
)

target_link_libraries( unit_tests
    primality
    Catch2::Catch2
)