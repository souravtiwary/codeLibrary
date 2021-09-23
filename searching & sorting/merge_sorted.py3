def findGap(gap):
    if gap <= 1:
        return 0
    return gap//2 + (gap%2)

def mergeArray(a, b, n, m):
    gap = n + m
    gap = findGap(gap)
    while gap > 0:
        i = 0
        while i+gap < n:
            if a[i] > a[i+gap]:
                a[i], a[i+gap] = a[i+gap], a[i]
            i+=1
        j = gap-n if gap > n else 0
        while i < n and j < m:
            if a[i] > b[j]:
                a[i], b[j] = b[j], a[i]
            i+=1
            j+=1
        if j < m:
            j = 0
            while j + gap < m:
                if b[j] > b[gap+j]:
                    b[j], b[gap+j] = b[gap+j], b[j]
                j += 1
        gap = findGap(gap)
        print(a, b)
    print(a)
    print(b)

n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

mergeArray(a, b, n, m)