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

#define N 1000011
ll n;
int a[N];

int last(int n) {
  if (!(n & (n-1))) return n;
  n--;
  REP(i, 0, 4) n |= n >> (1 << i);
  return (++n) >> 1;
}

void rec(int n) {
  if (n < 0) return;
  else if (!n) a[0] = 0;
  else {
    int r = last(n), l = r-1;
    do {a[l] = r, a[r++] = l--;} while (r <= n);
    rec(l);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  cout << n*n + n << '\n';
  rec(n);
  REP(i, 0, n) cout << a[i] << ' ';
  cout << endl;
}