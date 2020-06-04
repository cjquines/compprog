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

ll n, at, bt;
vi a, b;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  PER(i, n, 1) {
    if (at < bt) at += i, a.EB(i);
    else bt += i, b.EB(i);
  }
  if (at < bt) cout << bt - at << '\n';
  else cout << at - bt << '\n';
  cout << SIZE(a) << ' ';
  for (auto i : a) {
    cout << i << ' ';
  }
  cout << '\n';
}