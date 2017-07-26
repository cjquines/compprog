#include <iostream>
using namespace std;

int main() {
  int H, U, D, F, day;
  float height, up, fatigue;
  while (true) {
    scanf("%d %d %d %d", &H, &U, &D, &F);
    if (H == 0) break;
    day = 1;
    height = 0.0;
    up = U + 0.0;
    fatigue = (F * U) / 100.0;
    // printf("%f %f %f\n", height, up, fatigue);
    while (true) {
      // printf("day %d : ", day);
      height += up;
      // printf("%f %f %f \n", height, up, fatigue);
      if (height > H) break;
      if (height < 0) break;
      height -= D;
      // printf("%f %f %f \n", height, up, fatigue);
      if (height < 0) break;
      up -= fatigue;
      // printf("%f %f %f \n", height, up, fatigue);
      day++;
    }
    if (height > H) {
      printf("success on day %d\n", day);
    } else if (height < 0) {
      printf("failure on day %d\n", day);
    }
  }
}