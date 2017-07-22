#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int(i) = int(a); (i) <= int(b); (i)++)
#define PB push_back
#define INF 0x3f3f3f3f
typedef vector<int> vi;

#define N 111
int t, n, m, a, b, c, skip, tr[N], p[N][N], ans[N];
priority_queue<tuple<int, int, int>> e[N];

int find(int v, int i) {
  return (!~p[i][v]) ? v : p[i][v] = find(p[i][v], i);
}

void unite(int u, int v, int i) {
  rand() % 2 ? p[i][u] = v : p[i][v] = u;
}

void mst(int i) {
  while (!e[i].empty()) {
    tie(c, a, b) = e[i].top(), e[i].pop();
    a = find(a, i), b = find(b, i);
    if (a != b) {
      if (!i) skip++, copy(p[i], p[i]+N, p[skip]),
        ans[skip] = ans[i], e[skip] = e[i], tr[skip] = tr[i];
      unite(a, b, i), ans[i] += -c, tr[i]++;
    }
  }
  if (tr[i] < n - 1) ans[i] = INF;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    memset(p, -1, sizeof(p));
    memset(tr, 0, sizeof(tr));
    skip = ans[0] = 0;
    cin >> n >> m;
    while (m--) cin >> a >> b >> c, e[0].emplace(-c, a, b);
    REP(i, 0, n - 1) mst(i);
    cout << ans[0] << ' ' << *min_element(ans+1, ans+n) << '\n';
  }
}