#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int(i) = int(a); (i) <= int(b); (i)++)
#define PB push_back
#define INF 0x3f3f3f3f
typedef vector<int> vi;

#define N 10001
int t, n, kn, tmp, res;
priority_queue<tuple<int, int, int>> e;
vi k, p;

int find(int v) { return (!~p[v]) ? v : p[v] = find(p[v]); }

bool unite(int u, int v) {
  u = find(u), v = find(v);
  if (u != v) rand() % 2 ? p[u] = v : p[v] = u;
  return (u != v);
}

int dist(int v, int s) {
  string vs = to_string(v), ss = to_string(s);
  vs = string(4 - vs.length(), '0') + vs;
  ss = string(4 - ss.length(), '0') + ss;
  int res = 0;
  REP(i, 0, 3) res += min(abs(vs[i] - ss[i]), 10-abs(vs[i] - ss[i]));
  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    vi().swap(k), vi(N, -1).swap(p);
    res = 0; tmp = INF;
    cin >> n;
    while (n--) {
      cin >> kn;
      for (auto it : k) e.emplace(-dist(kn, it), kn, it);
      k.PB(kn); 
    }
    while (!e.empty()) {
      int w, a, b;
      tie(w, a, b) = e.top(), e.pop();
      if (unite(a, b)) res += -w;
    }
    for (auto it : k) tmp = min(tmp, dist(it, 0));
    cout << res + tmp << '\n';
  }
}