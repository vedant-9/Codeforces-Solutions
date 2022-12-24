n, m = map(int, input().split())
a = []
for i in range(m):
    a.append(list(map(int, input().split())))
for x in a[0][0], a[0][1]:
    s = set(i for i in range(1, n+1))
    for i in a[1:]:
        if x not in i:
            s.intersection_update(set(i))
    if len(s):
        exit(print("YES"))
print("NO")
