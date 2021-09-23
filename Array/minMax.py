def findMinMax(arr, low, high):
    mini = arr[low]
    maxi = arr[low]
    if low == high:
        mini = arr[low]
        maxi = arr[low]
        return maxi, mini
    elif high == low + 1:
        if arr[low] < arr[high]:
            mini = arr[low]
            maxi = arr[high]
        else:
            mini = arr[high]
            maxi = arr[low]
        return maxi, mini
    # if more than three element are there
    else:
        mid = (low+high)//2
        maxil, minil = findMinMax(arr, low, mid)
        maxir, minir = findMinMax(arr, mid+1, high)
    return (max(maxil, maxir), min(minil, minir))


arr = list(map(int, input().split()))
print(*findMinMax(arr, 0, len(arr)-1))
