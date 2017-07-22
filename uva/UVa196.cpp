#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for(int(i) = int(a); (i) <= int(b); (i)++)
#define ALL(c) begin(c), end(c)
#define PB push_back
#define N 19000000
#define INDEX(i, j) (i)*c + (j)
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

char cel[1024], ccl[5];
ll t, c, r, v, crw;
vi dp(N), in(N), tps;
vvi ch(N);
queue<ll> qu;

int main() {
  scanf("%I64d", &t);
  REP(i, 0, t-1) {
    vi(N).swap(dp); vi(N).swap(in);
    vi().swap(tps); vvi(N).swap(ch); 
    scanf("%I64d%I64d", &c, &r); // the order makes me cringe
    REP(i, 0, r-1) REP(j, 0, c-1) {
      scanf("%s ", cel);
      if (cel[0] == '=') {
        char *tok = strtok(cel, "=+");
        while (tok != NULL) {
          sscanf(tok, "%[^0-9]%I64d", ccl, &crw);
          ll tmp = 0;
          for (int i = 0; ccl[i]; i++)
            tmp *= 26, tmp += ccl[i] - 'A' + 1;
          ch[INDEX(crw-1, tmp-1)].PB(INDEX(i, j));
          in[INDEX(i, j)]++;
          tok = strtok(NULL, "=+");
        }
      } else sscanf(cel, "%I64d", &dp[INDEX(i, j)]);
    }
    REP(i, 0, r-1) REP(j, 0, c-1)
      if (!in[INDEX(i, j)]) qu.push(INDEX(i, j));
    while (!qu.empty()) {
      v = qu.front(); qu.pop(); tps.PB(v);
      for (auto it : ch[v]) {
        in[it]--;
        if (!in[it]) qu.push(it);
      }
    }
    for (auto it : tps) for (auto jt : ch[it])
      dp[jt] += dp[it];
    REP(i, 0, r-1) {
      cout << dp[INDEX(i, 0)];
      REP(j, 1, c-1) cout << ' ' << dp[INDEX(i, j)];
      cout << endl;
    }
  }
}