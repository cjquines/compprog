// again, sorry, but i really do need to practice union-find

#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for(int(i) = int(a); (i) <= int(b); i++)

int m, n, ans;
char tile;
int b[111][111];
int p[10011];
int dx[4] = {-1, -1, -1, 0};
int dy[4] = {1, 0, -1, -1};

int find(int v) {
  return (p[v] >= 0) ? p[v] = find(p[v]) : v;
}

void unite(int v, int s) {
  v = find(v), s = find(s);
  if (v != s) {
    if (p[v] == p[s]) p[v]--;
    if (p[v] > p[s]) p[v] = s;
    else p[s] = v;
    ans--;
  }
}

int main() {
  while (scanf("%d %d", &m, &n), m) {
    memset(b, 0, sizeof(b));
    memset(p, -1, sizeof(p));
    ans = 0;
    REP(i, 0, m-1) REP(j, 0, n-1) {
      scanf("%1s", &tile);
      if (tile == '@') {
        b[i][j] = 1;
        ans++;
        REP(k, 0, 3) {
          int x = i + dx[k];
          int y = j + dy[k];
          if (0 <= x && x < m && 0 <= y && y < n) {
            if (b[x][y]) unite(i*n + j, x*n + y);
          }
        }
      }
    }
    printf("%d\n", ans);
  }
}