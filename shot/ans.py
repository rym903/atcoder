sx, sy, tx, ty = list(map(int, input().split(" ")))

dx = tx - sx
dy = ty - sy
ans = 'R'*dx + 'U'*dy 
ans += 'L'*dx + 'D'*dy 
ans += 'L' + 'U'*(dy+1) + 'R'*(dx+1) + 'D'
ans += 'R' + 'D'*(dy+1) + 'L'*(dx+1) + 'U'

print(ans)