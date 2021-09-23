class Solution:
    def countTriplet(self, arr, n, x):
        if len(arr) < 3:
            return 0
        arr.sort()
        count = 0
        for i in range(len(arr)-2):
            left = i + 1
            right = len(arr)-1
            while left < right:
                sumo = arr[i] + arr[left]+ arr[right]
                if sumo >= x:
                    right -= 1
                else:
                    count += (right-left)
                    left += 1
        return count

obj = Solution()

print(obj.countTriplet([5,1,3,4,7], 5, 12))
