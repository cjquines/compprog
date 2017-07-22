#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for(int(i) = int(a); (i) <= int(b); i++)
#define ALL(c) begin(c), end(c)

int main() {
  int t, x1, y1, x2, y2, rnd;
  string line;
  double ans;
  scanf("%d\n\n", &t);
  while (t--) {
    ans = 0;
    scanf("%*d%*d\n");
    while (getline(cin, line), line[0]) {
      sscanf(line.data(), "%d%d%d%d", &x1, &y1, &x2, &y2);
      ans += sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    }
    rnd = int(round(3*ans/500));
    printf("%d:%.2d\n", rnd/60, rnd%60);
    if (t) printf("\n");
  }
}