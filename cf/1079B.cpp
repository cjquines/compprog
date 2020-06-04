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

string s;
int n;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> s;
  n = s.size();
  int r = n/20 + (n % 20 != 0);
  int c = n/r + (n % r != 0);
  int rem = r*c - n;
  int q = rem / r;
  int a = 0;
  // cout << rem << ' ' << q << endl;
  cout << r << ' ' << c << '\n';
  REP(i, 0, r - 1) {
    if (r-1 - i < (rem % r)) {
      REP(j, 1, c - q - 1) cout << s[a++];
      REP(j, 1, q + 1) cout << '*';
    } else {
      REP(j, 1, c - q) cout << s[a++];
      REP(j, 1, q) cout << '*';
    }
    cout << '\n';
  }
}