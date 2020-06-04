#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for(int(i) = int(a); (i) <= int(b); i++)
#define ALL(c) begin(c), end(c)

int n, m;
string tmp1, tmp2;
vector<int> g[111];
vector<int> in(111);
vector<int> ans;
vector<string> b;
priority_queue<int> q;

int main() {
  cin >> n >> tmp1;
  REP(i, 2, n) {
    cin >> tmp2;
    auto diff = mismatch(ALL(tmp1), tmp2.begin());
    if (diff.second == tmp2.end()) {
      cout << "Impossible\n";
      return 0;
    } else if (diff.first != tmp1.end()) {
      g[(*diff.first)-'a'].push_back((*diff.second)-'a');
      in[(*diff.second)-'a']++;
    }
    tmp1 = tmp2;
  }
  REP(i, 0, 25) if (!in[i]) q.push(-i);
  while (!q.empty()) {
    m = -q.top(), q.pop();
    ans.push_back(m);
    for (auto it : g[m]) {
      in[it]--;
      if (!in[it]) q.push(-it);
    }
    vector<int>().swap(g[m]);
  }
  if (ans.size() < 26) {
    cout << "Impossible\n";
  } else {
    for (auto it : ans) {
      cout << char(it+'a');
    }
    cout << '\n';
  }
}