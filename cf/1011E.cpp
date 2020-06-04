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

#define N 100011
bitset<N> p;
int n, k, r, a;

int gcd(int a, int b) {
  if (a < b) return gcd(b, a);
  if (b == 0) return a;
  return gcd(b, a%b);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> k >> r;
  REP(i, 1, n-1) {
    cin >> a;
    r = gcd(r, a);
  }
  r = gcd(r, k);
  cout << k/r << '\n';
  for (int i = 0; i < k; i += r) cout << i << ' ';
  cout << endl;
}