#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int(i) = int(a); (i) <= int(b); (i)++)
#define PB push_back
#define INF 0x3f3f3f3f

bitset<64> g, p;
char temp;
int t, m, a[2], na, dp[64][64][64][2], in[64][64][64][2];
int da[] = {-8, -1, 0, 1, 8};
vector<int> e;
queue<tuple<int, int, int, int>> q;

// forgive me, muse of good programming
#define MOVE(i, ni) REP(d, 0, 4) {\
  int (ni) = (i) + da[d];\
  if ((ni) >= 0 && (ni) <= 63) if (!g[(ni)]) {

int main() {
  scanf("%d", &t);
  while (t--) {
    g.reset(), p.reset(); vector<int>().swap(e);
    memset(dp, -1, sizeof(dp)), memset(in, 0, sizeof(in));
    na = 0;
    REP(i, 0, 63) {
      scanf("%1s", &temp);
      if (temp == 'A') a[na] = i, na++;
      else if (temp == 'P') p[i] = 1;
      else if (temp == 'M') m = i;
      if (temp == '#') g[i] = 1;
      else e.PB(i);
    }
    for (auto it : e) for (auto jt : e) for (auto kt : e) {
      if (it == jt || it == kt) {
        dp[it][jt][kt][1] = 1;
        if (!p[it]) dp[it][jt][kt][0] = 0;
      } else if (p[it]) {
        dp[it][jt][kt][0] = 1, dp[it][jt][kt][1] = 0;
      } else {
        MOVE(it, nt) in[it][jt][kt][0]++;}}
        MOVE(jt, nt) MOVE(kt, nt) in[it][jt][kt][1]++;}}}}
      }
    }
    for (auto it : e) for (auto jt : e) for (auto kt : e) {
      if (~dp[it][jt][kt][0]) q.emplace(it, jt, kt, 0);
      if (~dp[it][jt][kt][1]) q.emplace(it, jt, kt, 1);
    }
    while (!q.empty()) {
      int me, a1, a2, pl;
      tie(me, a1, a2, pl) = q.front(); q.pop();
      if (pl) MOVE(me, nm) if (dp[nm][a1][a2][0] == -1) {
        if (dp[me][a1][a2][1] == 0) {
          dp[nm][a1][a2][0] = 1, q.emplace(nm, a1, a2, 0);
        } else if (dp[me][a1][a2][1] == 1) {
          if (!--in[nm][a1][a2][0])
            dp[nm][a1][a2][0] = 0, q.emplace(nm, a1, a2, 0);
        }
      }}} else MOVE(a1, n1) MOVE(a2, n2)
        if (dp[me][a1][a2][0] == 0) {
          if (dp[me][n1][n2][1] == -1)
            dp[me][n1][n2][1] = 1, q.emplace(me, n1, n2, 1);
        } else if (dp[me][n1][n2][1] == -1) {
          if (!--in[me][n1][n2][1])
            dp[me][n1][n2][1] = 0, q.emplace(me, n1, n2, 1);
        }
      }}}}
    }
    if (dp[m][a[0]][a[1]][0] == 0) printf("You are eliminated.\n");
    else if (dp[m][a[0]][a[1]][0] == 1) printf("You can escape.\n");
    else printf("You are trapped in the Matrix.\n");
  }
}