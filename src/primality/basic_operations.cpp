#include "basic_operations.hpp"

/**
 * @brief Does a^b mod m fast and safe.
 * 
 * This routine essentially uses a 
 * 
 * @param   base        Number.
 * @param   exponent    Number.
 * @param   modulus     Number.
*/
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
};

/**
 * @brief Multiply two numbers modulo m (a*b mod m).
 * 
 * Use the russian peasant algorithm to perform multiplication fast.
 * 
 * @param   a   Number.
 * @param   b   Number.
 * @param   m   Modulo.
*/
uint64_t mulmod(uint64_t a, uint64_t b, uint64_t m)
{
    uint64_t res = 0;
    uint64_t temp_b;

    b %= m;

    while (a != 0) {
        if (a & 1) {
            /* Add b to res, modulo m, without overflow */
            if (b >= m - res) // Equiv to if (res + b >= m), without overflow
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