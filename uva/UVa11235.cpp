#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int(i) = int(a); (i) <= int(b); (i)++)
typedef long long ll;

struct segtree {
  int i, j, n;
  int s;
  segtree *l, *r;

  segtree(int *a, int i, int j):
    i(i), j(j), n(j-i) {
    if (n == 1) s = a[i], l = r = NULL;
    else {
      int m = (i + j) >> 1;
      l = new segtree(a, i, m);
      r = new segtree(a, m, j);
      s = max(l->s, r->s);
    }
  }

  int query(int I, int J) {
    if (I <= i and j <= J) return s;
    if (J <= i or j <= I) return 0;
    return max(l->query(I, J), r->query(I, J));
  }
};

#define N 100111
int n, q, arr[N], cnt[N], str[N];
int a, b, res1, res2, res3;

int main() {
  ios_base::sync_with_stdio(0);
  while (cin >> n >> q) {
    memset(cnt, 0, sizeof(cnt));
    REP(i, 0, n-1) cin >> arr[i];
    str[0] = 0, cnt[0] = 1;
    REP(i, 1, n-1) {
      if (arr[i] == arr[i-1])
        str[i] = str[i-1];
      else str[i] = i;
      cnt[str[i]]++;
    }
    REP(i, 0, n-1) cnt[i] = cnt[str[i]];
    segtree *t = new segtree(cnt, 0, n);
    REP(i, 1, q) {
      cin >> a >> b;
      a--, b--;
      if (arr[a] == arr[b])
        cout << b - a + 1 << '\n';
      else {
        res1 = str[a] + cnt[a] - a;
        res2 = b - str[b] + 1;
        a = str[a] + cnt[a];
        b = str[b] - 1;
        if (a > b) res3 = 0;
        else res3 = t->query(a, b);
        cout << max(max(res1, res2), res3) << '\n';
      }
    }
    delete t;
  }
}