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

#define N 101
int n, m, f, a[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  REP(i, 0, m-1) {
    cin >> f;
    a[f]++;
  }
  REP(ans, 1, 101) {
    int acc = 0;
    REP(i, 1, 100) acc += a[i]/ans;
    if (acc < n) {
      cout << ans-1 << endl;
      return 0;
    }
  }
}