#include <bits/stdc++.h>
using namespace std;

int main() {
  string temp;
  while (cin >> temp, temp[0] != '#') {
    if (next_permutation(begin(temp), end(temp))) {
      cout << temp << '\n';
    } else cout << "No Successor\n";
  }
}