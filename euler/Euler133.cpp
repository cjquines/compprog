#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for(int (i) = int(a); (i) <= int(b); (i)++)
#define N 100001

typedef long long ll;

// assume p > 3 first. R(k) = (10^k - 1)/9.
// R(k) = 0 (mod p) iff 10^k = 1 (mod 9p)
// also, R(10^a)|R(10^b) if a <= b, so only
// need to check for large enough b. use
// euler: 10^k = 10^(k % 6p - 6) (mod 9p)

int c;
ll res;
bitset<N> p;

ll modpow(int b, ll e, int m) {
  if (e == 0) return 1;
  if (e == 1) return b;
  if (e & 1) return (b*modpow(b, e-1, m)) % m;
  long long b2 = modpow(b, e/2, m);
  return (b2*b2) % m;
}

int main() {
  p[1] = 1;
  REP(i, 2, N-1) if (!p[i]) {
    c = 2; while (c*i <= N) p[c*i] = 1, c++;
  }
  REP(i, 2, N) if (!p[i])
    if (modpow(10, modpow(10, 100, 6*i-6), 9*i) != 1)
      res += i;
  printf("%I64d\n", res);
}