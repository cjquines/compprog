#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int(i) = int(a); (i) <= int(b); (i)++)
typedef unsigned long long ll;

int t;
string n;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> t;
  REP(h, 1, t) {
    cin >> n;
    while (true) {
        auto it = adjacent_find(n.begin(), n.end(), greater<char>());
        if (it == n.end()) break;
        else {
          *it -= 1;
          for (it++; it != n.end(); it++) *it = '9';
        }
    }
    while (n[0] == '0') n = n.substr(1);
    cout << "Case #" << h << ": " << n << '\n';
  }
}