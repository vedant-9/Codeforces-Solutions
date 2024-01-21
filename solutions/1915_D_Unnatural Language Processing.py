for _ in range(int(input())):
    n = int(input())
    s = input()
    # i means current vowel index
    vis = [0 for i in range(n)]
    i = n-2
    while(i >= 0):
        if(s[i] in "bcd"):
            vis[i] = 1
            if(i-1>=0 and s[i-1] in "bcd"):
                i -= 1
        i -= 1
    for i in range(n):
        if(i>0 and vis[i]):
            print(".", end="")
        print(s[i], end="")
    print()
