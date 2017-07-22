#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (ll (i) = ll(a); (i) <= ll(b); (i)++)
#define SQRTN 10000011
typedef unsigned long long ll;

// it's multiplicative, only need to consider prime powers
// thankfully, easy to compute that for p^e. on a table:
//     1   p   p2  p3  ..  pe
// 1   1   1   1   1   ..  1
// p   1   p   p   p   ..  p
// p2  1   p   p2  p2  ..  p2
// p3  1   p   p2  p3  ..  p3
// ..  ..  ..  ..  ..  ..  ..
// pe  1   p   p2  p3  ..  pe
// ans = sum (i = 0 to e) (2e-2i+1)p^i
// i won't bother simplifying this

int t, e;
ll c, n, p2, pe, res, tmp, ans;
bitset<SQRTN> p;

ll pow(ll p, int e) {
  if (e == 0) return 1;
  if (e == 1) return p;
  if (e & 1) return p * pow(p, e-1);
  return (p2 = pow(p, e/2)) * p2;
}

ll compute(ll p, int e) {
  pe = 1, res = 0;
  REP(i, 0, e) res += (2*e-2*i+1)*pe, pe *= p;
  return res;
}

int main() {
  p[1] = 1;
  REP(i, 2, SQRTN-1) if (!p[i]) {
    c = 2; while (c*i <= SQRTN) p[c*i] = 1, c++;
  }
  cin >> t;
  REP(j, 1, t) {
    cin >> n;
    ans = 1, e = 0;
    REP(i, 2, SQRTN-1) if (!p[i]) {
      e = 0; while (n % i == 0) n /= i, e++;
      if (e) ans *= compute(i, e);
      if (n == 1) break;
    }
    if (n != 1) ans *= compute(n, 1);
    cout << "Case " << j << ": " << ans << endl;
  }
}