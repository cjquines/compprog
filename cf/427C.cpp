#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int(i) = int(a); (i) <= int(b); (i)++)
#define ALL(c) c.begin(), c.end()
#define INF 0x3f3f3f3f
#define PB push_back
#define SZ(c) int((c).size())
typedef long long ll;
typedef vector<int> vi;

#define N 100111
#define MOD 1000000007
bitset<N> tr;
int t, n, m, x, y;
ll res, ans, mnn, cnt;
stack<int> st;
vi g[N], gr[N], c(N);

void dfs_fwd(int v) {
  tr[v] = 1;
  for (auto it : g[v]) if (!tr[it]) dfs_fwd(it);
  st.push(v);
}

void dfs_bwd(int v) {
  tr[v] = 0;
  if (c[v] < mnn) mnn = c[v], cnt = 1;
  else if (c[v] == mnn) cnt++;
  for (auto it : gr[v]) if (tr[it]) dfs_bwd(it);
}

void scc() {
  tr.reset();
  REP(i, 1, n) if (!tr[i]) dfs_fwd(i);
  res = 0, ans = 1;
  while (!st.empty()) {
    if (tr[st.top()]) {
      mnn = INF, cnt = 0;
      dfs_bwd(st.top());
      res += mnn, ans = (ans * cnt) % MOD;
    }
    st.pop();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  REP(i, 1, n) cin >> c[i];
  cin >> m;
  REP(i, 1, m) cin >> x >> y, g[x].PB(y), gr[y].PB(x);
  scc();
  cout << res << ' ' << ans << '\n';
}