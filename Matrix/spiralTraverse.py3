# time O(n*m) space => itt-> O(n*m), rec-> O(n*m)

def spiralTraversal(arr):
    result = []
    startRow, endRow = 0, len(arr)-1
    startCol, endCol = 0, len(arr[0]) - 1

    while startRow<=endRow and startCol <= endCol:
        for col in range(startCol, endCol+1):
            result.append(arr[startRow][col])
        
        for row in range(startRow+1, endRow+1):
            result.append(arr[row][endCol])

        for col in reversed(range(startCol, endCol)):
            result.append(arr[endRow][col])
        
        for row in reversed(range(startRow+1, endRow)):
            result.append(arr[row][startCol])

        startCol += 1
        endCol -= 1
        startRow += 1
        endRow -= 1

    print(*result)

arr = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]]
spiralTraversal(arr)