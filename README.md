# Implementation code of the Miller-Rabin primality test

This repository contains two implementations of the Miller-Rabin primality test: one that is deterministic for non-negative integers up to 2^64 (by using witness bases), and another that is probabilistic (uses random bases).

The complexity of both versions is ~_O_(log_N_). The probabilistic version guarantees 4^(-100)=2^(-200) chance of error (100 iterations).

## References

- **Algorithms for Competitive Programming**. _Primality tests_. Available at [cp-algorithms.com](https://cp-algorithms.com/algebra/primality_tests.html).
- Ben Lynn. _Primality Tests_. Available at [crypto.stanford.edu](https://crypto.stanford.edu/pbc/notes/numbertheory/millerrabin.html).
- Bobby Kleinberg. _The Miller-Rabin Randomized Primality Test_. Available at [cs.cornell.edu](https://www.cs.cornell.edu/courses/cs4820/2010sp/handouts/MillerRabin.pdf).
- Shyam Narayanan. _Improving the Speed and Accuracy of the Miller-Rabin Primality Test_. Available at [math.mit.edu](https://math.mit.edu/research/highschool/primes/materials/2014/Narayanan.pdf).
