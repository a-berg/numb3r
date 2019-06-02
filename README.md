# numb3r

[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)
![version: 0.1.0](https://img.shields.io/badge/version-0.1.0-yellow.svg)

- [numb3r](#numb3r)
    - [Goals](#goals)
    - [Non-goals](#non-goals)
  - [Features](#features)
    - [Roadmap](#roadmap)
  - [Usage](#usage)
  - [API documentation](#api-documentation)
    - [Primality testing](#primality-testing)
    - [Prime Sieve](#prime-sieve)
    - [Constants](#constants)
    - [Other](#other)
  - [Contact and contribution](#contact-and-contribution)
  - [License](#license)

---

A toy C++ 17 program to learn software engineering.

Primarily interested in exploring these features:

- Modern C++, STL
- Multithreading
- Tools (CMake, clang, Catch2, Doxygen)
- TDD

The objective of this project is to build a **small**, well documented, well
designed, well tested and performant program to run basic number theory algorithms.

### Goals

- Extensive unit testing.
- Performant algorithms, use of multithreading when possible.
- Provide templating of methods for unsigned integers up to 64 bits and multi-precision.
- Modern CMake, modularity.
- LLVM code style; enforcement by clang-tidy and clang-format.
- Good documentation.

### Non-goals

- Provide generic methods for any generic ring or field type (e.g. no
  primality testing for matrices).
- Implement advanced algorithms (i.e. no AKS, RSA, etc).
- Benchmarking (one would argue this is necessary if I pretend to parallelize
  code, however, it might become too much hassle for a small project)

## Features

   Miller-Rabin primality testing.
- Templated methods, STL enforcement of unsigned types.

### Roadmap

- Prime sieve.
- Computing of some constants (Euler-Mascheroni, π).
- Factorization via Pollard's rho algorithm.
- Parallel execution of algorithms.
  - [ ] Miller-Rabin
  - [ ] Prime sieve

## Usage

This distribution, as of today, is not considered "usable". However, in the
spirit of FOSS, I will give brief directives on how to use.

As of 2019-06-02 only Miller-Rabin is implemented. You just need to grab the 2 header files under `src/primality` and you are set. Refer to  [miller-rabin(3)](doc/man_pages/miller-rabin(3).md) for more information.

## API documentation

> A note about documentation: I use man page notation for the document names,
> however I am experimenting with documentation formats so they are not
> *guaranteed* to use man pages conventions.

Here you will find links to the manual pages of the project.

### Primality testing

- [miller-rabin(3)](doc/man_pages/miller-rabin(3).md)
- [miller-rabin(7)](doc/man_pages/miller-rabin(7).md) (draft)

### Prime Sieve

- prime-sieve(3)
- prime-sieve(7)

### Constants

- euler-mascheroni(3)
- euler-mascheroni(7)
- pi(3)
- pi(7)

### Other

- [parallelization(7)](doc/man_pages/parallelization(7)) (draft, stub)

## Contact and contribution

I don't expect any contributions, since this repository is never going to be
known. However, should you detect a bug or have some suggestion for improvement,
you can send an e-mail to [aberges@outlook.com](aberges@outlook.com), or submit
a pull-request, or open an issue; I will be glad to learn more.

Code of conduct could be expressed as this: please don't troll, please don't be an ass.

## License

**numb3r** is released as open source software under the GPL v3 license, see the
LICENSE.txt file in the project root for the full license text.