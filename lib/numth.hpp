#include <cmath>
#include <random>
//#include "typedefs.hpp"

bool miller_rabin_test(const uint64_t &number, const uint64_t &acc);

uint64_t powmod(uint64_t base, uint64_t exponent, uint64_t modulus);
uint64_t mulmod(uint64_t a, uint64_t b, uint64_t modulus);

uint64_t prime_leq(uint64_t number);
uint64_t sexy_primes(uint64_t number);