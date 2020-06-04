#include <bits/stdc++.h>
using namespace std;
#define STREP(i, s) for (int(i) = 0; (s)[(i)]; (i)++)
#define REP(i, a, b) for (int(i) = int(a); (i) <= int(b); (i)++)
#define PER(i, a, b) for (int(i) = int(a); (i) >= int(b); (i)--)
#define ALL(c) begin(c), end(c)
#define SIZE(c) int((c).size())
#define INF 0x3f3f3f3f
#define EB emplace_back
#define PB push_back
#define F first
#define S second

#define int ll

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define N 100011
int n, m, k, u, v, x, s, y, d[N], in[N], res;
vii g[N], trn;
priority_queue<ii> pq;

#undef int
int main() {
#define int ll
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> k;
  REP(i, 1, m) {
    cin >> u >> v >> x;
    g[u].EB(v, x); g[v].EB(u, x);
  }
  REP(i, 1, k) {
    cin >> s >> y;
    g[1].EB(s, y); g[s].EB(1, y);
    trn.EB(s, y);
  }
  memset(d, 63, sizeof(d));
  d[1] = 0; pq.push({0, 1});
  while (!pq.empty()) {
    int w = pq.top().F, v = pq.top().S; pq.pop();
    if (-w > d[v]) continue;
    for (auto u : g[v]) if (d[u.F] > d[v] + u.S) {
      d[u.F] = d[v] + u.S;
      pq.push({-d[u.F], u.F});
    }
  }
  REP(v, 1, n) for (auto u : g[v])
    if (d[u.F] == d[v] + u.S) in[u.F]++;
  for (auto u : trn) {
    if (d[u.F] != u.S) res++;
    else if (in[u.F] > 1) res++, in[u.F]--;
  }
  cout << res << endl;
}