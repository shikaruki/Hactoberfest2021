# Python Program to Concatenate Two Dictionaries

def Merge_Dictionaries(first, second):
    result = {**first_Dict, **second_Dict}
    return result

first_Dict = {'a': 'apple', 'b': 'Banana' , 'o': 'Orange'}
second_Dict = { 'k': 'Kiwi', 'm': 'Mango'}
print("First Dictionary: ", first_Dict)
print("Second Dictionary: ", second_Dict)

# Concatenate Two Dictionaries in Python
third_Dict = Merge_Dictionaries(first_Dict, second_Dict)

print("\nAfter Concatenating two Dictionaries : ")
print(third_Dict)
