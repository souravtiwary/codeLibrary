def findSunarray(arr, n):
    count = 0
    summ = 0
    temp = {}
    temp.setdefault(summ, 1)
    for i in range(n):
        summ += arr[i]
        if summ in temp.keys():
            count += temp[summ]
            temp[summ] += 1
        else:
            temp.setdefault(summ, 1)
    return count


findSunarray([0, 0, 5, 5, 0, 0], 6)
