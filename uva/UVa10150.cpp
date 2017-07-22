#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int(i) = int(a); (i) <= int(b); i++)
#define ALL(c) begin(c), end(c)

bool flag = false;
int s1, t1, p[26000];
string s, t;
vector<string> dict[17];
vector<int> g[17][26000];
queue<int> q;

bool dist(string s, string t) {
  int count = 0;
  for (int i = 0; s[i]; i++) {
    if (s[i] != t[i]) {
      count++;
      if (count > 1) return false;
    }
  }
  return count == 1;
}

void build() {
  REP(i, 1, 16)
  REP(j, 0, dict[i].size()-1)
  REP(k, 0, dict[i].size()-1) {
    if (j == k) continue;
    else if (dist(dict[i][j], dict[i][k])) {
      g[i][j].push_back(k);
    }
  }
}

void bfs(int i, int j, int len) {
  memset(p, -1, sizeof(p));
  queue<int>().swap(q);
  q.push(i), p[i] = -2;
  while (!q.empty()) {
    i = q.front(), q.pop();
    if (i == j) break;
    for (auto it : g[len][i]) {
      if (p[it] == -1) p[it] = i, q.push(it);
    }
  }
  if (p[j] == -1) {
    cout << "No solution.\n";
  } else {
    while (j != -2) {
      cout << dict[len][j] << '\n';
      j = p[j];
    }
  }
}

int main() {
  while (getline(cin, s), s[0]) {
    dict[s.size()].push_back(s);
  }
  build();
  while (cin >> s >> t) {
    if (flag) cout << '\n';
    flag = true;
    s1 = s.size();
    t1 = t.size();
    if (s1 != t1) {
      cout << "No solution.\n";
      continue;
    }
    auto si = find(ALL(dict[s1]), s);
    auto ti = find(ALL(dict[t1]), t);
    if (si == dict[s1].end() || ti == dict[t1].end()) {
      cout << "No solution.\n";
      continue;
    } 
    bfs(ti - dict[t1].begin(), si - dict[s1].begin(), s1);
  }
}