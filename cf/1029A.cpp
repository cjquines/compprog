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

int n, k, st;
string s;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> k >> s;
  st = 0;
  REP(i, 1, n-1) {
    bool flag = true;
    REP(j, 0, n-1-i) if (s[j] != s[i+j]) flag = false;
    if (flag) { st = n-i; break; }
  }
  cout << s;
  REP(i, 1, k-1) {
    REP(j, st, n-1) cout << s[j];
  }
  cout << '\n';
}