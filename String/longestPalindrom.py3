#      * Linear time Manacher's algorithm to find longest palindromic substring.
#      * There are 4 cases to handle
#      * Case 1 : Right side palindrome is totally contained under current palindrome. In this case do not consider this as center.
#      * Case 2 : Current palindrome is proper suffix of input. Terminate the loop in this case. No better palindrom will be found on right.
#      * Case 3 : Right side palindrome is proper suffix and its corresponding left side palindrome is proper prefix of current palindrome. Make largest such point as
#      * next center.
#      * Case 4 : Right side palindrome is proper suffix but its left corresponding palindrome is be beyond current palindrome. Do not consider this
#      * as center because it will not extend at all.
#      *
#      * To handle even size palindromes replace input string with one containing $ between every input character and in start and end.

def longestPalindrom(string):
    idx = 0
    newInput = []
    # print(len(string))
    for i in range(2*len(string)+1):
        if i % 2 != 0:
            newInput.append(string[idx])
            idx += 1
        else:
            newInput.append('$')
    
    T = [0]*len(newInput)
    start = 0
    end = 0
    for i in range(0, len(newInput)):
        while start > 0 and end < len(newInput) and newInput[start-1] == newInput[end+1]:
            end += 1
            start -= 1
        
        T[i] = end - start + 1

        if end == len(newInput):
            break

        newCenter = end

        if i % 2 == 0:
            end += 1
        
        for j in range(i+1, end+1):
            T[j] = min(T[i - (j - i)], 2 * (end - j)+1)

            if (j+T[i-(j-i)]//2 == end):
                newCenter = j
                break
        i = newCenter
        end = i + T[i]//2
        start = i - T[i]//2
    maxi = float("-inf")
    for i in range(len(T)):
        val = T[i]//2
        maxi = max(maxi, val)
    return maxi

for _ in range(int(input())):
    string = input()
    print(longestPalindrom(string))