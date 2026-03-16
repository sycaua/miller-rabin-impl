#include<bits/stdc++.h>

using namespace std;
#define rep(i,a,b) for(int i = (a);i < (b);i++) 
mt19937_64 rng((int) chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef __int128_t i128;

i128 fast_mod_exponentiation(i128 n,i128 exp, i128 m) {
    n %= m;
    i128 resto = 1;
    while(exp){
        if (exp % 2)
            resto = (resto * n) % m;
        n = ((n % m) * (n % m)) % m;
        exp >>= 1;
    }
    return resto;
}

bool is_composite(i128 num, i128 base, i128 odd_power, i128 s){
    i128 rest = fast_mod_exponentiation(base,odd_power,num);

    if (rest == 1 || rest == num-1)
        return false;

    for (int r =1; r  < s;r++){
        rest = ((rest) % num * (rest) % num % num);
        if (rest == num-1){
            return false;
        }
    }

    return true;
}


int miller_rabin(i128 n) {
    i128 d = n - 1,s = 0;

    if(n > 1e9) {
        return -1;
    }

    if(n == 2 || n == 3) return true;

    while(d % 2 == 0) {
        d /= 2;
        s++;
    }

    for(int a :  {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
        if(is_composite(n,a,d,s)) {
            return 0;
        }
    }

    return 1;
}



int main() {
    ll n;cin >> n;

    int res = miller_rabin(n);

    if(res == -1) cout << "To large" << endl;
    else if(res == 0) cout << "Is not prime" << endl;;
    else cout << "Is prime" << endl;
}
