#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int(i) = int(a); (i) <= int(b); (i)++)
#define EB emplace_back
#define INF 0x3f3f3f3f
#define F first
#define S second

// dijkstra will work here. i hope.
// I AM TIRED OF MAKING USELESS OPTIMIZATIONS

#define N 100011
int n, m, a, b, w, sz[N], d[N];
vector<int> dly[N];
vector<pair<int, int>> g[N];
priority_queue<pair<int, int>> pq;

int main() {
  memset(d, 63, sizeof(d));
  scanf("%d %d", &n, &m);
  REP(i, 1, m) scanf("%d %d %d", &a, &b, &w),
    g[a].EB(w, b), g[b].EB(w, a);
  REP(i, 1, n) {
    scanf("%d", &sz[i]);
    dly[i].resize(sz[i]);
    REP(j, 0, sz[i]-1) scanf("%d", &dly[i][j]);
  }
  d[1] = 0, pq.emplace(0, 1);
  while (!pq.empty()) {
    w = -pq.top().F;
    a = pq.top().S;
    pq.pop();
    if (w > d[a]) continue;
    if (a == n) break;
    for (int i = 0; i < sz[a]; i++)
      if (dly[a][i] == w) w++;
    for (int i = 0; i < g[a].size(); i++)
      if (d[g[a][i].S] > w + g[a][i].F)
        d[g[a][i].S] = w + g[a][i].F,
        pq.emplace(-d[g[a][i].S], g[a][i].S);
  }
  if (d[n] == INF) printf("-1\n");
  else printf("%d\n", d[n]);
}