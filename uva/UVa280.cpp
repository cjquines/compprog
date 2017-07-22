#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for(int(i) = int(a); (i) <= int(b); i++)

int n, v, tmp, res;
vector<int> edges[111];
bitset<111> intree;

void dfs(int v, bool first) {
  if (!intree[v]) {
    if (!first) intree[v] = true;
    res++;
    for (auto it : edges[v]) {
      dfs(it, false);
    }
  }
}

int main() {
  while (scanf("%d", &n), n) {
    REP(i, 0, 110) vector<int>().swap(edges[i]);
    while (scanf("%d", &v), v) {
      while (scanf("%d", &tmp), tmp) {
        edges[v].push_back(tmp);
      }
    }
    scanf("%d", &tmp);
    REP(i, 1, tmp) {
      scanf("%d", &v);
      res = 0;
      intree.reset();
      dfs(v, true);
      printf("%d", n-res+1);
      REP (i, 1, n) {
        if (!intree[i]) printf(" %d", i);
      }
      printf("\n");
    }
  }
}