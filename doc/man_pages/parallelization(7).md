---
title: Parallelization
---

The easiest way to model parallelizable code is through the use of **monoids**.
A monoid is a set $A$ equipped with an operation $\circ$ that is associative and
has an identity element. It is written as $(A,\ \circ\,,\ e)$.

Some examples (relevant to this program):

- $(\mathbb{B},\ \wedge,\  1)$, that is, boolean truth values with the `AND` operation and `True` as the identity.
- $(\mathbb{N},\ +,\ 0)$ and $(\mathbb{N},\ \cdot\,,\ 1)$.
- $(\mathbb{Q},\ +,\ 0)$. Relevant to the computing of constants.

Associativity of the monoid operation guarantees that the code is parallelizable.

## Miller Rabin Test

Here we find the $(\mathbb{N},\ +,\ 0)$, $(\mathbb{N},\ \cdot\,,\ 1)$ and $(\mathbb{B},\ \wedge,\  1)$ monoids. We can conclude that the following operations can be parallelized:

- The predicate `single_miller_rabin : Integer -> Bool`.
- Multiplication (consequence of $(\mathbb{N},\ +,\ 0)$).
- Exponentiation (consequence of $(\mathbb{N},\ \cdot\,,\ 1)$).