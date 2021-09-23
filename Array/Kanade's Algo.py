for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    max_so_far = float("-inf")
    max_till_here = 0
    for i in range(n):
        max_till_here += arr[i]
        if max_till_here >  max_so_far:
            max_so_far = max_till_here
        if max_till_here < 0:
            max_till_here = 0
    print(max_so_far)