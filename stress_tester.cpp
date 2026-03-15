#include <bits/stdc++.h>
#include <random>
#include "final_probabilistic_impl.h"
using namespace std;

mt19937_64 rdm((int) chrono::steady_clock::now().time_since_epoch().count());

#define ln "\n"
typedef __int128_t i128;

bool trial_division_is_prime(i128 n) {
    if (n <= 1)
        return false;
    else if (n == 2)
        return true;
    else if (n % 2 == 0)
        return false;

    for (i128 d = 3; d * d <= n; d += 2) {
        if (n % d == 0)
            return false;
    }

    return true;
}

string str_repr(bool is_prime) {
    return (is_prime) ? "PRIME" : "NOT PRIME";
}

int main() {
    cout << "Running 1e6 iterations of tests for integers ranging from 0 to 1e9" << ln;

    for (int i = 1; i <= 1e6; i++) {

        i128 n = uniform_int_distribution<i128>(0, 1e9)(rdm);

        cout << "TEST " << i << ln;
        cout << "  -> n = " << (long long) n << ln;

        bool trial_answer = trial_division_is_prime(n);
        bool miller_rabin_answer = is_prime(n);

        cout << "    ==> Trial division answer: " << str_repr(trial_answer) << ln;
        cout << "    ==> Miller-Rabin answer: " << str_repr(miller_rabin_answer) << ln;

        if (trial_answer == miller_rabin_answer)
            cout << "--> OK" << ln;
        else {
            cout << "// FAIL" << ln;
            break;
        }
    }
}
