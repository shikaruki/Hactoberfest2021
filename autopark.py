menu_msg = {
    1: "add new car",
    2: "edit car data",
    3: "view data",
    4: "add/remove movement info", 
    5: "amount of fuel spent on a particular date",
    6: "fuel consumption rating", 
    7: "exit"
}

data = [ # add some data to test the code
    {
        "brand": "Toyota",
        "number": "AE1256BO",
        "fuel_tank": 70,
        "fuel_consumption": 10,
        "movements": [
            {
                "date": "13/09/2021",
                "dist": "20"
            },
            {
                "date": "04/10/2021",
                "dist": "35"
            }
        ]

    },
    {
        "brand": "Mazda",
        "number": "AE6525CA",
        "fuel_tank": 120,
        "fuel_consumption": 15,
        "movements": [
            {
                "date": "13/09/2021",
                "dist": "50"
            },
            {
                "date": "13/09/2021",
                "dist": "29"
            }
        ]

    },
]

def add_new_car(car={}): 
    car['brand'] = input("please enter brand name: ")
    car['number'] = input("please enter car number: ")
    car['fuel_tank'] = int(input("please enter fuel tank size (liters): "))
    car['fuel_consumption'] = int(input("please enter fuel consumption (per 100km): "))
    car['movements'] = []
    data.append(car)
    return "Car added." 


def choose_car_menu(): # show a list of every car, if input index exists, return this index
    print("Choose car: ")
    for i, b in enumerate(data):
        print(f"{i} - {list(b.values())[0]} {list(b.values())[1]}") # display index, brand and car number
    inp = input()
    if inp.isdigit() and int(inp) <= len(data):
        inp = int(inp)
        return inp
    else:
        print("There's no such car in the database")


def view_data(i): # view all car data by index, return index 
    car = data[i]
    for item, value in car.items():
        if isinstance(value, list): # check if value is list with all car movement dicts
            for date, dist in [d.values() for d in value]: # unpack every dict in list
                print(f"\t{date} -> {dist} km") # display k, v
        else: # if it's not list, just display k, v
            print(f"\t{item} -> {value}")
    return inp


def edit_car(i): # edit any kind of car data
    car = data[i]
    arg = input("What do you want to edit? (brand, number, fuel_tank, fuel_consumption, movements)\n>")
    if arg in car.keys() and arg != "movements": # movements is harder to edit, so firstly check for other values
        new_value = input("Please enter new value: ")
        if new_value.isdigit(): # keep all integer values being integers
            car[arg] = int(new_value)
        else:
            car[arg] = new_value # if not int, let it be string
    elif arg == "movements": # call another func to edit movements
        edit_car_movements(i)


def edit_car_movements(i):
    def add_departure(): # add new movement, departure
        date = input("Please enter a date in this format: dd/mm/yyyy\n>")
        dist = input("Please enter distance:\n>")
        if (list_dates(i).count(date) < 2  and dist.isdigit()): # check if there are any departures on same date
            dct = {
                "date": date,
                "dist": dist
            }
            car["movements"].append(dct)
        else:
            print("There can't be more than 2 departures on the same date.")

    car = data[i]

    for i, v in enumerate(car["movements"]):
        print(f"\t{i} -> {v}")

    inp = input("(a)dd, (d)elete or (e)dit?")
    if inp.lower() == "a":
        add_departure()
        
    elif inp.lower() == "d":
        to_delete = int(input("Which departure do you want to delete? (enter a number)\n>"))
        if to_delete <= len(car["movements"]): # check if there is such index
            car["movements"].pop(to_delete) # just pop by index

    elif inp.lower() == "e":
        to_edit = int(input("Which departure do you want to edit? (enter a number)\n>"))
        if to_edit <= len(car["movements"]):
            car["movements"].pop(to_edit)  
        add_departure()
        
            
def list_dates(i): # make a list of dates to easily count them, check if there are same dates
    car = data[i]
    dates = []
    for date, dist in [d.values() for d in car["movements"]]:
        dates.append(date)
    return dates


def fuel_spent_on_date(date):
    summary = 0
    for car in data:
        consumption = car["fuel_consumption"]
        for day, dist in [d.values() for d in car["movements"]]:
            if day == date: # if input date equals some date in movements list
                summary += float((100/consumption)) * float(dist) # calculates consumption for 1km, multiplies it by distance
    return summary


def sort_by_consumption():
    rating = [] 
    for car in data:
        brand = car["brand"]
        consumption = car["fuel_consumption"]
        rating.append((brand, consumption))
    rating.sort(key=lambda tup: tup[1], reverse=True) # sort tuples by fuel consumption and reverse to make a top
    return rating


while 1:
    for k, v in menu_msg.items():
        print(f"{k} -> {v}") # just prints out the menu
    inp = input("\n") 
    if inp.isdigit():
        inp = int(inp)
        if inp == 1: # add new car
            print(f"{inp} -> {menu_msg.get(inp)}\n") # show chosen option
            add_new_car()
            print("\n")

        elif inp == 2: # edit car
            print(f"{inp} -> {menu_msg.get(inp)}\n")
            edit_car(choose_car_menu())
            print("\n")

        elif inp == 3: # view cars data
            print(f"{inp} -> {menu_msg.get(inp)}\n")
            view_data(choose_car_menu())
            print("\n")

        elif inp == 4: # edit car movements
            print(f"{inp} -> {menu_msg.get(inp)}")
            edit_car_movements(choose_car_menu())
            print("\n")

        elif inp == 5: # show how much fuel was spent on date
            print(f"{inp} -> {menu_msg.get(inp)}")
            date = input("Please enter a date in this format: dd/mm/yyyy\n>")    
            print(fuel_spent_on_date(date))
            print("\n")

        elif inp == 6: # prints a top of cars by fuel consumption rates
            print(f"{inp} -> {menu_msg.get(inp)}")
            print(*sort_by_consumption())
            print("\n")
        else:
            break
    else:
        print("\nThere's no such command.\n")

