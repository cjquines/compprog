#include <bits/stdc++.h>
using namespace std;
#define STREP(i, s) for (int(i) = 0; (s)[(i)]; (i)++)
#define REP(i, a, b) for (int(i) = int(a); (i) <= int(b); (i)++)
#define ALL(c) begin(c), end(c)
#define SZ(c) int((c).size())
#define INF 0x3f3f3f3f
#define EB emplace_back
#define MP make_pair
#define PB push_back
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define N 100111
int n, m, t, a, b, w, cmp;
int low[N], dst[N], ans[N], p[N], fst[N];
vector<pair<ii, ii>> pq;
vii g[N];
vector<pair<int, ii>> now;

int find(int v) { return p[v] < 0 ? v : p[v] = find(p[v]); }
void unite(int u, int v) {
  u = find(u), v = find(v);
  if (u == v) return;
  if (p[u] > p[v]) swap(u, v);
  p[u] += p[v], p[v] = u;
}

void dfs(int v, int p) {
  dst[v] = low[v] = ++t; fst[v] = cmp;
  for (auto it : g[v]) {
    if (it.S == p) continue;
    if (fst[it.F] != cmp) {
      dfs(it.F, it.S);
      low[v] = min(low[v], low[it.F]);
    } else low[v] = min(low[v], dst[it.F]);
  }
  if (p != -1 && low[v] == dst[v])
    ans[p] = 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  memset(p, -1, sizeof(p));
  REP(i, 1, m) cin >> a >> b >> w,
    pq.EB(MP(w, i), MP(a, b));
  sort(ALL(pq));
  for (int i = 0, j; i < m; i = j) {
    for (j = i; j < m && pq[j].F.F == pq[i].F.F; j++);
    cmp++;
    //memset(dst, 0, sizeof(dst));
    //memset(low, 0, sizeof(low));
    //vector<unordered_map<int, int>>(n+1).swap(g);
    REP(k, i, j-1) {
      a = find(pq[k].S.F), b = find(pq[k].S.S);
      if (a != b) ans[pq[k].F.S] = 2;
      vii().swap(g[a]), vii().swap(g[b]);
    }
    REP(k, i, j-1) {
      a = find(pq[k].S.F), b = find(pq[k].S.S);
      if (a != b)
        g[a].EB(b, pq[k].F.S), g[b].EB(a, pq[k].F.S);
    }
    REP(k, i, j-1) {
      a = find(pq[k].S.F), b = find(pq[k].S.S);
      if (a != b) {
        if (fst[a] != cmp) dfs(a, -1);
        if (fst[b] != cmp) dfs(b, -1);
      }
    }
    REP(k, i, j-1) unite(pq[k].S.F, pq[k].S.S);
  }
  /*while (!pq.empty() && cmp != n - 1) {

    w = pq.back().F.F;
    now.EB(pq.back().F.S, pq.back().S), pq.pop_back();
    while (!pq.empty() && w == pq.back().F.F)
      now.EB(pq.back().F.S, pq.back().S), pq.pop_back();
    cout << "WEIGHT " << w << endl;
    for (auto it : now) {
      cout << it.F << ' ' << it.S.F << ' ' << it.S.S << endl;
    }
    for (auto it : now) {
      a = find(it.S.F), b = find(it.S.S);
      if (a == b) ans[it.F] = -1;
      if (g[a].find(b) == g[a].end())
        //cout << "EDGE " << it.F << ' ' << a << ' ' << b << endl,
        g[a][b] = g[b][a] = it.F;
      else g[a][b] = g[b][a] = -1;
        //cout << "remove edge " << a << ' ' << b << endl;
    }
    REP(i, 1, n) if (!dst[i]) dfs(i, -1);
    for (auto it : now) {
      if (!ans[it.F]) ans[it.F] = 2;
      unite(it.S.F, it.S.S);
    }
  }*/
  REP(i, 1, m) {
    if (ans[i] == 0) cout << "none\n";
    else if (ans[i] == 1) cout << "any\n";
    else cout << "at least one\n";
  }
}