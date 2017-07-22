#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int(i) = int(a); (i) <= int(b); (i)++)
#define PB push_back

// single destination shortest paths
// on undirected unweighted graph => BFS

#define N 1001111
#define IND(i, j) 1001*i + j
bitset<N> tr;
char t;
int dx[] = {-1001, -1, 1, 1001};
int r, c, s, e, v, res, dp[N];
vector<int> br;
queue<int> q;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> r >> c;
  REP(i, 0, r-1) REP(j, 0, c-1) {
    cin >> t;
    if (t == 'T') tr[IND(i, j)] = 1;
    else if (t == 'S') s = IND(i, j);
    else if (t == 'E') e = IND(i, j);
    else REP(k, 1, t - '0') br.PB(IND(i, j));
  }
  q.push(e), dp[e] = 1;
  while (!q.empty()) {
    v = q.front(), q.pop();
    REP(i, 0, 3) {
      int s = v + dx[i];
      if (s >= 0 && s/1001 < r && s%1001 < c)
        if (!tr[s] && !dp[s])
          dp[s] = dp[v] + 1, q.push(s);
    }
  }
  for (auto it : br)
    if (dp[it] && dp[it] <= dp[s]) res++;
  cout << res << '\n';
}