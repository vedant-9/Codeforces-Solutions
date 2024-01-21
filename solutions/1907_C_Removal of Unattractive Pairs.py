for _ in range(int(input())):
    n = int(input())
    s = input()
    freq = dict()
    for ch in s:
        if ch not in freq:
            freq[ch] = 1
        else:
            freq[ch] += 1
    mx_cnt_char = max(freq, key = freq.get)
    print(max(n%2, freq[mx_cnt_char]-(n-freq[mx_cnt_char])))
