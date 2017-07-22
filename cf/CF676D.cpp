#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int(i) = int(a); (i) <= int(b); (i)++)
#define PB push_back

// another undirected unweighted graph
// sssp => BFS
// wait, i haven't even used dijkstra yet this week

#define N 1001111
#define IND(i, j) 1001*i + j
typedef bitset<4> rt;

char t;
int d[4][4] = {
  {-1001, 1, 1001, -1}, // TRBL
  {1, 1001, -1, -1001},
  {1001, -1, -1001, 1},
  {-1, -1001, 1, 1001}
};
int n, m, a, b, s, e, dp[N][4];
queue<pair<int, int>> q;
rt bd[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  memset(dp, -1, sizeof(dp));
  cin >> n >> m;
  REP(i, 0, n-1) REP(j, 0, m-1) {
    cin >> t;
    if (t == '+') bd[IND(i, j)] = rt("1111");
    else if (t == '-') bd[IND(i, j)] = rt("1010");
    else if (t == '|') bd[IND(i, j)] = rt("0101");
    else if (t == '^') bd[IND(i, j)] = rt("0001");
    else if (t == '>') bd[IND(i, j)] = rt("0010");
    else if (t == '<') bd[IND(i, j)] = rt("1000");
    else if (t == 'v') bd[IND(i, j)] = rt("0100");
    else if (t == 'L') bd[IND(i, j)] = rt("0111");
    else if (t == 'R') bd[IND(i, j)] = rt("1101");
    else if (t == 'U') bd[IND(i, j)] = rt("1110");
    else if (t == 'D') bd[IND(i, j)] = rt("1011");
    //cout << IND(i, j) << ' ' << t << endl;
    //cout << bd[IND(i, j)][0] << bd[IND(i, j)][1] << bd[IND(i, j)][2] << bd[IND(i, j)][3] << endl;
  }
  cin >> a >> b, s = IND(--a, --b);
  cin >> a >> b, e = IND(--a, --b);
  q.emplace(s, 0), dp[s][0] = 0;
  while (!q.empty()) {
    tie(a, b) = q.front(), q.pop();
    //cout << a/1001 << ' ' << a%1001 << ' ' << b << ' ' << dp[a][b] << '\n';
    REP(i, 0, 3) if (bd[a][i]) {
      int v = a + d[b][i];
      if (v >= 0 && v/1001 < n && v%1001 < m)
        if (!~dp[v][b] && bd[v][(i+2)%4])
          dp[v][b] = dp[a][b] + 1, q.emplace(v, b);
          //cout << "CH " << v/1001 << ' ' << v%1001 << ' ' << b << '\n'; 
    }
    if (!~dp[a][(b+1)%4])
      dp[a][(b+1)%4] = dp[a][b] + 1, q.emplace(a, (b+1)%4);
      //cout << "CH " << a/1001 << ' ' << a%1001 << ' ' << (b+1)%4 << '\n'; 
  }
  cout << min(min(dp[e][0], dp[e][1]),
              min(dp[e][2], dp[e][3])) << '\n';
}