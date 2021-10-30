
'''
You are given a string and your task is to swap cases.
In other words, convert all lowercase letters to uppercase letters and vice versa.
Www.HacToberFEST.diGItalOCean.com → wWW.hACtOBERfest.DIgiTALocEAN.COM
Pythonist 2 → pYTHONIST 2


Constraints
0 < len(s) <= 1000
Sample Input 0
>>HackerRank.com presents "Pythonist 2".
Sample Output 0
>>hACKERrANK.COM PRESENTS "pYTHONIST 2".
'''


import re

#[^a-zA-Z] means any character that IS NOT a-z OR A-Z
regexp = re.compile('[^a-zA-Z]+')


def swap_case(s):
    #Check the length of a string
    if len(s) < 1001:
        newstring = ''
        for a in s:
            # check condition if word in a for loop is in upper case letter  then make it lower case
            # and concat it with 'newstring' string
            if a.isupper() == True:
                newstring += a.lower()
            # check condition if word in a for loop is in lower case letter  then make it upper case
            # and concat it with 'newstring' string
            if a.islower() == True:
                newstring += a.upper()
            #If a word is not found in a regular expression then concat it with 'newstring' string
            if regexp.search(a):
                newstring += a

    else:
        raise Exception("Charater length should be less than 100")
    return newstring


if __name__ == '__main__':
    s = input('Enter your string here: ')
    result = swap_case(s)
    print(result)