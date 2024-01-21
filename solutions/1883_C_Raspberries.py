for _ in range(int(input())):
    n,k = map(int, input().split())
    l = list(map(int, input().split()))
    flag = 0
    for x in l:
        if x % k ==0:
            print(0)
            flag = 1
            break
    if flag == 0:
        mx = 0
        for x in l:
            mx = max(mx, x%k)
        ans = k-mx

        if k ==4:
            cnt2 = 0
            for x in l:
                cnt2 += (x%2==0)
            if cnt2 == 1:
                ans = min(ans, 1)
            elif cnt2 > 1:
                ans = min(ans, 0)
            else:
                ans = min(ans, 2)
        print(ans)
