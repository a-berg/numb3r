#include <catch2/catch.hpp>
#include <climits>
#include "miller_rabin.hpp"

TEST_CASE("Miller-Rabin test is performed",
          "[primality][miller-rabin]")
{
    SECTION("Some very standard cases"){
        CHECK(miller_rabin_test(2,   25) == true);
        CHECK(miller_rabin_test(3,   25) == true);
        CHECK(miller_rabin_test(8,   25) == false);
        CHECK(miller_rabin_test(17,  25) == true);
        CHECK(miller_rabin_test(97,  25) == true);
        CHECK(miller_rabin_test(100, 25) == false);
    }

    SECTION("32-bit ints"){
        CHECK(miller_rabin_test(ULONG_MAX - (  5 - 1), 25));
        CHECK(miller_rabin_test(ULONG_MAX - ( 17 - 1), 25));
        CHECK(miller_rabin_test(ULONG_MAX - ( 65 - 1), 25));
        CHECK(miller_rabin_test(ULONG_MAX - ( 99 - 1), 25));
        CHECK(miller_rabin_test(ULONG_MAX - (107 - 1), 25));
        CHECK(miller_rabin_test(ULONG_MAX - (135 - 1), 25));
        CHECK(miller_rabin_test(ULONG_MAX - (153 - 1), 25));
        CHECK(miller_rabin_test(ULONG_MAX - (185 - 1), 25));
        CHECK(miller_rabin_test(ULONG_MAX - (209 - 1), 25));
        CHECK(miller_rabin_test(ULONG_MAX - (267 - 1), 25));
    }

    SECTION("64-bit ints"){
        CHECK(miller_rabin_test(ULLONG_MAX - ( 59 - 1), 25));
        CHECK(miller_rabin_test(ULLONG_MAX - ( 83 - 1), 25));
        CHECK(miller_rabin_test(ULLONG_MAX - ( 95 - 1), 25));
        CHECK(miller_rabin_test(ULLONG_MAX - (179 - 1), 25));
        CHECK(miller_rabin_test(ULLONG_MAX - (189 - 1), 25));
        CHECK(miller_rabin_test(ULLONG_MAX - (257 - 1), 25));
        CHECK(miller_rabin_test(ULLONG_MAX - (279 - 1), 25));
        CHECK(miller_rabin_test(ULLONG_MAX - (323 - 1), 25));
        CHECK(miller_rabin_test(ULLONG_MAX - (353 - 1), 25));
        CHECK(miller_rabin_test(ULLONG_MAX - (363 - 1), 25));
    }
};