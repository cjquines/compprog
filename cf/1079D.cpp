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

ll a, b, c, x1, y1, x2, y2;
double res;

ll sgn(ll v) { return (0 < v) - (v < 0); }
double dist(double x1, double y1, double x2, double y2) {
  return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
double fx(ll y) { return double(-b*y - c)/double(a); }
double fy(ll x) { return double(-a*x - c)/double(b); }

int main() {
  ios_base::sync_with_stdio(0);
  cin >> a >> b >> c >> x1 >> y1 >> x2 >> y2;
  if (a == 0 || b == 0) {
    cout << abs(x2 - x1) + abs(y2 - y1);
  } else if (x1 == x2 || y1 == y2) {
    cout << abs(x2 - x1) + abs(y2 - y1);
  } else if (sgn(y2 - y1)*sgn(x2 - x1) != -sgn(a)*sgn(b)) {
    cout << abs(x2 - x1) + abs(y2 - y1);
  } else {
    // cout << abs(fx(y1) - x1) + dist(fx(y1), y1, fx(y2), y2) + abs(fx(y2) - x2) << endl;
    // cout << abs(fx(y1) - x1) + dist(fx(y1), y1, x2, fy(x2)) + abs(y2 - fy(x2)) << endl;
    // cout << abs(y1 - fy(x1)) + dist(x1, fy(x1), fx(y2), y2) + abs(fx(y2) - x2) << endl;
    // cout << abs(y1 - fy(x1)) + dist(x1, fy(x1), x2, fy(x2)) + abs(y2 - fy(x2)) << endl;
    cout << std::setprecision(10) << min(min(min(
      abs(fx(y1) - x1) + dist(fx(y1), y1, fx(y2), y2) + abs(fx(y2) - x2),
      abs(fx(y1) - x1) + dist(fx(y1), y1, x2, fy(x2)) + abs(y2 - fy(x2))),
  min(abs(y1 - fy(x1)) + dist(x1, fy(x1), fx(y2), y2) + abs(fx(y2) - x2),
      abs(y1 - fy(x1)) + dist(x1, fy(x1), x2, fy(x2)) + abs(y2 - fy(x2)))),
      double(abs(x2 - x1) + abs(y2 - y1)));
  }
}