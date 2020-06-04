import sys
floors = [line.strip() for line in sys.stdin][::-1]
n, m = map(int, floors.pop().split())
while n > 0 and '1' not in floors[-1]:
  floors.pop()
  n -= 1
if n > 0:
  lights = [[0 if floor.find('1') == -1
    else m + 1 - floor.find('1') for floor in floors],
    [max(0, floor.rfind('1')) for floor in floors]]
  climb = [[0]*n, [0]*n]
  climb[0][n-1] = lights[1][n-1]
  climb[1][n-1] = lights[0][n-1]

  for i in xrange(n-2, -1, -1):
    climb[0][i] = min(lights[1][i]*2 + 1 + climb[0][i+1],
      m + 2 + climb[1][i+1])
    climb[1][i] = min(lights[0][i]*2 + 1 + climb[1][i+1],
      m + 2 + climb[0][i+1])

  print climb[0][0]
else:
  print 0