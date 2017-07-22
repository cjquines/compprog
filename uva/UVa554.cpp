#include <bits/stdc++.h>
using namespace std;
#define STREP(i, s) for (int(i) = 0; (s)[(i)]; (i)++)
#define REP(i, a, b) for (int(i) = (a); (i) <= int(b); (i)++)
#define ALL(c) begin(c), end(c)

char alpha[] = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char shift[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
char convert[111];

int main() {
  char temp[256], cipher[256], ans[256], word[256];
  int best = -1, matches, len, printed = 0;
  vector<string> words;

  STREP(i, alpha) {
    convert[alpha[i]] = shift[i];
  }

  while (true) {
    gets(temp);
    if (temp[0] == '#') {
      break;
    }
    words.push_back(temp);
  }

  gets(cipher);
  REP(i, 0, 26) {
    stringstream ss(cipher);
    matches = 0;
    while (ss >> word) {
      if (find(ALL(words), word) != end(words)) {
        matches++;
      }
    }
    if (matches > best) {
      strcpy(ans, cipher);
      best = matches;
    }
    STREP(j, cipher) {
      cipher[j] = convert[cipher[j]];
    }
  }

  stringstream ss(ans);
  while (ss >> word) {
    len = strlen(word);
    if (printed == 0) {
      cout << word;
      printed = len;
    } else if (printed + 1 + len <= 60) {
      cout << " " << word;
      printed += 1 + len;
    } else {
      cout << endl << word;
      printed = len;
    }
  }
  cout << endl;
} 