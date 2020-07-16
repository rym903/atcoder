# 最近点対を分割統治法で求める
from math import sqrt
n = int(input())
ps = [list(map(float, input().strip().split())) for i in range(n)]
# print(ps)
# Q: なぜ、最初にx座標についてソートされている必要があるのか？
# A: 二つの区間が統合されるとき、dには2つの区間における最小２点間距離が入っており、
#    統合された区間における最小値は、それ以下を探索するようになっている。
#    この時、各区間A:[i, i+m), B:[i+m, n)での最小値において、
#    [Aの任意の点]と[Bの任意の点]の距離は、境界(i+m-1とi+m)を除いてこの最小値以上であるという前提が成り立つ。
#    そのため、統合された区間において探索するのはabs(dx - x) <= dのみを探索すれば良い。
#    仮にxでソートされていない場合、上の前提が成り立たないため、統合しても結局全ての点で
#    距離を計算しなくてはいけない。
ps.sort()
# print(ps)
INF = 10**9

# cp_rec - 再帰用関数
# 入力: 配列と区間
# 出力: 距離と区間内の要素をY座標でソートした配列
def cp_rec(ps, i, n):
    if n <= 1:
        return INF, [ps[i]]
    m = int(n/2)
    x = ps[i+m][0] # 半分に分割した境界のX座標
    # 配列を半分に分割して計算
    d1, qs1 = cp_rec(ps, i, m)
    d2, qs2 = cp_rec(ps, i+m, n-m)
    d = min(d1, d2)
    # Y座標が小さい順にmergeする
    qs = [None]*n
    s = t = idx = 0
    while s < m and t < n-m:
        if qs1[s][1] < qs2[t][1]:
            qs[idx] = qs1[s]; s += 1
        else:
            qs[idx] = qs2[t]; t += 1
        idx += 1
    while s < m:
        qs[idx] = qs1[s]; s += 1
        idx += 1
    while t < n-m:
        qs[idx] = qs2[t]; t += 1
        idx += 1
    # 境界のX座標x(=ps[i+m][0])から距離がd以下のものについて距離を計算していく
    # bは境界のX座標から距離d以下のものを集めたものが、Y座標の昇順に入っている。
    b = []
    for i in range(n):
        ax, ay = q = qs[i]
        if abs(ax - x) >= d:
            continue
        # Y座標について、qs[i]から距離がd以下のj(<i)について計算していく
        for j in range(len(b)-1, -1, -1):
            dx = ax - b[j][0]
            dy = ay - b[j][1]
            # このループは, ayとb[j][1]が近い順に取り出していいるため、
            # 一度 dy >= 0となれば、あとは探索する必要はない。
            if dy >= d: break
            d = min(d, sqrt(dx**2 + dy**2))
        b.append(q)
    # dは、区間[i, i+n)における最小区間距離を指している。
    # qsは[i, i+n)でY座標についてソートされている。
    return d, qs

# ps: ソートした二次元座標のlist
def closest_pair(ps):
    n = len(ps)
    return cp_rec(ps, 0, n)[0]

print("{:.09f}".format(closest_pair(ps)))