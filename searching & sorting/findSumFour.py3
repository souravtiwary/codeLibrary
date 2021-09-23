def fourSum(arr, target):
    ans = []
    if len(arr) < 4:
        return ans
    arr.sort()
    for i in range(0, len(arr)-3):
        #removing duplicates
        if i > 0 and arr[i] == arr[i-1]:
            continue
        for j in range(i+1, len(arr)-2):
            #removing duplicate
            if j > i+1 and arr[j] == arr[j-1]:
                continue
            
            l = j + 1
            r = len(arr) - 1
            while(l < r):
                oldLeft = l
                oldRight = r
                if arr[i]+arr[j]+arr[l]+arr[r] == target:
                    
                    ans.append([arr[i], arr[j], arr[l], arr[r]])
                    #removing duplicate
                    while(l < r and arr[l] == arr[oldLeft]):
                        l += 1
                    while(l < r and arr[r] == arr[oldRight]):
                        r -= 1
                elif arr[i]+arr[j]+arr[l]+arr[r] < target:
                    l += 1
                else:
                    r -= 1
    #print(ans)
    return ans
    
print(fourSum([10, 2,3,4,5,7,8], 23))