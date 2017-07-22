#include <bits/stdc++.h>
using namespace std;

char qwerty[] = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./ ~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?";
char dvorak[] = "`123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg' ~!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\"";
char convert[111];
char str[1111];

int main() {
  for (int i = 0; qwerty[i]; i++) {
    convert[qwerty[i]] = dvorak[i];
  }
  while (gets(str)) {
    for (int i = 0; str[i]; i++) {
      printf("%c", convert[str[i]]);
    }
    printf("\n");
  }
  return 0;
}