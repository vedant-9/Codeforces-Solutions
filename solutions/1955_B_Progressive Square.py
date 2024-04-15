for _ in range(int(input())):
    n, c, d = map(int, input().split())
    l = list(map(int, input().split()))
    l.sort()
    ans = []
    for i in range(n):
        for j in range(n):
            ans.append(l[0] + i * c + j * d)
    ans.sort()
    if l == ans:
        print("YES")
    else:
        print("NO")
