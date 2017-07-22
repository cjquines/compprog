#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for(int(i) = int(a); (i) <= int(b); (i)++)
#define PB push_back
#define N 1011
#define MOD 1000000007

bitset<N> tr;
int t, n, a, b, nch[N];
long long nck[N][N], dp[N];
vector<int> ch[N];

void dfs(int v) {
  nch[v] = dp[v] = 1;
  for (auto it : ch[v])
    dfs(it), dp[v] = dp[v] * dp[it] % MOD, nch[v] += nch[it];
  int nc = nch[v] - 1;
  for (auto it : ch[v])
    dp[v] = dp[v] * nck[nc][nch[it]] % MOD, nc -= nch[it];
}

int main() {
  ios_base::sync_with_stdio(0);
  REP(i, 0, N-1) nck[i][0] = nck[i][i] = 1;
  REP(i, 1, N-1) REP(j, 1, i-1)
    nck[i][j] = (nck[i-1][j-1] + nck[i-1][j]) % MOD;
  cin >> t;
  REP(k, 1, t) {
    memset(ch, 0, sizeof(ch)), tr.reset();
    cin >> n;
    REP(i, 1, n-1)
      cin >> a >> b, ch[a].PB(b), tr[b] = 1;
    REP(i, 1, n) if (!tr[i])
      dfs(i), cout << "Case " << k << ": " << dp[i] << '\n';
  }
}