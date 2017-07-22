#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int(i) = int(a); (i) <= int(b); (i)++)
#define N 100011
typedef long long ll;

// ex. dist: 3                            complexity
// indices   0  1  2  3  4  5  6  7  8    O(N)
// values    1  2  3  4  9  10 11 12 14   O(N)
// +dist     4  5  6  7  12 13 14 15 17   O(N)
// lwrbnd    4  4  4  4  8  8  9  9  9    O(N) (go l to r)
// -index-1  3  2  1  0  3  2  2  1  0    O(N)
// c2        3  1  0  0  3  1  1  0  0    O(N)
// total of last row is ans. can be memoryless :)

int n, d, x[N], sum, idx;
ll res, c2[N];

int main() {
  REP(i, 2, N-1) c2[i] = c2[i-1]+i-1;
  scanf("%d %d", &n, &d);
  REP(i, 0, n-1) scanf("%d", &x[i]);
  REP(i, 0, n-1) {
    sum = x[i] + d;
    while (x[idx] <= sum && idx < n) idx++;
    res += c2[idx-i-1];
  }
  printf("%I64d\n", res);
}