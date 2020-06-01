n = int(input())
ans = 1
m = 1000000000000000000
a = map(int, input().strip().split(" "))
a = list(a)

for i in range(n):
    if a[i]==0:
        ans = 0

for i in range(n):
    ans *= a[i]
    if ans > m:
        ans = -1
        break 

print(ans)