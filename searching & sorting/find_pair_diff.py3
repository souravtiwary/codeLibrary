def findPair(arr, target):
    arr.sort()
    i = 0
    j = 1
    while i < len(arr) and j < len(arr):
        if arr[j] - arr[i] == target:
            return 1
        elif arr[j] - arr[i] < target:
            j += 1
        else:
            i += 1
    return -1

for _ in range(int(input())):
    l, n = map(int, input().split())
    arr = list(map(int, input().split()))
    print(findPair(arr, n))