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

int n, a, b;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> a;
  REP(i, 2, n) cin >> b;
  if (n % 2 && a % 2 && b % 2)
    cout << "Yes\n";
  else cout << "No\n";
}