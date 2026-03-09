#include <bits/stdc++.h>
#include <random>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

mt19937_64 rng((int) chrono::steady_clock::now().time_since_epoch().count());

#define all(x) (x).begin(), (x).end()
#define fl(i, a, b) for (int i = a; i < (b); i++)
#define fll(i, a, b) for (ll i = a; i < ll(b); i++)
#define ln "\n"

typedef __int128_t i128;

bool trial_division(ll x) {
    bool p = true;

    for(ll i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            p = false;
            break;
        }
    }

    return p;
}

i128 fast_mod_exponentiation(i128 b,i128 e, i128 m) {
    if (e == 0)
        return 1;
    else if (e % 2 == 1)
        return ((fast_mod_exponentiation(b, e - 1, m) % m) * (b % m)) % m;

    ll r = fast_mod_exponentiation(b, e / 2, m) % m;
    return ((r % m) * (r % m)) % m;
}

bool is_prime(ll n) {
    if (n <= 1)
        return false;
    else if (n == 2)
        return true;
    else if (!(n & 1))
        return false;

    ll d, s;


    d = n - 1; s = 0;
    while (!(d & 1)) {
        d >>= 1;
        s++;
    }

    cout << "---> d = " << d << ln;
    cout << "---> s = " << s << ln;
    bool p = false;
    fll(i, 0, 100) {
        cout << "@ Iteration " << (i + 1) << ln;
        ll a = uniform_int_distribution<ll>(2, (ll) 1e18)(rng);
        cout << "Testing for a = " << a << ln;

        i128 x = fast_mod_exponentiation(a, d, n);
        if (x == 1 || x == n - 1) {
            p = true;
            continue;
        } else {
            ll cc = 0;
            while (cc < s) {
                x = ((x % n) * (x % n)) % n;

                if (x == n - 1) {
                    p = true;
                    break;
                }

                cc++;
            }
        }

        if (p)
            continue;
        else
            return false;
    }

    return true;
}

void stress_test(ll up) {
    ll c = 0;
    fll(i, 0, up) {
        uniform_int_distribution<int> distribution(2, 1e9);
        ll n = distribution(rng);
        bool p1 = trial_division(n);
        bool p2 = is_prime(n);
        cout << "@ Test " << (i + 1) << " (number = " << n << ")" << ln;
        cout << "-> Trial division answer: " << p1 << ln;
        cout << "-> Miller-Rabin answer: " << p2 << ln;

        if (p1 == p2)
            c++;
    }

    cout << "FOR " << up << " ITERATIONS, " << c << " MATCHED" << ln;
}

int main() {
    //ios::sync_with_stdio(false); cin.tie(NULL);

    cout << "Please type a non-negative integer to check for primality: ";
    long long n; cin >> n;

    cout << is_prime(n) << ln;
}
