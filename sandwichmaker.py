import random


done = False
count_s=0
sammich=[]
kitchen=[]
while done!= True:
    ingredients=input("What is one ingredient inside your kitchen? (Type 'done' if there are no more.)")
    kitchen.append(ingredients)
    if ingredients == "done":
        kitchen.remove("done")
        done = True
        
if "tuna" in kitchen:
    kitchen.remove("tuna")
    
while count_s!=3:
    sand=random.randint(0, len(kitchen) -1)
    thing=kitchen[sand]
    sammich.append(thing)
    count_s+=1
    

    
print("How about a "+str(sammich)+ " sandwich?")
    


