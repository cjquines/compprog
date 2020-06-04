sx = []
for i in range(10):
  print(i, flush=True)
  s = input()
  sx.append(s)
if "cool" in sx:
  print("normal", flush=True)
else:
  print("grumpy", flush=True)