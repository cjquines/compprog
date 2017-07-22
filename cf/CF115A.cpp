#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for(int(i) = int(a); (i) <= int(b); i++)
#define ALL(c) begin(c), end(c)

int n, t, p[2111], d[2111];

int find(int i) {
  return (p[i] > 0) ? find(p[i])+1 : 0;
}

int main() {
  cin >> n;
  REP(i, 1, n) cin >> t, p[i] = t;
  REP(i, 1, n) d[i] = find(i);
  cout << *max_element(ALL(d))+1 << '\n';
}