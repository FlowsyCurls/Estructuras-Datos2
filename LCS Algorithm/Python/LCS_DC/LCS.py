def commonPrefixUtil(s1, s2):
    result = ""
    n1, n2 = len(s1), len(s2)
    i, j = 0, 0

    while i <= n1 - 1 and j <= n2 - 1:
        if s1[i] != s2[j]:
            break
        result += s1[i]
        i, j = i + 1, j + 1

    return result


def commonPrefix(arr, low, high):
    if low == high:
        return arr[low]
    if high > low:
        # Partition : merge sort technique
        mid = low + (high - low) // 2
        str1 = commonPrefix(arr, low, mid)
        str2 = commonPrefix(arr, mid + 1, high)
        return commonPrefixUtil(str1, str2)
