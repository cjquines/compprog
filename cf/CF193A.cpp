#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int(i) = int(a); (i) <= int(b); (i)++)
#define ALL(c) c.begin(), c.end()
#define INF 0x3f3f3f3f
#define PB push_back
#define SZ(c) int((c).size())
typedef long long ll;
typedef vector<int> vi;

#define N 10001
#define IND(i, j) 51*(i) + (j)
char c[N][N];
int dx[] = {-1, 0}, dy[] = {0, -1};
int n, m, t, emp;
vi g[N], dst(N), low(N);

bool dfs(int v, int p) {
  dst[v] = low[v] = ++t;
  int ch = 0;
  bool ans = false, lch = false;
  for (int it : g[v]) {
    if (!dst[it]) {
      ans |= dfs(it, v);
      low[v] = min(low[v], low[it]);
      ch++;
      if (low[it] >= dst[v]) lch = true;
    } else if (it != p) {
      low[v] = min(low[v], dst[it]);
    }
  }
  if ((!~p && ch >= 2) || (~p && lch))
    ans = true;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  REP(i, 1, n) REP(j, 1, m) {
    cin >> c[i][j];
    if (c[i][j] == '#') {
      emp++;
      REP(k, 0, 1) {
        int nx = i + dx[k], ny = j + dy[k];
        if (min(nx, ny) > 0 && nx <= n && ny <= m)
          if (c[nx][ny] == '#')
            g[IND(i, j)].PB(IND(nx, ny)),
            g[IND(nx, ny)].PB(IND(i, j));
      }
    }
  }
  if (emp <= 2) {
    cout << -1 << '\n';
    return 0;
  }
  REP(i, 1, n) REP(j, 1, m) if (c[i][j] == '#') {
    if (dfs(IND(i, j), -1)) {
      cout << 1 << '\n';
    } else cout << 2 << '\n';
    return 0;
  }
}