for _ in range(int(input())):
    n, k = map(int, input().split())
    arr = [i+1 for i in range(n)]
    new_arr = arr[n-k-1::-1] + arr[n-k:n]
    for x in new_arr:
        print(x, end=" ")
    print()
