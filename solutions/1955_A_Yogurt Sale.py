for _ in range(int(input())):
    n, a, b = map(int, input().split())
    if 2 * a <= b:
        print(n * a)
    else:
        print((n // 2) * b + (n % 2) * a)
