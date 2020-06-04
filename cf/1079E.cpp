#include <bits/stdc++.h>
using namespace std;
#define STREP(i, s) for (int(i) = 0; (s)[(i)]; (i)++)
#define REP(i, a, b) for (int(i) = int(a); (i) <= int(b); (i)++)
#define PER(i, a, b) for (int(i) = int(a); (i) >= int(b); (i)--)
#define ALL(c) begin(c), end(c)
#define SIZE(c) int((c).size())
#define INF 0x3f3f3f3f
#define EB emplace_back
#define PB push_back
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define N 111
#define N2 10011
int n, a[N], cnt[N], res, nck[N][N], dst;
short dp[N][N2][N];

int choose(int n, int k) {
  if (nck[n][k] != -1) return nck[n][k];
  if (n == 0 || k == 0 || k == n) return nck[n][k] = 1;
  return nck[n][k] = choose(n-1, k) + choose(n-1, k-1);
}

int main() {
  ios_base::sync_with_stdio(0);
  memset(nck, -1, sizeof(nck));
  cin >> n;
  REP(i, 1, n) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  REP(i, 1, n) {
    dp[i][a[i]][1] += 1;
  }
  REP(i, 1, n) REP(w, 0, 10000) {
    REP(j, 1, n) {
      dp[i][w][j] += dp[i-1][w][j];
      if (a[i] < w) dp[i][w][j] += dp[i-1][w - a[i]][j-1];
    }
  }
  // cout << dp[n][12][3] << endl;
  res = 1;
  REP(i, 1, 100) {
    if (cnt[i] != 0) dst++;
    REP(j, 1, cnt[i]) {
      if (dp[n][i*j][j] == choose(cnt[i], j)) {
        res = max(res, j);
      }
    }
  }
  // if there is only one distinct value
  if (dst == 1) res = max(res, n);
  if (dst == 2) res = max(res, n);
  cout << res << endl;
}