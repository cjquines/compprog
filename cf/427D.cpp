#include <bits/stdc++.h>
using namespace std;
#define N 5011

string s, t;
int dpst[N][N], dpss[N][N], dptt[N][N], maxs[N], maxt[N], ans = N;

void lcs(string s, string t, int dp[N][N], bool mx, int maxd[N]) {
  for (int i = 0; s[i]; i++) for (int j = 0; t[j]; j++) {
    if (s[i] == t[j]) {
      if (i == 0 || j == 0) dp[i][j] = 1;
      else dp[i][j] = dp[i-1][j-1] + 1;
    } else dp[i][j] = 0;
    if (mx && i != j) maxd[i] = max(maxd[i], dp[i][j]);
    else if (dp[i][j] > maxs[i] && dp[i][j] > maxt[j])
      ans = min(ans, max(maxs[i], maxt[j]) + 1);
  }
}

int main() {
  cin >> s >> t;
  lcs(s, s, dpss, true, maxs);
  lcs(t, t, dptt, true, maxt);
  lcs(s, t, dpst, false, maxs);
  cout << (ans == N ? -1 : ans) << endl;
}