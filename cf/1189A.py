n = int(input())
s = input().strip()
if s.count('0') != s.count('1'):
  print(1)
  print(s)
else:
  print(2)
  print(s[:-1], s[-1])