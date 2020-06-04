#include <bits/stdc++.h>
using namespace std;
#define STREP(i, s) for (int(i) = 0; (s)[(i)]; (i)++)
#define REP(i, a, b) for (int(i) = int(a); (i) <= int(b); (i)++)
#define ALL(c) begin(c), end(c)
#define SIZE(c) int((c).size())
#define INF 0x3f3f3f3f
#define EB emplace_back
#define MP make_pair
#define PB push_back
#define F first
#define S second

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef long long ll;
// why am i even programming
// what is the point of all this

struct Edge {
  int u, v;
  ll cap, flow;
  Edge() {}
  Edge(int u, int v, ll cap): u(u), v(v), cap(cap), flow(0) {}
};

struct Dinic {
  int N;
  vector<Edge> E;
  vector<vi> g;
  vi d, pt;

  Dinic(int N): N(N), E(0), g(N), d(N), pt(N) {}

  void AddEdge(int u, int v, ll cap) {
    if (u != v) {
      E.EB(Edge(u, v, cap));
      g[u].EB(E.size() - 1);
      E.EB(Edge(v, u, 0));
      g[v].EB(E.size() - 1);
    }
  }

  bool BFS(int S, int T) {
    queue<int> q ({S});
    fill(d.begin(), d.end(), N + 1);
    d[S] = 0;
    while (!q.empty()) {
      int u = q.front(); q.pop();
      if (u == T) break;
      for (int k : g[u]) {
        Edge &e = E[k];
        if (e.flow < e.cap && d[e.v] > d[e.u] + 1) {
          d[e.v] = d[e.u] + 1;
          q.emplace(e.v);
        }
      }
    }
    return d[T] != N + 1;
  }

  ll DFS(int u, int T, ll flow = -1) {
    if (u == T || flow == 0) return flow;
    for (int &i = pt[u]; i < SIZE(g[u]); ++i) {
      Edge &e = E[g[u][i]];
      Edge &oe = E[g[u][i]^1];
      if (d[e.v] == d[e.u] + 1) {
        ll amt = e.cap - e.flow;
        if (flow != -1 && amt > flow) amt = flow;
        if (ll pushed = DFS(e.v, T, amt)) {
          e.flow += pushed;
          oe.flow -= pushed;
          return pushed;
        }
      }
    }
    return 0;
  }

  ll MaxFlow(int S, int T) {
    ll total = 0;
    while (BFS(S, T)) {
      fill(pt.begin(), pt.end(), 0);
      while (ll flow = DFS(S, T))
        total += flow;
    }
    return total;
  }
};

#define LAST 11111111
bitset<1110000> poss;
int t, n, p, g[55][55], rcp[55], li;
vector<int> posn[55][1110000];
map<tuple<int, int, int>, int> m;

int ind(int r, int c, int n) {
  auto tup = make_tuple(r, c, n);
  auto s = m.find(tup);
  if (s == m.end()) {
    li++;
    m[tup] = li;
    return li;
  }
  return s->S;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  REP(t1, 1, t) {
    cin >> n >> p;
    //cout << "WORK-1" << endl;
    poss.reset();
    memset(posn, 0, sizeof(posn));
    li = 0;
    m.clear();
    Dinic dinic(LAST+1);
    //cout << "WORK0" << endl;
    REP(i, 1, n) cin >> rcp[i];
    REP(i, 1, n) REP(j, 1, p) cin >> g[i][j];
    //cout << "WORK1" << endl;
    REP(j, 1, p) dinic.AddEdge(0, ind(1, j, 0), 1);
    REP(i, 1, n) REP(j, 1, p) {
      int la = floor(g[i][j] / (rcp[i] * 0.9));
      int sm = ceil(g[i][j] / (rcp[i] * 1.1));
      REP(k, sm, la) posn[i][k].PB(j), poss[k] = 1;
      //cout << i << ' ' << j << ' ' << k << endl;
    }
    REP(k, 1, 100011) if (poss[k]) {
      for (auto it : posn[1][k])
        dinic.AddEdge(ind(1, it, 0), ind(1, it, k), 1);
      REP(i, 1, n-1) for (auto it : posn[i][k]) for (auto jt : posn[i+1][k])
        dinic.AddEdge(ind(i, it, k), ind(i+1, jt, k), 1);
      for (auto it : posn[n][k])
        dinic.AddEdge(ind(n, it, k), LAST, 1);
    }
    cout << "Case #" << t1 << ": " << dinic.MaxFlow(0, LAST) << endl;
  }
}