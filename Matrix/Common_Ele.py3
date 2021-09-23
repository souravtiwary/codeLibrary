def findPair(mat):
    temp = dict()
    for ele in mat[0]:
        temp.setdefault(ele, 1)
    for row in range(len(mat)):
        for ele in range(1, len(mat[row])):
            if mat[row][ele] in temp.keys() and temp[mat[row][ele]] == row:
                temp[mat[row][ele]] += 1

                if row == len(mat)-1:
                    print(mat[row][ele], end=" ")

mat = [[1, 2, 2, 2], [1,5,2,1], [2, 2, 1, 6], [6, 4, 2, 1]]
findPair(mat)