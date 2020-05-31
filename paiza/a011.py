def rec(p, i, d, n, ans):
    """
    p: 現在位置
    i: iter
    ans: 移動履歴
    """
    # print(ans)
    if i==n:
        return ans
    
    tmp = ans
    a = int(input())
    if abs(p - a) <= d:
        return rec(p-a, i+1, d, n, tmp+"L")
    if abs(p + a) <= d:
        return rec(p+a, i+1, d, n, tmp+"R")


res = ""
d, n = map(int, (input().strip().split(" ")))

print(rec(0, 0, d, n, res))