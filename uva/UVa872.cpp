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

#define N 22
int t, n, ind[N];
list<int> noin;
map<char, int> dict;
string line, tok, revd[N];
vi g[N], res;

void toposort(int left) {
  if (left == 0) {
    for (auto i : res) cout << revd[i] << ' ';
    cout << '\n';
  } else {
    auto it = noin.begin();
    while (it != noin.end()) {
      int u = *it;
      auto jt = it; jt++;
      noin.erase(it);
      res.PB(u);
      for (auto v : g[u]) {
        ind[v]--;
        if (!ind[v]) noin.PB(v);
      }
      toposort(left - 1);
      for (auto v : g[u]) {
        if (!ind[v]) noin.pop_back();
        ind[v]++;
      }
      res.pop_back();
      noin.insert(jt, u);
      it = jt; it++;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> t;
  getline(cin, line);
  while (t--) {
    getline(cin, line);
    getline(cin, line);
    stringstream split(line);
    map<char, int>().swap(dict);
    memset(revd, 0, sizeof(revd));
    n = 0;
    while (split >> tok) {
      dict[tok[0]] = n; revd[n] = tok; n++;
    }
    getline(cin, line);
    stringstream(line).swap(split);
    memset(g, 0, sizeof(g));
    while (split >> tok) {
      g[dict[tok[0]]].PB(dict[tok[2]]);
      ind[dict[tok[2]]]++;
    }
    REP(i, 0, n-1) if (!ind[i]) noin.PB(i);
      cout << "NOIN HAS "; for (auto i : noin) cout << i << ' '; cout << endl;
    toposort(n);
  }
}