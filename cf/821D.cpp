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

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define N 10011
#define IND(i, j) (i)*N + (j)
bitset<N> lit[N];
int n, m, k, r, c;
map<int, vii> g;
map<int, int> d;
priority_queue<ii> pq;
vii l;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void edge(int v, int u, int w) {
  cout << "EDGE " << v << ' ' << u << ' ' << w << endl;
  auto it = g.find(v);
  if (it == g.end()) it->S = vii();
  it->S.EB(u, w);
  it = g.find(u);
  if (it == g.end()) it->S = vii();
  it->S.EB(v, w);
}

int dist(int v) {
  auto it = d.find(v);
  if (it == d.end()) it->S = INF;
  return it->S;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> k;
  REP(i, 1, k) {
    cin >> r >> c;
    l.EB(r, c);
    lit[r][c] = 1;
  }
  for (auto x : l) {
    int r = x.F, c = x.S;
    REP(i, 0, 3) {
      int R = r + dx[i], C = c + dy[i];
      if (lit[R][C])
        edge(IND(r, c), IND(R, C), 0);
    }
    edge(IND(r, c), IND(r, 0), 1);
    edge(IND(r, c), IND(0, c), 1);
  }
  edge(IND(n, m), IND(n, 0), 1);
  edge(IND(n, m), IND(0, m), 1);
  REP(i, 1, n) {
    edge(IND(i, 0), IND(i+1, 0), 1);
    edge(IND(i, 0), IND(i+2, 0), 1);
  }
  REP(j, 1, m) {
    edge(IND(0, j), IND(0, j+1), 1);
    edge(IND(0, j), IND(0, j+2), 1);
  }

  d[IND(1, 1)] = 0; pq.push({0, IND(1, 1)});
  while (!pq.empty()) {
    int w = pq.top().F, v = pq.top().S; pq.pop();
    if (-w > dist(v)) continue;
    for (auto u : g[v])
      if (dist(u.F) > dist(v) + u.S) {
        d[u.F] = d[v] + u.S;
        pq.push({-d[u.F], u.F});
      }
  }
  if (dist(IND(n, m)) == INF) cout << -1 << '\n';
  else cout << dist(IND(n, m)) << '\n';
}