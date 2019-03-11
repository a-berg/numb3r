#include "../lib/numth.hpp"



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

uint64_t powmod(uint64_t base, uint64_t exponent, uint64_t modulus)
{
    uint64_t r = modulus==1?0:1;
    while (exponent > 0) {
        if(exponent & 1)
            r = mulmod(r, base, modulus);
        exponent >>= 1;
        base = mulmod(base, base, modulus);
    }
    return r;
}

uint64_t mulmod(uint64_t a, uint64_t b, uint64_t m) {
    uint64_t res = 0;
    uint64_t temp_b;

    b %= m;

    while (a != 0) {
        if (a & 1) {
            /* Add b to res, modulo m, without overflow */
            if (b >= m - res) /* Equiv to if (res + b >= m), without overflow */
                res -= m;
            res += b;
        }
        a >>= 1;

        /* Double b, modulo m */
        temp_b = b;
        if (b >= m - b)       /* Equiv to if (2 * b >= m), without overflow */
            temp_b -= m;
        b += temp_b;
    }
    return res;
}

// Finds the biggest prime p such that p <= number
uint64_t prime_leq(uint64_t number) {

    while(number != 0 && !miller_rabin_test(number, 128)) {
        number--;
    }
    return number;
}

// Finds all the sexy prime pairs (p,p+6) such that p+6 <= number
uint64_t sexy_primes(uint64_t number) {

    while(number != 0 && !miller_rabin_test(number, 128)) {
        number--;
    }
    return number;
}