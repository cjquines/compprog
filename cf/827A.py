res = ["*"]*3000000

for cas in xrange(int(raw_input())):
  line = raw_input().strip().split()[::-1]
  repl = list(line.pop())
  line.pop()
  for i in map(int, line):
    res[i-1:i-1+len(repl)] = repl

while res[-1] == "*": res.pop()
print ''.join(res).replace("*","a")