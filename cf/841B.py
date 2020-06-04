input()
print("First" if 1 in [int(x) % 2 for x in input().strip().split()] else "Second")