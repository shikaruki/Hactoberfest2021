# Planet Weight and Age calculator

# Age
# The amount of time a planet takes to revolve around the sun is know as one year. The amount of time it takes for a planet to rotate on it's axis is considered as one day.
# The age of a person on earth (in days) is divided by the number of days in a year of the respective planets.
    # Planet	Rotation Period	    Revolution Period
    # Mercury	58.6 days	        87.97 days
    # Venus	    243 days	        224.7 days
    # Earth	    0.99 days	        365.26 days
    # Mars	    1.03 days	        1.88 years
    # Jupiter	0.41 days	        11.86 years
    # Saturn	0.45 days	        29.46 years
    # Uranus	0.72 days	        84.01 years
    # Neptune	0.67 days	        164.79 years
    # Pluto	    6.39 days	        248.59 years

# Weight
# Weight is the product of the mass of the planet and it's surface gravity.
# The mass of a person is multiplied by the planets surface gravity to find a person's weight.
    # Planet        Surface Gravity
    # Mercury	0.378g
    # Venus	    0.907g
    # Mars	    0.166g
    # Jupiter	2.36g
    # Saturn	0.916g
    # Uranus	0.889g
    # Neptune	1.12g
    # Pluto	    0.071g

from datetime import datetime

weight_dict =   {  
            "Mercury":0.378,
            "Venus":0.907,
            "Mars":0.166,
            "Jupiter":2.36,
            "Saturn":0.916,
            "Uranus":0.889,
            "Neptune":1.12,
            "Pluto":0.071
            }


age_dict =   {  
            "Mercury":87.97,
            "Venus":224.7,
            "Mars":686.2,
            "Jupiter":4336.2,
            "Saturn":10731,
            "Uranus":30680.3447,
            "Neptune":59899.7206,
            "Pluto":90490.8
            }

def weight():
    weight = int(input("Enter your weight (kg):"))
    print('''

    ░██╗░░░░░░░██╗███████╗██╗░██████╗░██╗░░██╗████████╗
    ░██║░░██╗░░██║██╔════╝██║██╔════╝░██║░░██║╚══██╔══╝
    ░╚██╗████╗██╔╝█████╗░░██║██║░░██╗░███████║░░░██║░░░
    ░░████╔═████║░██╔══╝░░██║██║░░╚██╗██╔══██║░░░██║░░░
    ░░╚██╔╝░╚██╔╝░███████╗██║╚██████╔╝██║░░██║░░░██║░░░
    ░░░╚═╝░░░╚═╝░░╚══════╝╚═╝░╚═════╝░╚═╝░░╚═╝░░░╚═╝░░░
    ╚═╝░░╚═╝░╚═════╝░╚══════╝
    ''')
    for x in weight_dict:
        planet_weight= round(weight*weight_dict.get(x),10)
        print(f"Weight on {x} is {planet_weight} kg")

def age():
    def get_birthdate():
        #Example:'18/09/2019'
        date_str = input("Enter your birthdate (D/M/Y):")
        
        try:
            date_obj = datetime.strptime(date_str, r'%d/%m/%Y')
        except:
            print("Invalid date. Please enter in the format D/M/Y.")
            date_obj = get_birthdate()
        
        finally:
            return date_obj

    date_obj = get_birthdate()

    def convert_age_in_days(date_obj):
        today = datetime.now()
        delta = (today - date_obj)
        age_in_days = delta.days
        print("Age",age_in_days)
        return age_in_days
    
    age_in_days = convert_age_in_days(date_obj)
    print('''
    ░█████╗░░██████╗░███████╗
    ██╔══██╗██╔════╝░██╔════╝
    ███████║██║░░██╗░█████╗░░
    ██╔══██║██║░░╚██╗██╔══╝░░
    ██║░░██║╚██████╔╝███████╗
    ╚═╝░░╚═╝░╚═════╝░╚══════╝
    ''')
    for x in age_dict:
        planet_age = round(age_in_days/age_dict.get(x),10)
        print(f"Age on {x} is {planet_age} years")


# weight()
print("\n")
age()
