---
title: miller-rabin
---

# Miller-Rabin test

Runs several Miller-Rabin tests to find out if a number is prime.

## Synopsis

```cpp
#include <miller_rabin.hpp>

bool
miller_rabin_test<UnsignedType>(UnsignedType n, uint64_t k);
```

## Description

The Miller-Rabin primality test is a well known, performant algorithm to test
wether a number is prime or not. See ([Rabin 1965][rabin-paper], [Rene
2005][rene-paper]), as well as the in-depth manual page: [miller-rabin(7)][miller-rabin(7)].

The function is templated, with usage of the STL to limit use to unsigned types.
Expect bizarre template errors if you use any other types; you have been warned!

The parameters meaning are as follow:

- `n`: the number to be checked.
- `k`: the rounds to be performed on `n`.

Complexity should be bounded by $\mathcal{O}(\log^3(n))$.

Type deduction is possible, however you should mark the number with any of the
`U*` suffixes to indicate that it's an unsigned type, otherwise the compiler
will assume it's a signed integer (it's the default behaviour).

The test is deterministic for composite numbers, although there is a small
chance, upper-bounded by $n^{-4}$, to return `false` for primes; it is so small
that in practice the test should be considered deterministic in all cases.

## Example

```cpp
#include <miller_rabin.hpp>

miller_rabin_test<>(
    3'162'646'859'112'208'529ULL, // 64-bit integer
    100 // 100 rounds
)
```

The compiler will deduce type `uint64_t` for the template, then the function
will return `true` as the used number is prime (although there is a small
chance, upper-bounded by $n^{-4}$, to return `false` it so small that in practice the test should be considered deterministic).

[rabin-paper]: https://www.sciencedirect.com/science/article/pii/0022314X80900840
[rene-paper]: ../3rdparty/rene05.pdf
[miller-rabin(7)]: miller-rabin(7).md