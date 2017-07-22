#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for(int(i) = int(a); (i) <= int(b); (i)++)
#define ALL(c) begin(c), end(c)
#define F first
#define S second
#define EB emplace_back
#define INF 0x3f3f3f3f
#define N 1011
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

bitset<N> tr;
int n, m, a, b, d, v;
queue<int> bfs;
priority_queue<ii> q;
vi dist, ans;
vii g[N];

int memo(int v) {
  if (~ans[v]) return ans[v];
  int res = 0;
  for (auto it : g[v]) if (dist[it.F] > dist[v]) res += memo(it.F);
  return ans[v] = res; 
}

int main() {
  ios_base::sync_with_stdio(0);
  while (cin >> n >> m) {
    memset(g, 0, sizeof(g)); tr.reset();
    vi(N, INF).swap(dist); vi(N, -1).swap(ans);
    REP(i, 1, m) cin >> a >> b >> d, g[a].EB(b, d), g[b].EB(a, d);
    dist[2] = 0; q.emplace(0, 2);
    while (!q.empty()) {
      d = -q.top().F; v = q.top().S; q.pop();
      if (d == dist[v]) for (auto it : g[v]) if (dist[v]+it.S < dist[it.F])
        dist[it.F] = dist[v]+it.S, q.emplace(-dist[it.F], it.F);
    }
    ans[1] = 1;
    cout << memo(2) << '\n';
  }
}