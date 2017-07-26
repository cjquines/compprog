#include <iostream>
using namespace std;

int collatz(int n) {
  int res = 1;
  while (n != 1) {
    n = (n % 2 == 0) ? n / 2 : 3 * n + 1;
    res++;
  }
  return res;
}

int main() {
  int i, j, tmp;
  while (scanf("%d %d", &i, &j) != EOF) {
    printf("%d %d ", i, j);
    if (i > j) {
      tmp = i;
      i = j;
      j = tmp;
    }
    int mx = 0;
    for (int n = i; n <= j; n++) {
      mx = (collatz(n) > mx) ? collatz(n) : mx;
    }
    printf("%d \n", mx);
  }
  return 0;
}