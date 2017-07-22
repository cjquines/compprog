#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int(i) = int(a); (i) <= int(b); (i)++)
#define PB push_back
#define INF 0x3f3f3f3f
typedef vector<int> vi;

#define N 10011
int t, n, m, a, x, y, c, tmp, res, na;
priority_queue<tuple<int, int, int>> e;
vi p;

int find(int v) { return (!~p[v]) ? v : p[v] = find(p[v]); }

bool unite(int u, int v) {
  u = find(u), v = find(v);
  if (u != v) rand() % 2 ? p[u] = v : p[v] = u;
  return (u != v);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> t;
  REP(i, 1, t) {
    vi(N, -1).swap(p);
    cin >> n >> m >> a;
    while (m--) cin >> x >> y >> c, e.emplace(-c, x, y);
    tmp = 0; res = n * a; na = n;
    while (!e.empty()) {
      tie(c, x, y) = e.top(), e.pop();
      if (unite(x, y)) {
        tmp += -c, n--;
        if (tmp + n*a < res) res = tmp + n*a, na = n;
      }
    }
    cout << "Case #" << i << ": " << res << ' ' << na << '\n';
  }
}