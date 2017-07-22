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

#define N 20111
bitset<N> tr, ind, out;
int t, n, m, x, y, cnt;
stack<int> st;
vi g[N], gr[N], sct;

void dfs_fwd(int v) {
  tr[v] = 1;
  for (auto it : g[v]) if (!tr[it]) dfs_fwd(it);
  st.push(v);
}

void dfs_bwd(int v, int c) {
  tr[v] = 0, sct[v] = c;
  for (auto it : gr[v]) if (tr[it]) dfs_bwd(it, c);
}

void scc() {
  tr.reset(), cnt = 0, vi(N).swap(sct);
  REP(i, 1, n) if (!tr[i]) dfs_fwd(i);
  while (!st.empty()) {
    if (tr[st.top()]) dfs_bwd(st.top(), ++cnt);
    st.pop();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    ind.reset(), out.reset();
    memset(g, 0, sizeof(g)), memset(gr, 0, sizeof(gr));
    cin >> n >> m;
    while (m--) cin >> x >> y, g[x].PB(y), gr[y].PB(x);
    scc();
    REP(i, 1, n) for (auto it : g[i])
      if (sct[i] != sct[it]) ind[sct[it]] = out[sct[i]] = 1;
    if (cnt == 1) cout << 0 << '\n';
    else cout << cnt - min(ind.count(), out.count()) << '\n';
  }
}