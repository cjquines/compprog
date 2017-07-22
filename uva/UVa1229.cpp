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

#define N 111
bitset<N> tr;
int n, ind, cnt;
unordered_map<string, int> mp;
stack<int> st;
string w, s, line;
vi g[N], gr[N], sct(N), col(N);
vector<string> prn, wrd;

void dfs_fwd(int v) {
  tr[v] = 1;
  for (auto it : g[v]) if (!tr[it]) dfs_fwd(it);
  st.push(v);
}

void dfs_bwd(int v, int c) {
  tr[v] = 0, sct[v] = c, col[c]++;
  for (auto it : gr[v]) if (tr[it]) dfs_bwd(it, c);
}

void scc() {
  tr.reset(), cnt = 0;
  vi(N).swap(sct), vi(N).swap(col);
  REP(i, 1, n) if (!tr[i]) dfs_fwd(i);
  while (!st.empty()) {
    if (tr[st.top()]) dfs_bwd(st.top(), ++cnt);
    st.pop();
  }
}

void dfs(int v) {
  tr[v] = 1, prn.PB(wrd[v]);
  for (auto it : g[v]) if (!tr[it]) dfs(it);
}

int index(string s) {
  auto it = mp.find(s);
  if (it != mp.end()) return it->second;
  mp[s] = ++ind, wrd[ind] = s;
  return ind;
}

int main() {
  ios_base::sync_with_stdio(false);
  while (cin >> n, n) {
    getline(cin, line);
    ind = 0;
    memset(g, 0, sizeof(g));
    memset(gr, 0, sizeof(gr));
    unordered_map<string, int>().swap(mp);
    vector<string>().swap(prn);
    vector<string>(N).swap(wrd);
    REP(i, 1, n) {
      getline(cin, line);
      istringstream iss(line);
      iss >> w;
      while (iss >> s)
        g[index(w)].PB(index(s)),
        gr[index(s)].PB(index(w));
    }
    scc();
    REP(i, 1, n) if (col[sct[i]] > 1 && !tr[i]) dfs(i);
    sort(ALL(prn));
    cout << SZ(prn) << '\n' << *prn.begin();
    for (auto it = prn.begin() + 1; it != prn.end(); it++)
      cout << ' ' << *it;
    cout << '\n';
  }
}