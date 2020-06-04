x = input()
y = set(map(int, input().split()))

if 0 in y:
  print(len(y) - 1)
else:
  print(len(y))