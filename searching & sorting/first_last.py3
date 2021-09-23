def findIndexs(arr, target):
    l = 0
    r = len(arr) - 1
    mid = 0
    while(l<r):
        mid = (l+r)//2
        if arr[mid] == target:
            break
        elif arr[mid] < target:
            l = mid + 1
        else:
            r = mid - 1
    if arr[mid] != target:
        print("-1")
    else:
        l = mid
        r = mid
        while l >= 0 and arr[l] == target:
            l -= 1
        print(l+1, end=" ")
        while(r < len(arr) and arr[r] == target):
            r += 1
        print(r-1)

for _ in range(int(input())):
    n, x = map(int, input().split())
    arr = list(map(int, input().split()))
    findIndexs(arr, x)