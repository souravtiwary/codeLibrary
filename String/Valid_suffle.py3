# def findSolution(a, b, string):
#     if len(a) + len(b) != len(string):
#         return False
#     for i in range(len(a)):
#         for j in range(len(string)):
#             if string[j] == a[i]:
#                 a[i] = j
#     for i in range(len(b)):
#         for j in range(len(string)):
#             if string[j] == b[i]:
#                 b[i] = j
#     for i in range(1, len(a)):
#         if a[i] - a[i-1] < 0:
#             return False
#     for i in range(1, len(b)):
#         if b[i] - b[i-1] < 0:
#             return False
#     return True


def findSolution(a, b, string):
    if len(a) + len(b) != len(string):
        return False
    i = 0
    j = 0
    k = 0

    while k < len(string):
        if i < len(a) and a[i] == string[k]:
            i += 1
        elif j < len(b) and b[j] == string[k]:
            j+=1
        else:
            return False
        k += 1
    if i != len(a) or j != len(b):
        return False
    return True
            

a = 'xy'
b = '12'
string = 'xy12'
a = list(a)
b = list(b)
string = list(string)
print(findSolution(a, b, string))