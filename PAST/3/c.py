a, r, n = map(int, input().strip().split(" "))
n -= 1
m = 1000000000
t = 1

while n > 0 and m >= t*a:
    # print(t, r)
    if n%2 == 1:
        t *= r
        n -= 1
    else:
        r = r**2
        n /= 2

if m < t*a:
    print("large")
else:
    print(t*a)