import math
for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    arr_sum = sum(arr)
    x = math.sqrt(arr_sum)
    if math.floor(x) == math.ceil(x):
        print("YES")
    else:
        print("NO")
