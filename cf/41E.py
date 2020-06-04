# classic

n = input()
a = n/2
b = (n+1)/2

print a*b
for i in xrange(1, a+1):
  for j in xrange(a+1, n+1):
    print "{} {}".format(i, j)