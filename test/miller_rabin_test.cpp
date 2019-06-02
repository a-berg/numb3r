#include <catch2/catch.hpp>
#include <climits>
#include "miller_rabin.hpp"

TEST_CASE("Miller-Rabin test is performed",
          "[primality][miller-rabin]")
{
    SECTION("Some very standard cases"){
        CHECK(miller_rabin_test<uint16_t>(2,   25) == true);
        CHECK(miller_rabin_test<uint16_t>(3,   25) == true);
        CHECK(miller_rabin_test<uint16_t>(8,   25) == false);
        CHECK(miller_rabin_test<uint16_t>(17,  25) == true);
        CHECK(miller_rabin_test<uint16_t>(97,  25) == true);
        CHECK(miller_rabin_test<uint16_t>(100, 25) == false);
    }

    SECTION("32-bit ints"){
        std::vector<uint32_t> primeGen32 =
            {5, 17, 65, 99, 107, 135, 153, 185, 209, 267};
        
        for (auto &&pgen : primeGen32)
        {
            CHECK(miller_rabin_test<uint32_t>(ULONG_MAX - (pgen - 1), 25));
        }
    }

    SECTION("64-bit ints"){
        std::vector<uint64_t> primeGen64 =
            {59, 83, 95, 179, 189, 257, 279, 323, 353, 363};

        for (auto &&pgen : primeGen64)
        {
            CHECK(miller_rabin_test<uint64_t>(ULLONG_MAX - (pgen - 1), 25));
        }
    }
};