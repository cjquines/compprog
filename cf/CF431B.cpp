#include <bits/stdc++.h>
using namespace std;
#define NP next_permutation
#define REP(i, a, b) for(int(i) = int(a); i <= int(b); i++)

int main() {
  int p[] = {0, 1, 2, 3, 4};
  int g[5][5];
  int curr, ans = -1;
  REP(i, 0, 4) REP(j, 0, 4) scanf("%d", &g[i][j]);
  do {
    curr = g[p[0]][p[1]] + g[p[1]][p[0]];
    curr += g[p[1]][p[2]] + g[p[2]][p[1]];
    curr += 2*g[p[2]][p[3]] + 2*g[p[3]][p[2]];
    curr += 2*g[p[3]][p[4]] + 2*g[p[4]][p[3]];
    if (curr > ans) ans = curr;
  } while (NP(begin(p), end(p)));
  printf("%d", ans);
}