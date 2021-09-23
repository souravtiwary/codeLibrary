class Solution:
    def findHistArea(self, arr):
        stack = list()
        area = 0
        maxArea = 0
        for i in range(len(arr)):
            if len(stack) == 0 or arr[stack[-1]] <= arr[i]:
                stack.append(i)
                i += 1
            else:
                top = stack.pop()
                if len(stack) == 0:
                    area = arr[top] * i
                else:
                    area = arr[top] * (i - stack[-1] - 1)
                maxArea = max(area, maxArea)
        while len(stack) != 0:
            top = stack.pop()
            if len(stack) == 0:
                area = arr[top] * top
            else:
                area = arr[top] * (i - stack[-1] - 1)
            maxArea = max(maxArea, area)
        return maxArea

    def maxRectangle(self, mat):
        arr = []
        arr = mat[0]
        maxArea = Solution.findHistArea(self, arr)
        for i in range(1, len(mat)):
            for c in range(len(mat[i])):
                if mat[i][c] == 0:
                    arr[c] = 0
                else:
                    arr[c] += mat[i][c]
            maxArea = max(Solution.findHistArea(self, arr), maxArea)
        return maxArea
    
A = [[0, 1, 1, 0],
         [1, 1, 1, 1],
         [1, 1, 1, 1],
         [1, 1, 0, 0]]
obj = Solution()
print(obj.maxRectangle(A))