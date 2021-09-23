
def kthSmallest(mat, n, k): 
    # Your code goes here
    res = []
    for row in mat:
        for ele in row:
            res.append(ele)
    res.sort()
   # print(*res)
    return res[k-1]