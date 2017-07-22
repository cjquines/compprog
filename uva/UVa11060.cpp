#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for(int(i) = int(a); (i) <= int(b); i++)
#define ALL(c) begin(c), end(c)

int n, m, c = 1;
string tmp1, tmp2;
vector<int> g[111];
vector<int> in(111);
vector<int> ans;
vector<string> b;
priority_queue<int> q;

int main() {
  while (cin >> n) {
    vector<int>().swap(ans);
    vector<string>().swap(b);
    REP(i, 1, n) cin >> tmp1, b.push_back(tmp1);
    cin >> m;
    REP(i, 1, m) {
      cin >> tmp1 >> tmp2;
      auto t = find(ALL(b), tmp2) - begin(b);
      g[find(ALL(b), tmp1) - begin(b)].push_back(t);
      in[t]++;
    }
    REP(i, 0, n-1) if (!in[i]) q.push(-i);
    while (!q.empty()) {
      m = -q.top(), q.pop();
      ans.push_back(m);
      for (auto it : g[m]) {
        in[it]--;
        if (!in[it]) q.push(-it);
      }
      vector<int>().swap(g[m]);
    }
    cout << "Case #" << c << ": Dilbert should drink beverages in this order:";
    for (auto it : ans) {
      cout << " " << b[it];
    }
    cout << ".\n\n";
    c++;
  }
}