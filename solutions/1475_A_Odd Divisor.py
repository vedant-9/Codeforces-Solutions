for _ in range(int(input())):
    n = int(input())
    b = bin(n)[2:]
    # print(b)
    x = b.count('1')
    # print(x)
    l = len(b)
    if ((n&1) or (n%2==0 and x!=1)):
        print("YES")
    else:
        print("NO")