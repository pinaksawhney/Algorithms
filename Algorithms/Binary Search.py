# Finding 1-d peak by binary search


def binary_search(arr, n):
    low = 0
    high = n-1
    mid = (low+high)//2
    while not(arr[mid] >= arr[mid+1] and arr[mid] >= arr[mid-1]):
        if arr[mid]>arr[mid+1]:
            high = mid-1
        elif arr[mid]>arr[mid-1]:
            low = mid+1
        mid = (high + low) // 2
        if mid==n-1:
            if arr[mid] >= arr[mid-1]:
                break
        elif mid==0:
            if arr[mid] >= arr[mid + 1]:
                break
    return mid


if __name__ == '__main__':
    print binary_search([1, 2, 4, 5, 3], 5)
