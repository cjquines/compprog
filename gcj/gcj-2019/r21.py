# import sys
# sys.stdout.flush()
# sys.exit()

from fractions import Fraction as F

for cas in range(int(input())):
  n = int(input())
  mol = []
  for _ in range(n):
    mol.append(list(map(int, input().split())))
  rats = set()
  for i in range(n):
    for j in range(i+1, n):
      a, b = mol[i]
      c, d = mol[j]
      if a == c: continue
      rat = F(d-b, a-c)
      if rat > 0: rats.add(rat)
  print("Case #" + str(cas+1) + ": " + str(len(rats) + 1))