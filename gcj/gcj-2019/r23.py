# import sys
# sys.stdout.flush()
# sys.exit()

from fractions import Fraction as F
from math import ceil

from random import *
seed(11)

# taken from https://stackoverflow.com/questions/38140872/

def to_continued_fractions(x):
  a = []
  while True:
    q, r = divmod(x.numerator, x.denominator)
    a.append(q)
    if r == 0: break
    x = F(x.denominator, r)
  return (a, a[:-1] + [a[-1] - 1, 1])

def combine(a, b):
  i = 0
  while i < len(a) and i < len(b):
    if a[i] != b[i]:
      return a[:i] + [min(a[i], b[i]) + 1]
    i += 1
  if i < len(a):
    return a[:i] + [a[i] + 1]
  if i < len(b):
    return a[:i] + [b[i] + 1]
  assert False

def from_continued_fraction(a):
  x = F(a[-1])
  for i in range(len(a) - 2, -1, -1):
    x = a[i] + 1 / x
  return x

def between(x, y):
  def predicate(z):
    return x < z < y or y < z < x
  return predicate

def simplicity(x):
  return x.numerator

def simplest_between(x, y):
  return min(filter(between(x, y), (from_continued_fraction(combine(a, b))
                                    for a in to_continued_fractions(x)
                                    for b in to_continued_fractions(y))), key=simplicity)

for cas in range(int(input())):
  n = int(input())
  mol = []
  for _ in range(n):
    mol.append(list(map(int, input().split())))

  # n = 10
  # mol = [[randint(1, 10), randint(1, 10)] for i in range(n)]
  # mol = [[1, 1], [2, 2], [1, 4]]

  def brute():
    for x in range(1, 25):
      for y in range(1, 25):
        if all(mol[i][0]*x + mol[i][1]*y < mol[i+1][0]*x + mol[i+1][1]*y for i in range(n-1)):
          return x, y
    return -1, -1

  def sol():
    gre = F(0,1)
    les = float('inf')
    for i in range(n-1):
      a, b = mol[i]
      c, d = mol[i+1]
      if b == d:
        if a >= c: les = -float('inf')
        continue
      rat = F(a-c, d-b)
      if d-b > 0: gre = max(gre, rat)
      else: les = min(les, rat)
    if les <= gre:
      return -1, -1

    # print(gre, les)
    if les != float('inf'):
      rat = simplest_between(gre, les)
      ansy, ansx = rat.numerator, rat.denominator
    else:
      ansx = 1
      ansy = int(gre) + 1
    return ansx, ansy
  
  # k = brute()
  j = sol()
  # if k != j:
    # print(mol, k, j)
  if j == (-1, -1):
    print("Case #" + str(cas+1) + ": IMPOSSIBLE")
  else:
    print("Case #" + str(cas+1) + ": " + str(j[0]) + " " + str(j[1]))
