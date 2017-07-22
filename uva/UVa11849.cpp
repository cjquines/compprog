#include <bits/stdc++.h>
using namespace std;
#define ALL(c) begin(c), end(c)

int main() {
  vector<int> cds;
  int n, m, t;
  while (scanf("%d %d", &n, &m)) {
    vector<int>().swap(cds);
    t = n + m;
    if (!t) break;
    while (t--) {
      scanf("%d", &n);
      cds.push_back(n);
    }
    sort(ALL(cds));
    printf("%d\n", distance(unique(ALL(cds)), end(cds)));
  }
}