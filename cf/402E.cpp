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

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  bitset<2000> g[n];
  REP(i, 0, n-1) REP(j, 0, n-1) { int x; cin >> x, g[i][j] = (x > 0); }
  REP(i, 0, n-1) REP(j, 0, n-1) if (g[j][i]) g[j] |= g[i];
  REP(i, 0, n-1) if (g[i].count() != n) { cout << "NO\n"; return 0; }
  cout << "YES\n";
}