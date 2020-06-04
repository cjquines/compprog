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

#define N 100011
bitset<N> b;
int x, n, ct, mx;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  n *= 2;
  while (n--) {
    cin >> x;
    if (!b[x]) b[x] = 1, ct++;
    else ct--;
    if (ct > mx) mx = ct;
  }
  cout << mx << endl;
}