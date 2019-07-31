def merge(L, R, A):
    i = 0
    j = 0
    for k in range(len(A)):
        if i >= len(L):
            A[k] = R[j]
            j += 1
        elif j >= len(R):
            A[k] = L[i]
            i += 1
        elif L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1
    return A


def merge_sort(A):
    n = len(A)
    if n < 2:
        return A
    else:
        mid = n/2
        L = A[:mid]
        R = A[mid:]
        merge_sort(L)
        merge_sort(R)
        merge(L, R, A)
        return A


print merge_sort([5, 6, 5, 11, 1, 9])
