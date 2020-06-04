from collections import Counter
from math import factorial

def multiply(a, b):
  """
  Multiplies two degree-15 polynomials a and b, clipping the result.

  Example
  =======

  The following computes (1 + x)(-1 + x) = (-1 + x^2):

  >>> multiply([1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
               [-1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0])
  [-1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
  """
  res = 16*[0]
  for i in xrange(16):
    for j in xrange(i+1):
      res[i] += a[j] * b[i-j]
  return res

def polyexp(b, e):
  """
  Polynomial exponentiation using multiply(a, b).
  """
  if e == 0:
    res = 16*[0]
    res[0] = 1
    return res
  if e == 1:
    return b
  res = polyexp(b, e/2)
  res = multiply(res, res)
  if e % 2 == 1:
    res = multiply(b, res)
  return res

gen = [factorial(15)]
for i in xrange(1, 16):
  gen.append(gen[-1] / i)

def count_perms(ctr, size):
  """
  Counts the number of permutations of ctr with length at most size.

  Example
  =======

  The following counts the permutations of 'aab' with length at most 2,
  which are '', 'a', 'aa', 'ab', 'b', 'ba.':

  >>> count_perms([2, 1], 2)
  6
  """
  polys = []
  for (i, j) in Counter(ctr).iteritems():
    polys.append(polyexp(gen[:(i+1)] + (15-i)*[0], j))
  prod = reduce(multiply, polys)
  res = []
  for i, v in enumerate(prod):
    res.append(v*factorial(i)/(factorial(15)**len(ctr)))
  return sum(res[:(size+1)])

def find_pos(word):
  letters = Counter(list("thereisasyetinsufficientdataforameaningfulanswer"))
  letters = [[i, j] for (i, j) in letters.iteritems()]
  letters.sort()
  depth = 0
  res = 0
  for i in word:
    j = 0
    while j < len(letters):
      if i > letters[j][0] and letters[j][1] > 0:
        letters[j][1] -= 1
        res += count_perms([k for m, k in letters], 14 - depth)
        letters[j][1] += 1
      if i == letters[j][0] and letters[j][1] > 0:
        letters[j][1] -= 1
        res += 1
        break
      j += 1
    depth += 1
  return res

def find_word(pos):
  letters = Counter(list("thereisasyetinsufficientdataforameaningfulanswer"))
  letters = [[i, j] for (i, j) in letters.iteritems()]
  letters.sort()
  word = ""
  while find_pos(word) < pos:
    i = 0
    while i < len(letters) and (letters[i][1] <= 0 or find_pos(word + letters[i][0]) <= pos):
      i += 1
    while letters[i-1][1] <= 0: i -= 1
    word += letters[i-1][0]
    letters[i-1][1] -= 1
  return word

print find_word(find_pos("legionary")
              + find_pos("calorimeters")
              - find_pos("annihilate")
              + find_pos("orchestrated")
              - find_pos("fluttering"))