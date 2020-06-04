#include <bits/stdc++.h>
using namespace std;
#define STREP(i, s) for (int(i) = 0; (s)[(i)]; (i)++)
#define REP(i, a, b) for (int(i) = int(a); (i) <= int(b); (i)++)
#define ALL(c) begin(c), end(c)
#define SIZE(c) int((c).size())
#define INF 0x3f3f
#define EB emplace_back
#define PB push_back
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define N 200011
bitset<N> t;
int n, m, k, x, y;
int ptr, cnt, mx;
vi g[N], res[N];

void add(int v) {
  res[ptr].PB(v); cnt++;
  if (cnt == mx) ptr++, cnt = 0;
}

void dfs(int v) {
  add(v), t[v] = 1;
  for (auto u : g[v]) if (!t[u]) dfs(u), add(v);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> k;
  mx = 2*n/k + (2*n%k != 0);
  while (m--) cin >> x >> y, g[x].PB(y), g[y].PB(x);
  dfs(1);
  REP(i, 0, ptr-1) {
    cout << mx;
    for (auto v : res[i]) cout << ' ' << v;
    cout << '\n';
  }
  if (cnt) {
    cout << cnt;
    for (auto v : res[ptr]) cout << ' ' << v;
    cout << '\n';
  } else ptr--;
  while (++ptr < k) cout << "1 1\n";
}