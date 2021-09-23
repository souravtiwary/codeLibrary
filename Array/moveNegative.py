arr = list(map(int, input().split()))
low = 0
high = 0
while high < len(arr):
    if arr[high] < 0:
        arr[low], arr[high] = arr[high], arr[low]
        high += 1
        low += 1
    else:
        high += 1
print(*arr)
