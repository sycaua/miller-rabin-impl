#include<bits/stdc++.h>
#include <random>

#include "final_probabilistic_impl.h"

using namespace std;

using ll = long long;
typedef __int128_t i128;

mt19937_64 rng((int) chrono::steady_clock::now().time_since_epoch().count());

i128 fast_mod_exponentiation(i128 b, i128 e, i128 m) {
    i128 r = 1;

    while (e) {
        if (e & 1)
            r = ((r % m) * (b % m)) % m;

        b = ((b % m) * (b % m)) % m;
        e >>= 1;
    }

    return r;
}


bool is_prime(i128 n) {
    if (n <= 1)
        return false;
    else if (n == 2)
        return true;
    else if (!(n & 1))
        return false;

    i128 d, s;

    d = n -1;
    s = 0;
    while (!(d & 1)) {
        d >>= 1;
        s++;
    }

    bool prime = false;
    for (int i = 1; i <= 100; i++) {
        i128 a = uniform_int_distribution<i128>(2, n - 2)(rng);
        i128 x = fast_mod_exponentiation(a, d, n);

        prime = false;

        if (x == 1 || x == n - 1) {
            prime = true;
            continue;
        } else {
            ll counter = 0;
            while (counter < s - 1) {
                x = ((x % n) * (x % n) % n);

                if (x == n - 1) {
                    prime = true;
                    break;
                }

                counter++;
            }
        }

        if (prime)
            continue;
        else
            return false;
    }

    return true;
}
