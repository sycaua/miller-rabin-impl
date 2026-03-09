#include<bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;
using namespace std;

#define i128 int128_t

i128 binary_exp(i128 n, i128 m , i128 exp){

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
    i128 rest = binary_exp(base,num,odd_power);

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

bool miller_rabin_rand(i128 num, int tries){
    if (num < 4)
        return (num == 3) || (num == 2);

    int s = 0;
    i128 d = num-1;

    while((d % 2) == 0){
        d >>= 1;
        s++;
    }

    for (int i = 0; i < tries; i++){
        i128 a = 2 + (rand() % (num-3));
        if (is_composite(num,a,d,s))
            return false;
    }
    return true;
}

int main(){

    i128 n;
    int t;

    cin >> n >> t;
    
    if (miller_rabin_rand(n,t)){
        cout << n << " is prime" << '\n';
    } else{
        cout << n << " is not prime" << '\n';
    }

}
