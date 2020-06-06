input = input().strip().split(" ")
a, b = int(input[0]), str(input[1])
c = int(b.replace(".", ""))

dot = 0
l = 0
for s in b:
    if s=='.':
        l = len(b[(dot+1):])
    dot += 1

print((a*c)//10**l)