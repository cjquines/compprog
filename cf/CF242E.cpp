#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int(i) = int(a); (i) <= int(b); (i)++)
typedef long long ll;

struct segtree {
  int i, j, n, d, s;
  segtree *l, *r;

  segtree(int *a, int i, int j):
    i(i), j(j), n(j-i), d(0) {
    if (n == 1) s = a[i], l = r = NULL;
    else {
      int m = (i + j) >> 1;
      l = new segtree(a, i, m);
      r = new segtree(a, m, j);
      pull();
    }
  }

  void pull() {
    s = l->s + r->s;
  }

  void push() {
    if (d) {
      s = n-s;
      if (l) l->d ^= 1, r->d ^= 1;
      d = 0;
    }
  }

  void set(int I, int J) {
    if (I <= i and j <= J) {
      d ^= 1;
      push();
    } else {
      push();
      if (!(J <= i or j <= I)) {
        l->set(I, J);
        r->set(I, J);
        pull();
      }
    }
  }

  int query(int I, int J) {
    push();
    if (I <= i and j <= J) return s;
    if (J <= i or j <= I) return 0;
    return l->query(I, J) + r->query(I, J);
  }
};

#define N 100111
#define MXLG 22
int n, a[N], m, t, l, r, x;
int b[MXLG][N];
ll res;
segtree* tr[MXLG];

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  REP(i, 0, n-1) cin >> a[i];
  REP(i, 0, n-1) REP(j, 0, MXLG-1)
    if (a[i] & (1 << j)) b[j][i] = 1;
  REP(j, 0, MXLG-1)
    tr[j] = new segtree(b[j], 0, n);
  cin >> m;
  REP(i, 0, m-1) {
    cin >> t >> l >> r;
    if (t == 1) {
      res = 0;
      REP(j, 0, MXLG-1)
        res = 2*res + tr[MXLG-1-j]->query(l-1, r);
      cout << res << '\n';
    } else {
      cin >> x;
      REP(j, 0, MXLG-1)
        if (x & (1 << j)) tr[j]->set(l-1, r);
    }
  }
}