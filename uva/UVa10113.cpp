#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for(int (i) = int(a); (i) <= int(b); (i)++)
#define N 61
#define F first
#define S second
typedef pair<int, int> ii;

// 6 shirt = 15 sock : shirt-(15, 6)->sock
// shirt-(15, 6)->sock-(1, 2)->underwear
// therefore shirt-(15*1, 6*2)->underwear

bitset<N> t;
ii ans;
int p1, p2, v1, v2, ind;
map<string, int> dict;
string q, s1, s2;
vector<pair<int, ii>> g[N];

int gcd(int a, int b) {
  if (a < b) return gcd(b, a);
  if (b == 0) return a;
  return gcd(a%b, b);
}

ii simp(int num, int den) {
  int d = gcd(num, den);
  return ii(num/d, den/d);
}

void dfs(int v, int u, ii cnv) {
  t[v] = 1;
  if (v == u) {ans = cnv; return;}
  for (auto it : g[v]) if (!t[it.F])
    dfs(it.F, u, simp(it.S.F*cnv.F, it.S.S*cnv.S));
}

int index(string s) {
  auto it = dict.find(s);
  if (it == dict.end()) {
    ind++; return dict[s] = ind;
  } else return it->S;
}

int main() {
  while (cin >> q, q[0] != '.') {
    if (q[0] == '!') {
      cin >> p1 >> s1 >> q >> p2 >> s2;
      v1 = index(s1), v2 = index(s2);
      g[v1].emplace_back(v2, simp(p2, p1));
      g[v2].emplace_back(v1, simp(p1, p2));
    } else {
      cin >> s1 >> q >> s2;
      v1 = index(s1), v2 = index(s2);
      t.reset();
      dfs(v1, v2, {1, 1});
      if (t[v2]) {
        cout << ans.S << ' ' << s1 << " = ";
        cout << ans.F << ' ' << s2 << endl;
      } else {
        cout << "? " << s1 << " = ? " << s2 << endl;
      }
    }
  }
}