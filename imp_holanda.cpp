#include<bits/stdc++.h>

using namespace std;

mt19937_64 rng((int) chrono::steady_clock::now().time_since_epoch().count());
typedef __int128_t ll;
typedef __int128_t i128;

i128 mult(i128 a,i128 b,i128 mod) {
    return ((a % mod) * (b % mod)) % mod;
}

i128 fpow(i128 a,i128 b,i128 mod) {
    i128 res = 1;

    while(b) {
        if(b & 1) res = mult(res,a,mod);

        a = mult(a,a,mod);
        b >>= 1;
    }
    
    return res;
}

bool is_prime(i128 n) {
    i128 d = n - 1,s = 0;

    if(n == 2 || n == 3) return true;

    while(d % 2 == 0) {
        d /= 2;
        s++;
    }

    int test = 30;
    while(test--) {
        i128 a = uniform_int_distribution<long long>(2,n - 2)(rng); 
        i128 exp_a = fpow(a,d,n);

        if(exp_a == 1 || exp_a == n - 1) continue;
        
        bool prime = false;
        for(int i = 0;i < s;i++) {
            exp_a = mult(exp_a,exp_a,n);

            if(exp_a == n - 1) {
                prime = true;
            }
        }

        if(prime) continue;

        return false;
    }

    return true;
}

int main() {
    ll n;cin >> n;

    cout << ((is_prime(n)) ? "Is prime" : "Is not prime") << "\n";

    return 0;
}


