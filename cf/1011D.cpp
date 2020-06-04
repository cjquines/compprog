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

#define N 31
int mxx, n, p[N], l, m, r, ans;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> mxx >> n;
  REP(i, 0, n-1) {
    cout << 1 << endl;
    fflush(stdout);
    cin >> p[i];
    if (p[i] == 0 || p[i] == -2) exit(0);
  }
  l = 2; r = mxx;
  REP(i, 0, 29) {
    m = (l + r)/2;
    cout << m << endl;
    fflush(stdout);
    cin >> ans;
    if (ans == 0 || ans == -2) exit(0);
    ans *= p[i%n];
    if (ans == 1) l = m+1;
    else r = m-1;
  }
  assert(1 == 2);
}