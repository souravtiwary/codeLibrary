# code
for i in range(int(input())):
    n, m = map(int, input().split())
    arrA = list(map(int, input().split()))
    arrB = list(map(int, input().split()))
    ans = []  # replace ans with counter
    dic = {}
    for i in range(min(n, m)):
        if dic.setdefault(arrA[i]) == None:
            dic[arrA[i]] = True
            ans.append(arrA[i])
        if dic.setdefault(arrB[i]) == None:
            dic[arrB[i]] = True
            ans.append(arrB[i])
    if n < m:
        for i in range(n, m):
            if dic.setdefault(arrB[i]) == None:
                dic[arrB[i]] == True
                ans.append(arrB[i])
    elif m < n:
        for i in range(m, n):
            if dic.setdefault(arrA[i]) == None:
                dic[arrA[i]] == True
                ans.append(arrA[i])
    print(len(ans))
