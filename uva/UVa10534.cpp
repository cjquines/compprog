#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int(i) = int(a); (i) <= int(b); (i)++)
#define ALL(c) begin(c), end(c)
#define N 10011

int n, t, ans, ar[N], ra[N], pi[N], pd[N], ai[N], ad[N];

void lis(int a[], int p[]) {
  vector<int> lst{0};
  for (int i = 1; i < n; i++) {
    auto it = upper_bound(ALL(lst), a[i],
      [&](const int &l, const int &r) {
        return a[r] >= l;
      });
    if (it != lst.end()) p[i] = p[*it], *it = i;
    else p[i] = *lst.rbegin(), lst.push_back(i);
  }
}

int findi(int v) {
  if (~ai[v]) return ai[v];
  else return ai[v] = (!~pi[v]) ? 1 : findi(pi[v]) + 1;
}

int findd(int v) {
  if (~ad[v]) return ad[v];
  else return ad[v] = (!~pd[v]) ? 1 : findd(pd[v]) + 1;
}

int main() {
  while (cin >> n) {
    ans = 0;
    memset(pi, -1, sizeof(pi));
    memset(pd, -1, sizeof(pd));
    memset(ai, -1, sizeof(ai));
    memset(ad, -1, sizeof(ad));

    REP(i, 0, n-1) cin >> ar[i], ra[n-i-1] = ar[i];
    lis(ar, pi), lis(ra, pd);
    REP(i, 0, n-1) findi(i), findd(i);
    REP(i, 0, n-1) ans = max(ans, 2*min(ai[i], ad[n-i-1])-1);
    cout << ans << endl;
  }
}