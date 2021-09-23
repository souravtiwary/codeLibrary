def productArray(arr, n):
    if n == 1:
        return [1]
    temp = 1
    zeros = 0
    idx = 0
    p = [0]*n
    for i in range(n):
        if arr[i] != 0:
            temp *= arr[i]
        else:
            zeros += 1
            idx = i
    if zeros > 1:
        return p
    elif zeros == 1:
        p[idx] = temp
        return p
    else:
        for i in range(n):
            p[i] = temp // arr[i]
    return p
