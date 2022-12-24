def f(x): 
    if x<10:
        return x  
    else:
        return x//10+9-(0 if str(x)[0]<=str(x)[-1] else 1)
 
l, r = map(int,input().split())
print(f(r)-f(l-1))
