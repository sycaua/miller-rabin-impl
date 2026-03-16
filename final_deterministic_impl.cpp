#include<bits/stdc++.h>
#include "final_deterministic_impl.h"

using namespace std;

typedef long long ll;
typedef __int128_t i128;

mt19937_64 rng((int) chrono::steady_clock::now().time_since_epoch().count());

i128 fast_mod_exponentiation(i128 b, i128 e, i128 m) {
    i128 r = 1;

    b %= m;
    while (e){
        if (e & 1)
            r = (r * b) % m;

        b = ((b % m) * (b % m)) % m;
        e >>= 1;
    }

    return r;
}

bool is_composite(i128 n, i128 b, i128 e, i128 s){
    i128 r = fast_mod_exponentiation(b, e, n);

    if (r == 1 || r == n - 1)
        return false;

    for (ll c = 1; c < s; c++) {
        r = ((r % n) * (r % n)) % n;

        if (r == n - 1)
            return false;
    }

    return true;
}


bool is_prime(i128 n) {
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

    for (ll a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022})
        if (is_composite(n, a, d, s))
            return false;

    return true;
}
