import sys
n = int(raw_input())
tr = map(int, raw_input().strip().split())
if tr != sorted(tr):
  print "NO"
else:
  for i in xrange(1, n):
    if tr[i] - tr[i-1] > 1:
      print "NO"
      sys.exit()
  print "YES"