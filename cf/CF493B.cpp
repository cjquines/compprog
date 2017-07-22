#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> first, second;
  char last[10];
  int n, temp;
  ll fpoints = 0, spoints = 0;
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &temp);
    if (temp > 0) {
      first.PB(temp);
      fpoints += temp;
      strcpy(last, "first");
    } else {
      second.PB(-temp);
      spoints += -temp;
      strcpy(last, "second");
    }
  }
  if (fpoints > spoints) printf("first");
  else if (fpoints < spoints) printf("second");
  else if (equal(ALL(first), begin(second))) printf(last);
  else if (!LC(ALL(first), ALL(second))) printf("first");
  else printf("second");
}