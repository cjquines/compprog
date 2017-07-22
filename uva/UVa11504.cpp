#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int(i) = int(a); (i) <= int(b); (i)++)
#define ALL(c) c.begin(), c.end()
#define INF 0x3f3f3f3f
#define PB push_back
#define SZ(c) int((c).size())
typedef vector<int> vi;

#define N 100111
bitset<N> tr, ind;
int t, n, m, x, y, cnt;
stack<int> st;
vi g[N], gr[N], col(N);

void dfs_fwd(int v) {
  tr[v] = 1;
  for (auto it : g[v]) if (!tr[it]) dfs_fwd(it);
  st.push(v);
}

void dfs_bwd(int v, int c) {
  tr[v] = 0, col[v] = c;
  for (auto it : gr[v]) if (tr[it]) dfs_bwd(it, c);
}

void scc() {
  tr.reset(), cnt = 0; vi(N).swap(col);
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
    ind.reset();
    memset(g, 0, sizeof(g));
    memset(gr, 0, sizeof(gr));
    cin >> n >> m;
    REP(i, 1, m) cin >> x >> y, g[x].PB(y), gr[y].PB(x);
    scc();
    REP(i, 1, n) for (auto it : g[i])
      if (col[i] != col[it]) ind[col[it]] = 1;
    cout << cnt - ind.count() << '\n';
  }
}