#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for(int(i) = int(a); (i) <= int(b); (i)++)
#define F first
#define S second
#define EB emplace_back
#define N 711
typedef pair<int, int> ii;
typedef pair<int, double> id;
typedef vector<id> vid;

bitset<N> tr;
int n, root;
double p[N][N];
ii k[N];
vid s[N];

void sp(int v, int a, int b); 

void dfs(int v) {
  if (v <= n) s[v].EB(v, 1);
  else dfs(k[v].F), dfs(k[v].S),
    sp(v, k[v].F, k[v].S), sp(v, k[v].S, k[v].F);
}

void sp(int v, int a, int b) {
  for (auto it : s[a]) {
    double tmp = 0;
    for (auto jt : s[b]) tmp += it.S * jt.S * p[it.F][jt.F];
    s[v].EB(it.F, tmp);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cout << setiosflags(ios::fixed) << setprecision(6);
  while (cin >> n, n) {
    tr.reset(); memset(s, 0, sizeof(s));
    REP(i, 1, n) REP(j, 1, n) cin >> p[i][j];
    REP(i, n+1, 2*n-1)
      cin >> k[i].F >> k[i].S, tr[k[i].F] = tr[k[i].S] = 1;
    REP(i, 1, 2*n-1) if (!tr[i]) root = i;
    dfs(root);
    for (auto it : s[root]) if (it.F == 1)
      cout << it.S << '\n';
  }
}