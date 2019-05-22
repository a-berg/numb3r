#include "basic_operations.hpp"

#include <random>
#include <cstdint>

/// \brief Perform the miller-rabin primality test.
/// 
/// The Miller-Rabin primality test is a well known, performant algorithm to
/// test wether a number is prime or not. The following manual pages should
/// be of help: miller-rabin(1,3,7).
/// 
/// \param  number  The number to be tested.
/// \param  acc     Number of rounds to be passed by the number.
///
template<
    typename TUInt,
    typename std::enable_if_t<std::is_unsigned<TUInt>::value>* = nullptr>
bool miller_rabin_test(const TUInt &number, const uint64_t &acc)
{
    // initial check
    if (number == 2 || number == 3)
        return true;
    if (number % 2 == 0 || number % 3 == 0)
        return false;
    // factorise number to 2^s d
    TUInt d = number - 1;
    TUInt s = 0;
    while ((d & 1) == 0 && d > 0)
    {
        d >>= 1;
        s++;
    }
    // initialize distribution
    std::default_random_engine generator;
    std::uniform_int_distribution<TUInt> distribution(2, number - 2);
    // actual miller-rabin here
    TUInt witness;
    TUInt x;
    for (int k = 0; k < acc; ++k) // run k miller-rabin tests
    {
        // NOTE: in Z/nZ, a = -1 and n - 1 = a is the same
        witness = distribution(generator);
        x = powmod<TUInt>(witness, d, number);
        if (x == 1 || x == number - 1) // test passed, run next one
            continue;

        for (int i = 0; i < s - 1; ++i)
        {
            x = powmod<TUInt>(x, 2, number);

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