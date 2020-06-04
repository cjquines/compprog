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

#define N 51
ll dp[N][N][N], n, k, m;

ll bc(int n, int k, int m) {
  if (!k) return 1;
  if (!~dp[n][k][m]) return dp[n][k][m];
  
}

int main() {
  ios_base::sync_with_stdio(0);
  memset(dp, -1, sizeof(dp));

  while (cin >> n) {
    cin >> k >> m;

  }
}