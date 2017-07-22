#include <bits/stdc++.h>
using namespace std;

int main() {
  set<pair<string, string>> leaves;
  string species, color;
  int n;
  cin >> n;
  while (n--) {
    cin >> species >> color;
    leaves.emplace(species, color);
  }
  cout << leaves.size();
}