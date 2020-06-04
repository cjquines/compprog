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

ll n, res, f, p;

int main() {
  ios_base::sync_with_stdio(0);
  while (cin >> n) {
    if (n <= 5) {
      if (n == 2) cout << 1 << endl;
      if (n == 3) cout << 3 << endl;
      if (n == 4) cout << 6 << endl;
      if (n == 5) cout << 1 << endl;
      continue;
    }
    f = 5;
    p = 1;
    for (; n >= f; f *= 10, p *= 10);
    f /= 10;
    //cout << f << ' ' << p << endl;
    // 1 until n % p has ceil(n/p)
    // 0 and the rest have floor(n/p)
    if (n % p < f) {
      res = (n/p + 1)*(n/p)*(n%p);
      res += (n/p)*(n/p)*(f - (n%p));
      cout << res << endl;
    } else if (n % p != p-1) {
      res = (n/p + 1)*(n/p + 1)*((n%p)-f+1);
      res += (n/p + 1)*(n/p)*(2*f-(n%p)-2);
      res += (n/p)*(n/p);
      cout << res << endl;
    } else {
      res = (n/p + 1)*(n/p + 1)*((n%p)-f);
      res += (n/p + 1)*(n/p)*(2*f-(n%p));
      cout << res << endl;
    }
  }
}