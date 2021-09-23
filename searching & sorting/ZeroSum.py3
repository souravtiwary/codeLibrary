def findSumZero(arr, n):
    ans = 1 if arr[0] == 0 else 0
    temp = arr[0]
    for i in range(1, n):
        if arr[i] == 0:
            ans += 1
            temp = 0
            
        temp += arr[i]
        if temp == 0:
            ans += 1
    return ans
        
arr = [0,0,5,5,0,0]
n = 6
print(findSumZero(arr, n))