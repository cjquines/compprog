#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int(i) = int(a); (i) <= int(b); (i)++)
#define INF 0x3f3f3f3f
typedef pair<int, int> ii;

struct segtree {
  int i, j, n, s1, s2;
  segtree *l, *r;

  segtree(int *a, int i, int j):
    i(i), j(j), n(j-i) {
    if (n == 1) s1 = s2 = a[i], l = r = NULL;
    else {
      int m = (i + j) >> 1;
      l = new segtree(a, i, m);
      r = new segtree(a, m, j);
      pull();
    }
  }

  void pull() {
    s1 = max(l->s1, r->s1);
    s2 = min(l->s2, r->s2);
  }

  void set(int I, int J, int v) {
    if (I <= i and j <= J) s1 = s2 = v;
    else if (!(J <= i or j <= I))
      l->set(I, J, v), r->set(I, J, v), pull();
  }

  int query1(int I, int J) {
    if (I <= i and j <= J) return s1;
    if (J <= i or j <= I) return 0;
    return max(l->query1(I, J), r->query1(I, J));
  }

  int query2(int I, int J) {
    if (I <= i and j <= J) return s2;
    if (J <= i or j <= I) return INF;
    return min(l->query2(I, J), r->query2(I, J));
  }
};

#define N 511
char c;
int n, a[N][N], q, xx1, yy1, xx2, yy2, v, res1, res2;
segtree* tr[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  REP(i, 0, n-1) REP(j, 0, n-1) cin >> a[i][j];
  REP(i, 0, n-1) tr[i] = new segtree(a[i], 0, n);
  cin >> q;
  while (q--) {
    cin >> c;
    if (c == 'q') {
      cin >> xx1 >> yy1 >> xx2 >> yy2;
      res1 = 0, res2 = INF;
      REP(i, xx1-1, xx2-1)
        res1 = max(res1, tr[i]->query1(yy1-1, yy2)),
        res2 = min(res2, tr[i]->query2(yy1-1, yy2));
      cout << res1 << ' ' << res2 << '\n';
    } else {
      cin >> xx1 >> yy1 >> v;
      tr[xx1-1]->set(yy1-1, yy1, v);
    }
  }
}