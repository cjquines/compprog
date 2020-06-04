#include <bits/stdc++.h>
using namespace std;
#define STREP(i, s) for (int(i) = 0; (s)[(i)]; (i)++)
#define REP(i, a, b) for (int i = int(a); (i) <= int(b); (i)++)
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

const int N = 100011;
const int LG = 17;

int n, q, s[N][LG], dp[N][LG];
int lg[N];

int main() {
  ios_base::sync_with_stdio(0);
  for (int i = 1, j = 1; i < N; i *= 2, j++) {
    lg[i] = j - 1;
    // cout << i << ' ' << j << endl;
  }

  cin >> n;
  REP(i, 1, n) cin >> s[i][0];

  REP(j, 1, LG-1) {
    REP(i, 1, n-(1 << j)+1) {
      s[i][j] = s[i][j-1] + s[i + (1 << (j - 1))][j-1];
      dp[i][j] = dp[i][j-1] + dp[i + (1 << (j - 1))][j-1];
      if (s[i][j] >= 10) {
        dp[i][j]++;
        s[i][j] -= 10;
      }
      // cout << i << ' ' << j << ' ' << s[i][j] << ' ' << dp[i][j] << '\n';
    }
  }

  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << dp[l][lg[r-l+1]] << '\n';
  }
}