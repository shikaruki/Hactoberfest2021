import random
print("------------Snake Water Gun---------------")#between two Player
print("S for Snake\nW for Water\nG for Gun")
print()

chances = 10
computer_points = 0
user_points = 0 


while True: 
    computer_choice = random.choice(("S", "W", "G"))
    # print(f"Computer choice is {computer_choice}")  

    
    if chances != 0:
        User_choice = input("Enter Your choice: ")
        if computer_choice == User_choice:
            chances -= 1
            print(f"Draw..Try again... your remaining {chances} ")
            print()
        

        elif computer_choice == "S" and User_choice == "W" or  computer_choice == "W" and User_choice == "G" or computer_choice == "G" and User_choice == "S":
            chances -= 1
            computer_points += 1
            print(f"You Lose...& your remaining {chances} ")
            print()

        elif User_choice == "S" and computer_choice == "W" or  User_choice == "W" and computer_choice == "G" or User_choice == "G" and computer_choice == "S":
            chances -= 1
            user_points += 1 
            print(f"You Win...& your remaining {chances} ")
            print()


    else:
        if computer_points < user_points:
            print(f"You are winner.... beacause computer points ({computer_points}) is less than Your points ({user_points})")
            break
           
        else:
            print(f"Computer Win..You are Lose .... beacause computer points ({computer_points}) is greater than Your points ({user_points})")
            break
            
    


