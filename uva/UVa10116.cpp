#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for(int(i) = int(a); (i) <= int(b); i++)

int r, c, start, sr, sc, ans;
char tile;
int b[11][11];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  while (scanf("%d %d %d", &r, &c, &start), r) {
    memset(b, 0, sizeof(b));
    REP (i, 0, r-1) REP (j, 0, c-1) {
      scanf("%1s", &tile);
      if (tile == 'W') b[i][j] = -1;
      else if (tile == 'S') b[i][j] = -2;
      else if (tile == 'E') b[i][j] = -3;
      else b[i][j] = -4;
    }
    sr = 0, sc = start-1, ans = 0;
    while (true) {
      int nr = sr + dx[b[sr][sc]+4];
      int nc = sc + dy[b[sr][sc]+4];
      if (0 <= nr && nr < r && 0 <= nc && nc < c) {
        if (b[nr][nc] > 0) {
          printf("%d step(s) before a loop of %d step(s)\n",
            b[nr][nc]-1, ans-b[nr][nc]+2);
          break;
        } else {
          b[sr][sc] = ++ans;
          sr = nr, sc = nc;
        }
      } else {
        printf("%d step(s) to exit\n", ans+1);
        break;
      }
    }
  }
}