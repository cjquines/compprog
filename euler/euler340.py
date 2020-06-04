a = 21**7
b = 7**21
c = 12**7
r = b % a
q = b / a

# For b - ka < n <= b - (k-1)a,
# F(n) = n + 4ka - (3k+1)c = n + (4a - 3c)k - c
# Let F(n) = n - c + G(n); so G(n) = (4a - 3c)k
# For fixed k, there are a ints in (b - ka, b - (k-1)a]
# so the summation of G(n) would be (4a - 3c)ka.
# sum F(n) = sum n - sum c + sum G(n)
#          = b(b+1)/2 - (b+1)c + sum G(n)
#          = b(b+1)/2 - (b+1)c + sum G(n) from n = 0 to r
#            + sum (4a - 3c)ka from k = 1 to q
#          = b(b+1)/2 - (b+1)c + (4a - 3c)(q+1)(r+1)
#            + (4a - 3c)(a)(sum k) from k = 1 to q
#          = b(b+1)/2 - (b+1)c + (4a - 3c)(q+1)(r+1)
#            + (4a - 3c)(a)(q)(q+1)/2

s = (b*(b+1)/2 - (b+1)*c + (4*a - 3*c)*(q+1)*(r+1)
     + (4*a - 3*c)*a*q*(q+1))

print s % 10**9