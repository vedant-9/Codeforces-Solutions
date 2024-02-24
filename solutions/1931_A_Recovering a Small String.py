for _ in range(int(input())):
    n = int(input())
    # aaa - 3
    # aab - 4
    # aaz - 28
    # abz - 29
    # azz - 53
    # zzz - 78
    if n <= 28:
        print("aa"+chr(ord('a')+n-3))
    elif n <= 53:
        print("a"+chr(ord('a')+n-28)+"z")
    else:
        print(chr(ord('a')+n-53)+"zz")
