// complexity: O(n^2)
// there are at most (2nCn)/(n+1) ids to check

#include <bits/stdc++.h>
using namespace std;

struct state {
  string id;
  stack<char> cur;
  queue<char> rm1, rm2;
  state () { }
  state (const state* s): id(s->id), cur(s->cur),
    rm1(s->rm1), rm2(s->rm2) { }
};

void dfs(state* s) {
  if (!s->rm1.empty()) {
    state* n = new state(s);
    n->cur.push(n->rm1.front());
    n->rm1.pop();
    n->id.append("i ");
    dfs(n);
  }
  if (!s->rm2.empty() && !s->cur.empty()) {
    if (s->rm2.front() == s->cur.top()) {
      state* n = new state(s);
      n->rm2.pop();
      n->cur.pop();
      n->id.append("o ");
      dfs(n);
    }
  }
  if (s->rm1.empty() && s->rm2.empty()) {
    s->id.pop_back();
    cout << s->id << '\n';
  }
  delete(s);
}

int main() {
  string source, target;
  while (cin >> source >> target) {
    state* initial = new state();
    for (auto it : source) initial->rm1.push(it);
    for (auto it : target) initial->rm2.push(it);
    cout << "[\n";
    dfs(initial);
    cout << "]\n";
  }
}