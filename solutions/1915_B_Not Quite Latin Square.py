for _ in range(int(input())):
    mat = [input() for i in range(3)]
    flag = 0
    for i in range(3):
        for j in range(3):
            if(mat[i][j] == "?"):
                st = set({"A", "B", "C", "?"})
                st.remove(mat[i][0])
                st.remove(mat[i][1])
                st.remove(mat[i][2])
                print(st.pop())
                flag = 1
                break
        if flag == 1:
            break
