perms = ["1869","1896","1986","1698","6198","1689","1968"]
count = [0]*10
s = raw_input().strip()
for i in s: count[int(i)] += 1
for i in "1689": count[int(i)] -= 1
mod = 0
flag = True
for i in xrange(1, 10):
  if count[i] > 0: flag = False
  mod = (pow(3, count[i] % 6, 7)*(mod + 4*i) - 4*i) % 7
if flag:
  print perms[0] + "0"*count[0]
else:
  mod = (pow(3, (count[0] + 4) % 6, 7) * mod) % 7
  print ''.join([str(i) for i in xrange(1, 10) for j in xrange(count[i])]) + "0"*count[0] + perms[mod]