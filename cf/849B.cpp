#include <bits/stdc++.h>
using namespace std;
#define STREP(i, s) for (int(i) = 0; (s)[(i)]; (i)++)
#define REP(i, a, b) for (int(i) = int(a); (i) <= int(b); (i)++)
#define ALL(c) begin(c), end(c)
#define SIZE(c) int((c).size())
#define INF 0x3f3f
#define EB emplace_back
#define PB push_back
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

ll n, y[1002], a1, a2, a3;
ll p1, q1, p2, q2;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  REP(i, 1, n) cin >> y[i];
  // check if first three collinear
  if (y[2] - y[1] == y[3] - y[2]) {
    // continue reading points until non-line is found
    a1 = 2;
    a2 = 3;
    while (++a2 <= n)
      if (y[2] - y[1] != y[a2] - y[a2-1]) break;
    if (a2 > n) {
      cout << "No\n";
      return 0;
    }
  } else if (n == 3) {
    cout << "Yes\n";
    return 0;
  } else {
    // does fourth point lie on a1a2 or a1a3?
    if (y[4] - y[2] == 2*(y[2] - y[1])) a1 = 2, a2 = 3;
    else if (2*(y[4] - y[3]) == y[3] - y[1]) a1 = 3, a2 = 2;
    else if (y[4] - y[3] == y[2] - y[1]) a1 = 2, a2 = 3, a3 = 4;
    else if (y[4] - y[2] == y[3] - y[1]) a1 = 3, a2 = 2, a3 = 4;
    else {
      cout << "No\n";
      return 0;
    }
  }
  REP(i, a2+1, n) {
    if ((a1-1)*(y[i] - y[1]) != (i-1)*(y[a1] - y[1])) {
      if (a3 != 0 &&
        (a3-a2)*(y[i] - y[a2]) != (i-a2)*(y[a3] - y[a2])) {
        cout << "No\n";
        return 0;
      } else a3 = i;
    }
  }
  cout << "Yes\n";
}