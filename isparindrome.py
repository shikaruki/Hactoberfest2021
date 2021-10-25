def isparindrom(str):
    if str == str[::-1]:
        return True
    return False

print(isparindrom('parindromemordnirap'))