for z in range(int(input())):
    a=input()
    b=input()
    ans="NO"
    for i in range(len(a)):
        #print(a[:i]+" "+a[i::-1])
        if b in a[:i]+a[i::-1]:
            ans="YES"
            break
    print(ans)