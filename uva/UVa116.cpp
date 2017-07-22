#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for(int(i) = int(a); (i) <= int(b); (i)++)
#define ALL(c) begin(c), end(c)
#define PB push_back

struct node { int dp; vector<int> p; };
int m, n, res;
node g[11][101];

int comp(int j, int l, int r) {
  if (g[l][j].dp == g[r][j].dp)
    return g[l][j].p < g[r][j].p ? l : r;
  return g[l][j].dp < g[r][j].dp ? l : r;
}

void upd(int i, int j, int a, int b, int c) {
  int par = comp(j-1, comp(j-1, c, b), a);
  g[i][j].dp += g[par][j-1].dp;
  g[i][j].p = g[par][j-1].p;
  g[i][j].p.PB(par);
}

int main() {
  ios_base::sync_with_stdio(0);
  while (cin >> m >> n) {
    memset(g, 0, sizeof(g));
    REP(i, 1, m) REP(j, 1, n) cin >> g[i][j].dp;
    if (m == 1) {
      cout << 1, res = g[1][1].dp;
      REP(j, 2, n) cout << ' ' << 1, res += g[1][j].dp;
      cout << '\n' << res << '\n';
      continue;
    }
    REP(j, 2, n) {
      upd(1, j, 1, 2, m); upd(m, j, 1, m-1, m);
      REP(i, 2, m-1) upd(i, j, i-1, i, i+1);
    }
    REP(i, 1, m) g[i][n].p.PB(i);
    res = 1;
    REP(i, 2, m) res = comp(n, res, i);
    cout << g[res][n].p[0];
    REP(i, 1, n-1) cout << ' ' << g[res][n].p[i];
    cout << '\n' << g[res][n].dp << '\n';
  }
}