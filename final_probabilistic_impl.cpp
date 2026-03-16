#include<bits/stdc++.h>
#include "final_probabilistic_impl.h"

using namespace std;

typedef long long ll;
typedef __int128_t i128;

mt19937_64 rd((int) chrono::steady_clock::now().time_since_epoch().count());

i128 fast_modular_exponentiation(i128 b, i128 e, i128 m) {
    i128 r = 1;

    b %= m;
    while (e) {
        if (e & 1)
            r = (r * b) % m;

        b = ((b % m) * (b % m)) % m;
        e >>= 1;
    }

    return r;
}

bool num_is_composite(i128 n, i128 b, i128 e, i128 s){
    i128 r = fast_modular_exponentiation(b, e, n);

    if (r == 1 || r == n - 1)
        return false;

    for (ll c = 1; c < s; c++) {
        r = ((r % n) * (r % n)) % n;

        if (r == n - 1)
            return false;
    }

    return true;
}

bool is_probably_prime(i128 n) {
    if (n <= 1)
        return false;
    else if (n == 2 || n == 3)
        return true;
    else if (!(n & 1))
        return false;

    i128 d, s;

    d = n - 1;
    s = 0;
    while (!(d & 1)) {
        d >>= 1;
        s++;
    }

    for (int i = 1; i <= 100; i++) {
        i128 a = uniform_int_distribution<ll>(2, n - 2)(rd);
        i128 x = fast_modular_exponentiation(a, d, n);

        if (num_is_composite(n, a, d, s))
            return false;
    }

    return true;
}
