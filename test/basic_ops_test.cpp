#include <catch2/catch.hpp>
#include <climits>
#include "basic_operations.hpp"

TEST_CASE("Multiplication modulo m is robust against overflow.",
          "[basic-operations][mulmod]")
{
    SECTION("32-bit ints"){
        CHECK(
            mulmod<uint32_t>(ULONG_MAX-1, ULONG_MAX-1, ULONG_MAX - ( 5 - 1)) 
            == 9);
        CHECK(
            mulmod<uint32_t>(ULONG_MAX-1, ULONG_MAX-1, ULONG_MAX - (17 - 1)) 
            == 225);
        CHECK(
            mulmod<uint32_t>(ULONG_MAX-1, ULONG_MAX-1, ULONG_MAX - (65 - 1)) 
            == 3969);
    }

    SECTION("64-bit ints"){
        CHECK(
            mulmod<uint64_t>(ULLONG_MAX - 1, ULLONG_MAX - 1, ULLONG_MAX - (59 - 1)) 
            == 3249);
        CHECK(
            mulmod<uint64_t>(ULLONG_MAX - 1, ULLONG_MAX - 1, ULLONG_MAX - (83 - 1)) 
            == 6561);
        CHECK(
            mulmod<uint64_t>(ULLONG_MAX - 1, ULLONG_MAX - 1, ULLONG_MAX - (95 - 1)) 
            == 8649);
    }
};

TEST_CASE("Power modulo m is robust against overflow.",
          "[basic-operations][powmod]")
{
    SECTION("32-bit ints"){
        CHECK(powmod<uint32_t>(ULONG_MAX-1, 3, ULONG_MAX - ( 5 - 1)) == 27);
        CHECK(powmod<uint32_t>(ULONG_MAX-1, 3, ULONG_MAX - (17 - 1)) == 3375);
        CHECK(powmod<uint32_t>(ULONG_MAX-1, 3, ULONG_MAX - (65 - 1)) == 250047);
    }

    SECTION("64-bit ints"){
        CHECK(powmod<uint64_t>(ULLONG_MAX - 1, 3, ULLONG_MAX - (59 - 1)) == 185193);
        CHECK(powmod<uint64_t>(ULLONG_MAX - 1, 3, ULLONG_MAX - (83 - 1)) == 531441);
        CHECK(
            powmod<uint64_t>(ULLONG_MAX - 1, 9223372036854775807, ULLONG_MAX - (95 - 1)) ==
            9087951427482486718
        );
    }
};
