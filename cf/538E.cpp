#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int(i) = int(a); (i) <= int(b); (i)++)
#define N 200011

int n, u, v, ffp[N], fsp[N], sfp[N], ssp[N], nlv[N];
vector<int> t[N];

void dfs1(int v) {
  if (t[v].empty()) nlv[v] = 1;
  else for (auto it = t[v].begin(); it != t[v].end(); it++) dfs1(*it), nlv[v] += nlv[*it];
}

void dfs2(int v) {
  if (!t[v].empty()) {
    ffp[v] = sfp[v] = 0, fsp[v] = 1, ssp[v] = N;
    for (auto it = t[v].begin(); it != t[v].end(); it++) {
      dfs2(*it);
      ffp[v] = max(ffp[v], nlv[v] - nlv[*it] + fsp[*it]);
      fsp[v] += ffp[*it] - 1;
      sfp[v] += ssp[*it];
      ssp[v] = min(ssp[v], sfp[*it]);
    }
  } else ffp[v] = fsp[v] = sfp[v] = ssp[v] = 1;
}

int main() {
  cin >> n;
  REP(i, 1, n-1) cin >> u >> v, t[u].push_back(v);
  dfs1(1), dfs2(1), cout << ffp[1] << ' ' << sfp[1] << endl;
}