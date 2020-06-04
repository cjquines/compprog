n = int(raw_input())
res = []

while n > 4:
  n -= 2
  res.append("3 {} {} {}".format(n, n+1, n+2))
  res.append("3 {} {} {}".format(n, n+1, n+2))
  res.append("4 {} {} {} {}".format(1, n+1, n-1, n+2))
  for i in xrange(1, n-1):
    res.append("4 {} {} {} {}".format(i, n+1, i+1, n+2))

if n == 3:
  res.append("3 1 2 3")
  res.append("3 1 2 3")
elif n ==4:
  res.append("4 1 2 3 4")
  res.append("4 1 2 4 3")
  res.append("4 1 3 2 4")

print len(res)
print "\n".join(res)