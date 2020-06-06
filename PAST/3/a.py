a = input()
b = input()
if a==b:
    print("same")
elif a.lower() == b.lower() or a.upper() == b.upper():
    print("case-insensitive")
else:
    print("different")