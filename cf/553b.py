fib = [0]*100
fib[0] = fib[1] = 1
for i in xrange(2, 100):
  fib[i] = fib[i-1] + fib[i-2]

n, k = map(int, raw_input().strip().split())

res = []

def print_ans(i, n, k):
  # print kth permutation, starts with index i
  if n == 0:
    return
  elif k > fib[n-1]:
    res.append(i+1)
    res.append(i)
    print_ans(i+2, n-2, k-fib[n-1])
  else:
    res.append(i)
    print_ans(i+1, n-1, k)

print_ans(1, n, k)
print ' '.join(map(str, res))