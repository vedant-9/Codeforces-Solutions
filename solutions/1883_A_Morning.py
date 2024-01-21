for _ in range(int(input())):
    l = [int(x) for x in input()]
    # print(l)
    for i in range(4):
        if l[i] == 0:
            l[i] = 10
    print(abs(l[0]-1)+abs(l[1]-l[0])+abs(l[2]-l[1])+abs(l[3]-l[2])+4)
    
