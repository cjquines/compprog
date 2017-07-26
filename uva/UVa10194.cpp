#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

struct team {
  char name[30];
  int points;
  int wins, ties, losses;
  int scored, against;
};

int difference(team x) {
  return x.scored - x.against;
}

int games(team x) {
  return x.wins + x.ties + x.losses;
}

bool compare(team x, team y) {
  if (x.points == y.points) {
    if (x.wins == y.wins) {
      if (difference(x) == difference(y)) {
        if (x.scored == y.scored) {
          if (games(x) == games(y)) {
            return x.name > y.name;
          } else {
            return games(x) < games(y);
          }
        } else {
          return x.scored > y.scored;
        }
      } else {
        return difference(x) > difference(y);
      }
    } else {
      return x.wins > y.wins;
    }
  } else {
    return x.points > y.points;
  }
}

int main() {
  int N, T, G;
  vector<team> teams;
  scanf("%d", &N);
  while (N--) {
    // echo line
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
      // get line
      teams[i].name;
    }
    scanf("%d", &G);
    while (G--) {

    }
  }
}