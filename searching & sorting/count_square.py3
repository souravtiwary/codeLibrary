class Solution:
    def search(self, N):
        if N <= 3:
            return 1
        else:
            temp = N**(1/2)
            if temp - int(temp) == 0:
                return int(temp-1)
            else:
                return int(temp)
        