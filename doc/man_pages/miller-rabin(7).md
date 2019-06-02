# The Miller-Rabin primality test

$$
\newcommand{\complexity}[1]{\mathcal{O}(#1)\ }
\newcommand{\linear}{n}
\newcommand{\logn}{\log n}
\newcommand{\loglinear}{n\,\log n}
\newcommand{\polylog}[1]{\log^{#1} n}
$$

> This page is extremely outdated and incomplete. A more complete version, in
> Spanish, can be found [here][aberges-miller-rabin]. I am working to revamp
> this.

[aberges-miller-rabin]: https://adrianberges.com/2019/02/25/MillerRabin.html

## Introduction

The test is based off the Theorem 2.1 in [1][05rene]. Essentially, given a
number $n$ that we want to know if its prime or composite, we can check every
number from $1$ to $n-1$ and see if the property $x^m = 1$ or $x^{m 2^i} = -1$
for some $0\leq i < k$ holds, and given that we write $n-1 = 2^k m$.

From here, we go on to determine that: if we write $n-1$ as above and we check
for a random $x$ the equation $x^{m 2^i} = -1$ for every $k$, then we can say
that $n$ is _probably prime_. Repeating the test $a$ times improves the
probability of $n$ being prime.

## Sketch of algorithm

The test needs to check for the following conditions:

1. If $w^d \equiv 1 \mod n$ or $w^d \equiv n-1 \mod n$ then n passes the test
2. 

## Implementation details

We first need to factorise $n-1$ into the form $n-1 = 2^k m$:

```cpp
typedef long long unsigned u64;
typedef long unsigned      u32;

u64 n;
u32 a;

u64 temp = number - 1;
u64 s = 0;
while (temp % 2 == 0 && temp > 0)
{
    temp /= 2;
    s += 1;
}
u64 d = (number - 1) / pow(2, s);
```

After this, write an outer loop for `a`:

```cpp
for(int i = 0; i < a; i++){
    // inner loop
}
```

Inside the inner loop we should find the proper algorithm.
[etc.]

## Complexity

The algorithm's complexity given this implementation is of
$\complexity{a\polylog{3}}$. As seen in [1][05rene], the exponent to the
logarithm ought to be $1+\mu$, with $\mu = 2$ for standard multiplication (since
I am not implementing FFT-based multiplication).

Moreover, the paper says that the probability of a composite to pass the test
$a$ times is $1/4$ for $a=1$, $a^{-1}$ for $a=\logn$, and $n^{-\logn}$ for
$a=\polylog{2}$.

This means that the total complexity will be in the range
$\complexity{\polylog{4}}$ to $\complexity{\polylog{5}}$ depending on our choice of
$a$. For large numbers, $a=\logn$ seems appropriate.

**Note**: For implementations using up to 64-bit integers, it suffices to check
with witnesses `[2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37]` instead of drawing
at random. This makes the test deterministic and thus only needing
$\complexity{\polylog{3}}$ time to complete.

## References

[05rene]: http://www.math.leidenuniv.nl/~psh/ANTproc/05rene.pdf
[wiki]:   https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test