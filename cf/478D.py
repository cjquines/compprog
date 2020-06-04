import sys
sys.setrecursionlimit(100000)

def memoize(f):
  memo = {}
  def sub(*args):
    if args not in memo:
      memo[args] = f(*args)
    return memo[args]
  return sub

@memoize
def solve(n, w):
  if w == 0: return 1
  if n == 0 or w < 0: return 0
  return solve(n - 1, w) + solve(n - 1, w - n)