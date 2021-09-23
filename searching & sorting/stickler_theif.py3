def findAmount(arr, size):
    exe_pre = 0
    exe_curr = 0
    inc_pre = arr[0]
    inc_curr = arr[0]
    for i in range(1,len(arr)):
        exe_curr = max(inc_pre, exe_pre)
        inc_curr = exe_pre + arr[i]
        inc_pre  = inc_curr
        exe_pre = exe_curr
    return max(inc_curr, exe_curr)


for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    print(findAmount(arr, n))