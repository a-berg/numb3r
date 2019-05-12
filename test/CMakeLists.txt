# For now, only one executable is generated: the testing utility.
add_executable( unit_tests
    unit_tests.cpp
    basic_ops_test.cpp
    miller_rabin_test.cpp
)

target_include_directories( unit_tests
    PRIVATE ../src/
)

target_link_libraries( unit_tests
    primality
    Catch2::Catch2
)