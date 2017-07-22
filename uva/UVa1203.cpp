#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<pair<int, int>> queries;
  int q, p;
  string inst;
  while (cin >> inst, inst[0] != '#') {
    cin >> q >> p;
    queries.emplace_back(q, p);
  } 
  sort(begin(queries), end(queries));
  cin >> q;
  p = 1;
  while (q) {
    for (auto it : queries) {
      if (p % it.second == 0) {
        cout << it.first << endl;
        if (!--q) break;
      }
    }
    p++;
  }
}