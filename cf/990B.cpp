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

const int N = 200111;
int n, k, a[N], res;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> k;
  REP(i, 0, n-1) cin >> a[i];
  sort(a, a + n);
  res = n;
  for (int i = 0, j = 0; i < n && j < n; i++) {
    while (j < n && a[i] >= a[j]) j++;
    if (j == n) break;
    if (a[j] <= a[i] + k) res--;
  }
  cout << res << endl;
}