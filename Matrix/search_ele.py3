class Solution:
    def doBinarySearch(self, row, target):
        l = 0
        r = len(row) - 1
        while l <= r:
            mid = (l + r)//2
            if row[mid] == target:
                return True
            if row[mid] < target:
                l = mid + 1
            elif row[mid] > target:
                r = mid - 1
        return False
    
    def searchMatrix(self, mat, target) -> bool:
        i = 0
        
        if len(mat) == 0:
            return False
        if len(mat[0]) == 0:
            return False
        
        while(i < len(mat)):
            if mat[i][-1] >= target:
                ans = Solution.doBinarySearch(self, mat[i], target)
                if ans:
                    return True
                else:
                    if target < mat[i][-1] and ans == False:
                        return False
                    else:
                        i += 1
            else:
                i += 1
        return False