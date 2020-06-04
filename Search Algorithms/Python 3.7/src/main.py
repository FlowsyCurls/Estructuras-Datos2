def sequentialSearch(arr, x):
    for i in range(len(arr)):

        if arr[i] == x:
            return i

    return -1


def binarySearch(arr, x):
    l = 0
    r = len(arr)
    while l <= r:
        mid = l + (r - l) // 2
        if arr[mid] == x:
            return mid
        elif arr[mid] < x:
            l = mid + 1
        else:
            r = mid - 1
    return -1


def interpolationSearch(arr, x):
    n = len(arr)
    # Find indexes of two corners
    lo = 0
    hi = (n - 1)
    while lo <= hi and arr[lo] <= x <= arr[hi]:
        if lo == hi:
            if arr[lo] == x:
                return lo
            return -1
        pos = lo + int(((float(hi - lo) / (arr[hi] - arr[lo])) * (x - arr[lo])))
        if arr[pos] == x:
            return pos
        if arr[pos] < x:
            lo = pos + 1
        else:
            hi = pos - 1

    return -1


def main():
    i = 33
    arr = [10, 12, 13, 16, 18, 19, 21, 24, 25, 28, 33, 35, 42, 47]
    a = sequentialSearch(arr, i)
    b = binarySearch(arr, i)
    c = interpolationSearch(arr, i)
    if a == b and b == c:
        print("Element is found at index:", a)
    else:
        print("Element is not found!")


main()
