#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for(int(i) = int(a); (i) <= int(b); (i)++)
#define PB push_back
#define INF 0x3f3f3f3f
#define N 10011
#define C 11

bitset<N> par;
int n, v, root, ans, dp[N][C];
string line;
vector<int> ch[N];

int memo(int v, int c) {
  if (~dp[v][c]) return dp[v][c];
  dp[v][c] = c;
  for (auto it : ch[v]) {
    int mnm = INF;
    REP(i, 1, C-1) if (i != c) mnm = min(mnm, memo(it, i));
    dp[v][c] += mnm;
  }
  return dp[v][c];
}

int main() {
  ios_base::sync_with_stdio(0);
  while (cin >> n, n) {
    par.reset();
    memset(ch, 0, sizeof(ch));
    memset(dp, -1, sizeof(dp));
    REP(i, 0, n-1) {
      cin >> line;
      getline(cin, line);
      istringstream iss(line);
      while (iss >> v) ch[i].PB(v), par[v] = 1;
    }
    REP(i, 0, n-1) if (!par[i]) root = i;
    ans = INF;
    REP(i, 1, C-1) ans = min(ans, memo(root, i));
    cout << ans << '\n';
  }
}