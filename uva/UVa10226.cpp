#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<string> trees;
  string tree;
  int t, n, c;
  scanf("%d\n\n", &t);
  while (t--) {
    n = 0;
    while (getline(cin, tree) && tree != "") {
      trees.push_back(tree);
      n++;
    }
    sort(trees.rbegin(), trees.rend());
    while (!trees.empty()) {
      c = 0;
      tree = trees.back();
      while (!trees.empty()) {
        if (tree != trees.back()) break;
        trees.pop_back();
        c++;
      }
      printf("%s %.4f\n", tree.data(), (double)c / (double)n * 100.0);
    }
    if (t) printf("\n");
  }
}