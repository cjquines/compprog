#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int (i) = int(a); (i) <= int(b); (i)++)
typedef long long ll;

ll p, q, n;

struct mx {
  ll a[2][2];
  mx() { memset(a, 0, sizeof(a)); }
};

mx mult(mx l, mx r) {
  mx res;
  REP(i, 0, 1) REP(j, 0, 1) REP(k, 0, 1)
    res.a[i][j] += l.a[i][k] * r.a[k][j];
  return res;
}

mx pow(mx b, ll e) {
  mx res; res.a[0][0] = res.a[1][1] = 1;
  if (e == 0) return res;
  if (e == 1) return b;
  if (e & 1) return mult(b, pow(b, e-1));
  res = pow(b, e/2);
  return mult(res, res);
}

int main() {
  while (cin >> p >> q >> n) {
    if (n) {
      mx m; m.a[0][1] = 1; m.a[1][0] = -q; m.a[1][1] = p;
      m = pow(m, n-1);
      cout << 2*m.a[1][0] + p*m.a[1][1] << endl;
    } else cout << 2 << endl;
  }
}