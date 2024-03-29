#include <cstdint>
#include <cmath>

/// \brief Multiply two numbers modulo m (a*b mod m).
///
/// Use the russian peasant algorithm to perform multiplication fast.
///
/// \par Requires
/// - All operands are of type unsigned integer.
/// 
/// \par Ensures
/// - Operations are carried out without overflow.
/// 
/// @param   a   First number to be multiplied.
/// @param   b   Second number to be multiplied.
/// @param   m   Modulo.
///
template<
    typename TUInt,
    typename std::enable_if_t<std::is_unsigned<TUInt>::value>* = nullptr>
TUInt mulmod(TUInt a, TUInt b, TUInt m)
{
    TUInt res = 0;
    TUInt temp_b;

    b %= m;

    while (a != 0) {
        if (a & 1) {
            // Add b to res, modulo m, without overflow
            if (b >= m - res) // Equiv to if (res + b >= m), without overflow
                res -= m;
            res += b;
        }
        a >>= 1;

        // Double b, modulo m
        temp_b = b;
        if (b >= m - b) // Equiv to if (2 * b >= m), without overflow
            temp_b -= m;
        b += temp_b;
    }
    return res;
};

/// \brief Does a^b mod m fast and safely.
/// 
/// This routine essentially uses exponentiation by squaring.
///
/// \par Requires
/// - All operands are of type unsigned integer.
/// 
/// \par Ensures
/// - Operations are carried out without overflow.
/// 
/// \param   base        Unsigned Integer.
/// \param   exponent    Unsigned Integer.
/// \param   modulus     Unsigned Integer.
template<
    typename TUInt,
    typename std::enable_if_t<std::is_unsigned<TUInt>::value>* = nullptr>
TUInt powmod(TUInt base, TUInt exponent, TUInt modulus)
{
    TUInt r = modulus==1?0:1;
    while (exponent > 0) {
        if(exponent & 1)
            r = mulmod<TUInt>(r, base, modulus);
        exponent >>= 1;
        base = mulmod<TUInt>(base, base, modulus);
    }
    return r;
};