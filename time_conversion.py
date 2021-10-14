"""
Converting 12 hours format to 24 hour format
""" 

def Time_Conversion(str_1):
     
    # Identifying the last two elements of time as AM and the first two elements as 12
    if str_1[-2:] == "AM" and str_1[:2] == "12":
        return "00" + str_1[2:-2]
         
    # remove the AM from string  
    elif str_1[-2:] == "AM":
        return str_1[:-2]
     
    # Identifying the last two elements of time as PM and the first two elements as 12  
    elif str_1[-2:] == "PM" and str_1[:2] == "12":
        return str_1[:-2]
    
    # Else - add 12 to hours and remove PM
    else:        
        return str(int(str_1[:2]) + 12) + str_1[2:8]
        
x = "08:05:45PM"
print(Time_Conversion(x))