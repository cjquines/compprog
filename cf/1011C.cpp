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

#define N 1011
int n, m, a[N], b[N];
double rep;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  REP(i, 1, n) cin >> a[i];
  REP(i, 1, n) cin >> b[i];
  REP(i, 1, n) if ((a[i] <= 1) || (b[i] <= 1)) {
    cout << -1 << endl;
    return 0;
  }
  rep = m;
  REP(i, 1, n) {
    rep += rep/(a[i] - 1);
    rep += rep/(b[i] - 1);
  }
  cout << setprecision(10) << (rep - m) << endl;
}