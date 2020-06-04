# import sys
# sys.stdout.flush()
# sys.exit()

from random import *
from collections import Counter

def simulate():
  v = [0]*20; xray = [0]*20
  for _ in range(70):
    v[randint(0, 19)] += 1
    xray[_ % 20] = v[_ % 20]
  scan = [i for (x, i) in sorted((x, i) for (i, x) in enumerate(xray))[:10]]
  for _ in scan:
    v[randint(0, 19)] += 1
    xray[_] = v[_]
  for _ in scan:
    v[randint(0, 19)] += 1
    xray[_] = v[_]
  scan = [i for (x, i) in sorted((x, i) for (i, x) in enumerate(xray))[:5]]
  for _ in scan:
    v[randint(0, 19)] += 1
    xray[_] = v[_]
  for _ in scan:
    v[randint(0, 19)] += 1
    xray[_] = v[_]
  # for _ in scan:
  #   v[randint(0, 19)] += 1
  #   xray[_] = v[_]
  for _ in range(5):
    v[randint(0, 19)] += 1
    asd = min(i for (i, x) in enumerate(xray) if x == min(xray))
    xray[asd] = v[asd]
  guess_i = set(i for (i, x) in enumerate(xray) if x == min(xray))
  # return len(guess_i)
  goal_i = min(guess_i); guess_i.remove(goal_i)
  if len(guess_i) == 0:
    xray2 = [i for i in xray if i != min(xray)]
    guess_i = set(i for (i, x) in enumerate(xray2) if x == min(xray2))
  if len(guess_i) > 5: return -2
  for _ in guess_i:
    v[randint(0, 19)] += 1
    v[_] += 1
  for _ in range(5 - len(guess_i)):
    v[randint(0, 19)] += 1
  real_i = set(i for (i, x) in enumerate(v) if x == min(v))
  # return goal_i, v
  if len(real_i) > 1: return -1
  return goal_i in real_i

# print(simulate())
print(Counter(simulate() for _ in range(1000)))