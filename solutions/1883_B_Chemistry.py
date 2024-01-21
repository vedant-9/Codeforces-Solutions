for _ in range(int(input())):
    n,k = map(int, input().split())
    s = input()
    freq = dict()
    for ch in s:
        if ch not in freq:
            freq[ch] = 1
        else:
            freq[ch] += 1
    cnt = 0
    for key in freq:
        if(freq[key] %2 !=0 ):
            cnt += 1
    # print(freq)
    if(cnt <= k+1 and abs(cnt-k)%2==(n-k)%2):
        print("YES")
    else:
        print("NO")
