from LCS import commonPrefix

if __name__ == '__main__':
    arr = ["shak", "shark", "sharlyn", "shine"]
    ans = commonPrefix(arr, 0, len(arr) - 1)
    if len(ans):
        print("The longest common prefix is  \"", ans, "\" : ", len(ans));
    else:
        print("There is no common prefix")