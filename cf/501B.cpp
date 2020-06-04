#include <bits/stdc++.h>
using namespace std;
#define ALL(c) begin(c),end(c)
#define PB push_back

int main() {
  vector<string> mgaluma, mgabago;
  string luma, bago;
  int q;
  cin >> q;
  while (q--) {
    cin >> luma >> bago;
    auto it = find(ALL(mgabago), luma);
    if (it == end(mgabago)) {
      mgaluma.PB(luma);
      mgabago.PB(bago);
    } else *it = bago;
  }
  cout << mgaluma.size() << endl;
  for (int i = 0; i < mgaluma.size(); i++) {
    cout << mgaluma[i] << ' ' << mgabago[i] << endl;
  }
}