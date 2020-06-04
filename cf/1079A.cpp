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

int n, k, a[101], nd = 0, res = 0;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> k;
  REP(i, 1, n) {
    int f; cin >> f; a[f]++;
  }
  REP(i, 1, 100) {
    nd = max(nd, a[i] / k + (a[i] % k != 0));
  }
  REP(i, 1, 100) {
    if (a[i] % (nd * k) != 0)
      res += nd * k - (a[i] % (nd * k));
  }
  cout << res << endl;
}