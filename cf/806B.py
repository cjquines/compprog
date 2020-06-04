import sys

def mxpt(i, n):
  if 8*i > n:
    if 4*i > n:
      if 2*i > n:
        return 500
      else:
        return 1000
    else:
      return 1500
  else:
    if 16*i > n:
      return 2000
    elif 32*i > n:
      return 2500
    else:
      return 3000

lines = [map(int, line.strip().split()) for line in sys.stdin][1:]
correct = [0]*5

for i in xrange(len(lines)):
  for j in xrange(5):
    if lines[i][j] >= 0:
      correct[j] += 1

for i in xrange(len(lines)*32):
  vasyapts = 0
  petyapts = 0
  for j in xrange(5):
    if lines[0][j] > lines[1][j] and lines[1][j] != -1:
      maxpts = mxpt(correct[j]+i, len(lines)+i)
    else:
      maxpts = mxpt(correct[j], len(lines)+i)
    vasyapts += maxpts - maxpts/250*lines[0][j] if lines[0][j] >= 0 else 0
    petyapts += maxpts - maxpts/250*lines[1][j] if lines[1][j] >= 0 else 0
  if vasyapts > petyapts:
    print i
    sys.exit()

print -1