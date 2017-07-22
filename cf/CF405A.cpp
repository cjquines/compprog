#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> cubes;
  int n, tmp;
  scanf("%d", &n);
  while (n--) scanf("%d", &tmp), cubes.push_back(tmp);
  sort(begin(cubes), end(cubes));
  for (auto it : cubes) printf("%d ", it);
}