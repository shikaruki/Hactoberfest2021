n = int(input())
a = set()
b = set()
c = set()
t = int(input())
for j in range(t):
    s = input()
    a.add(s)
b = a
c = a
for i in range(1,n) :
    a = set()
    t = int(input())
    for j in range(t):
        s = input()
        a.add(s)
    b = b&a
    c = c|a
print(len(b))
print(*sorted(b), sep="\n")
print(len(c))
print(*sorted(c), sep="\n")
