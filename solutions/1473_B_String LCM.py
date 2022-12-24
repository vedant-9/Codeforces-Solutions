def findlcm(x, y):
    if x > y:
        greater = x
    elif x < y:
        greater = y
    else:
        return x
    while(True):
        if((greater % x == 0) and (greater % y == 0)):
            lcm = greater
            break
        greater += 1
    return lcm


for _ in range(int(input())):
    a = input()
    b = input()
    l,m = len(a),len(b)
    c,d = a*m,b*l
    if(c!=d):
        print(-1)
    else:
        if(l<m):
            print(a*(findlcm(l,m)//l))
        else:
            print(b*(findlcm(l,m)//m))