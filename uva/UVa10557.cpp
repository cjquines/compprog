#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int(i) = int(a); (i) <= int(b); (i)++)
#define EB emplace_back

#define N 111
bool cyc;
bitset<N> tr;
int n, r, t, w[N], d[N], na, nb, nw;
vector<int> g[N], rx;
vector<tuple<int, int, int>> e;

void dfs(int v) {
  tr[v] = 1;
  for (auto it : g[v]) if (!tr[it]) dfs(it);
}

int main() {
  ios_base::sync_with_stdio(0);
  while (cin >> n, ~n) {
    memset(d, -63, sizeof(d));
    memset(g, 0, sizeof(g));
    vector<tuple<int, int, int>>().swap(e);
    REP(i, 1, n) {
      cin >> w[i] >> r;
      while (r--) cin >> t, g[i].EB(t);
    }
    REP(i, 1, n) for (auto it : g[i]) e.EB(i, it, w[it]);
    d[1] = 100, dfs(1), cyc = false;
    REP(i, 1, n) {
      vector<int>().swap(rx);
      for (auto it : e) {
        tie(na, nb, nw) = it;
        if (d[na] > 0 && d[nb] < d[na] + nw)
          d[nb] = d[na] + nw, rx.EB(na);
      }
      if (!rx.size()) break;
      if (i == n) for (auto it : rx)
        tr.reset(), dfs(it), cyc |= tr[n];
    }
    if (d[n] > 0 || cyc) cout << "winnable\n";
    else cout << "hopeless\n";
  }
}