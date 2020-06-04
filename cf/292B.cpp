#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for(int(i) = int(a); (i) <= int(b); i++)
#define ALL(c) begin(c), end(c)

int n, m, a, b, bf, rf, sf;
int d[1111111];

int main() {
  scanf("%d %d", &n, &m);
  while (m--) scanf("%d %d", &a, &b), d[a]++, d[b]++;
  REP(i, 1, n) {
    if (d[i] == 0) {
      bf = rf = sf = -1;
    } else if (d[i] == 1) {
      if (bf >= 0) bf++;
      rf = -1;
    } else if (d[i] == 2) {
      if (sf >= 0) sf++;
    } else if (d[i] > 2) {
      bf = rf = -1;
      if (sf >= 0) sf++;
    }
  }
  if (bf == 2) printf("bus topology\n");
  else if (rf == 0) printf("ring topology\n");
  else if (sf == 1) printf("star topology\n");
  else printf("unknown topology\n");
}