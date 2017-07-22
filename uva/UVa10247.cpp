#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int (i) = int(a); (i) <= int(b); (i)++)
#define M 1006969
typedef long long ll;

// fix k. suppose answer is a_d, num nodes is n_d.
// we partition the labels to k subtrees, then for each
// subtree there are a_(d-1) ways to label.

int c[11111][11111];
ll k, d, t1, t2, t3, n[22][22], a[22][22];

int memoc(ll n, ll k) {
  if (~c[n][k]) return c[n][k];
  if (!n || !k || n == k) return c[n][k] = 1;
  return c[n][k] = (memoc(n-1, k-1) + memoc(n-1, k)) % M;
}

ll memon(ll k, ll d) {
  if (~n[k][d]) return n[k][d];
  if (!d) return n[k][d] = 1;
  return n[k][d] = (k * memon(k, d-1) + 1) % M;
}

ll memoa(ll k, ll d) {
  if (~a[k][d]) return a[k][d];
  if (!d) return a[k][d] = 1;
  t3 = memoa(k, d-1); a[k][d] = 1;
  t1 = memon(k, d) - 1; t2 = memon(k, d-1); 
  REP(i, 0, k-1)
    a[k][d] = a[k][d] * memoc(t1-i*t2, t2) % M * t3 % M;
  return a[k][d];
}

int main() {
  memset(c, -1, sizeof(c));
  memset(n, -1, sizeof(n));
  memset(a, -1, sizeof(a));
  while (cin >> k >> d) cout << memoa(k, d) << endl;
}