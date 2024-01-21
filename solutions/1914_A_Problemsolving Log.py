for _ in range(int(input())):
    n = int(input())
    s = input()
    freq = [0 for i in range(26)]
    for ch in s:
        freq[ord(ch)-ord('A')] += 1
    ans = 0
    for i in range(26):
        if(freq[i] >= i+1):
            ans += 1
    print(ans)
