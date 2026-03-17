#include "final_probabilistic_impl.h"

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128_t i128;

mt19937_64 rd((int)chrono::steady_clock::now().time_since_epoch().count());

/*
 Implementação da exponenciacão modular binária para eficientemente calcular a
 exponenciação de um uma (base b) a um (expoente e) (módulo m).
*/
i128 fast_modular_exponentiation(i128 b, i128 e, i128 m) {
  i128 r = 1;

  b %= m;
  while (e) {
    if (e & 1) r = (r * b) % m;

    b = ((b % m) * (b % m)) % m;
    e >>= 1;
  }

  return r;
}

/*
 Verifica se um (número positivo n) é composto, tomando uma (base b), um
 (expoente ímpar e) e um (número positivo s) para representar as potências de 2
 contidas em (n-1), retornando falso de imediato caso o valor de r =(b^e) mod(n)
 seja congruente a (1) ou (n-1), caso contrário, itera por todas as s potências
 em (n-1), exponenciando (r ^(2^s)) mod(n) e verificando se r passa
 a ser congruente a (n-1), caso passe, retorna falso.

 Se falhar em todas os casos acima, retorna verdadeiro.
*/
bool num_is_composite(i128 n, i128 b, i128 e, i128 s) {
  i128 r = fast_modular_exponentiation(b, e, n);

  if (r == 1 || r == n - 1) return false;

  for (ll c = 1; c < s; c++) {
    r = ((r % n) * (r % n)) % n;

    if (r == n - 1) return false;
  }

  return true;
}

/*
 Utiilza o algorítmo de Miller Rabin em sua forma probabilistica para
 verificar a primalidadde de um (número positivo n), também retornando falso
 imediatamente em casos triviais e verdadeiro para 2 e 3, a fim de evitar
 números menores que 2 na geração aleatória de bases.
*/
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

    if (num_is_composite(n, a, d, s)) return false;
  }

  return true;
}
