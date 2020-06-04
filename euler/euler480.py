from collections import Counter

def memoize(f):
  memo = {}
  def sub(x, y):
    if str([y] + x) not in memo:
      memo[str([y] + x)] = f(x, y)
    return memo[str([y] + x)]
  return sub

@memoize
def _count_perms(ctr, size):
  if size < 0:
    return 0
  res = 1
  for i in xrange(len(ctr)):
    ctr[i] -= 1
    res += count_perms(ctr[:], size - 1)
    ctr[i] += 1
  return res

def count_perms(ctr, size):
  """
  Counts the number of permutations of ctr with length at most size.

  Example
  =======

  The following counts the permutations of 'aab' with length at most 2,
  which are '', 'a', 'aa', 'ab', 'b', 'ba':

  >>> count_perms([2, 1], 2)
  6
  """
  ctr.sort(reverse=True)
  while len(ctr) > 0 and ctr[-1] == 0:
    ctr.pop()
  return _count_perms(ctr, size)

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