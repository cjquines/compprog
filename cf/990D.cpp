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

int n, a, b, g[1111][1111];

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> a >> b;
  if (n == 1) {
    cout << "YES\n0" << endl;
  } else if (min(a, b) > 1 || (n <= 3 && a == 1 && b == 1)) {
    cout << "NO" << endl;
  } else {
    if (a == 1 && b == 1) {
      REP(i, 1, n-1) {
        g[i][i+1] = 1;
        g[i+1][i] = 1;
      }
    } else if (b == 1) {
      REP(i, 1, n-a) {
        g[n][i] = 1;
        g[i][n] = 1;
      }
    } else {
      swap(a, b);
      REP(i, 1, n-a) {
        g[n][i] = 1;
        g[i][n] = 1;
      }
      REP(i, 1, n) REP(j, 1, n)
        if (i != j) g[i][j] ^= 1;
    }
    cout << "YES" << endl;
    REP(i, 1, n) {
      REP(j, 1, n) cout << g[i][j];
      cout << '\n';
    }
  }
}