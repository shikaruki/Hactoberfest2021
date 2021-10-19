#! /usr/bin/python3
import sys
import random

answer = True

print("Simple Magic 8-Ball script to show examples of random and conditional statements.")

while answer:
    question = input("Ask your Magic 8-Ball a question or simply press enter to quit: ")
    answers = random.randint(1,8)
    if question == "":
        sys.exit()
    elif answers == 1:
        print ("It could be.")
    elif answers == 2:
        print ("I don't think so.")
    elif answers == 3:
        print ("You may rely on it")
    elif answers == 4:
        print ("I'm not sure, ask again.")
    elif answers == 5:
        print ("Definetly.")
    elif answers == 6:
        print ("I couldn't hear you.")
    elif answers == 7:
        print ("Umm. No..")
    elif answers == 8:
        print ("Well, yes!")
