#include <basic_operations.hpp>
#include <random>

bool miller_rabin_test(const uint64_t &number, const uint64_t &acc)
{
    // initial check
    if (number == 2 || number == 3)
        return true;
    if (number % 2 == 0 || number % 3 == 0)
        return false;
    // factorise number to 2^s d
    uint64_t d = number - 1;
    uint64_t s = 0;
    while ((d & 1) == 0 && d > 0)
    {
        d >>= 1;
        s++;
    }
    // initialize distribution
    std::default_random_engine generator;
    std::uniform_int_distribution<uint64_t> distribution(2, number - 2);
    // actual miller-rabin here
    uint64_t witness;
    uint64_t x;
    for (int k = 0; k < acc; ++k) // run k miller-rabin tests
    {
        /* NOTE: in Z/nZ, a = -1 and n - 1 = a is the same */
        witness = distribution(generator);
        x = powmod(witness, d, number);
        if (x == 1 || x == number - 1) // test passed, run next one
            continue;

        for (int i = 0; i < s - 1; ++i)
        {
            x = powmod(x, 2, number);

            if (x == 1) // test failed, n is not prime
                return false; // break from function

            if (x == (number - 1)) // test passed, run next one
                break; // break from inner for loop into outer for loop
        }

        if (x != number - 1) // test failed, n is not prime
            return false;
    }
    return true; // all tests passed, good chance that n is prime
};