from tkinter import *
from tkinter import messagebox
from tkinter.ttk import Combobox
import datetime

# Croma section
def cromad():
    root1 = Toplevel()

    def generate_bill():
        bill = Frame(root1, width=400, height=330)
        bill.place(x=590, y=50)
        bill_title = Label(bill, text='Bill', font='Arial 20')
        bill_title.place(x=180, y=0)
        dt = 'Date Time  ' + str(datetime.datetime.now())
        dt_label = Label(bill, text=dt, font='Arial 15')
        dt_label.place(x=0, y=40)
        
        items = [
            (i1, entry1, "Google Home", 10000, 70),
            (i2, entry2, "Boat rockerz 1100", 5000, 90),
            (i3, entry3, "Lenovo Zuk z2+", 14000, 110),
            (i4, entry4, "iPhone 11", 100500, 130),
            (i5, entry5, "Vivo v11 pro", 18000, 150)
        ]
        
        total = 0
        for idx, (item, entry, name, price, y_pos) in enumerate(items):
            if item.get() == 1:
                quantity = int(entry.get())
                cost = price * quantity
                total += cost
                item_label = Label(bill, text=f'{name:20} Rs.{cost}', font='Arial 12')
                item_label.place(x=0, y=y_pos)
        
        total_label = Label(bill, text=f'Total Rs.{total}', font='Arial 12')
        total_label.place(x=0, y=190)
        
        thank_you = Label(bill, text='Thank you! Your order will be delivered within 4-5 working days.', font='Arial 15')
        thank_you.place(x=50, y=210)
        
        quit_button = Button(root1, text='Exit', command=root1.destroy, font='Times 12')
        quit_button.place(x=770, y=390)

    def create_entry(idx, y_pos):
        quantity_label = Label(root1, text='Quantity', bg='light blue', font='Miriam 15', fg='red')
        quantity_label.place(x=350, y=y_pos)
        entry = Entry(root1)
        entry.place(x=420, y=y_pos + 5)
        return entry

    root1.configure(bg='light blue')
    root1.geometry('900x600+150+150')
    root1.title('Croma')
    title = Label(root1, text='Welcome To Croma', font='Arial 30', bg='light blue')
    title.pack()

    i1, i2, i3, i4, i5 = IntVar(), IntVar(), IntVar(), IntVar(), IntVar()
    entry1, entry2, entry3, entry4, entry5 = None, None, None, None, None

    items_info = [
        (i1, 'Google Home Rs.10000', 50, create_entry),
        (i2, 'Boat rockerz 1100 Rs.5000', 80, create_entry),
        (i3, 'Lenovo Zuk z2+ Rs.14000', 110, create_entry),
        (i4, 'iPhone 11 Rs.100500', 140, create_entry),
        (i5, 'Vivo v11 pro Rs.18000', 170, create_entry)
    ]

    for idx, (var, text, y_pos, entry_fn) in enumerate(items_info):
        check_btn = Checkbutton(root1, text=text, font='Courier 12', bg='light blue', fg='blue', variable=var, command=lambda idx=idx: globals()[f'entry{idx+1}'] = entry_fn(idx, y_pos))
        check_btn.place(x=0, y=y_pos)

    next_button = Button(root1, text='Next', font='Courier', fg='blue', command=generate_bill)
    next_button.place(x=100, y=200)

    disc = Canvas(root1, width=225, height=225, bg='light blue')
    disc.place(x=30, y=250)
    disc_img = PhotoImage(file='./disc.png')
    disc.create_image(0, 0, image=disc_img, anchor=NW)

    root1.mainloop()

# Similar structure for wranglerd() and mc() can be applied if needed

def mains(x):
    root = Toplevel()
    root.title('Desidime')
    root.configure(bg='yellow')
    root.geometry('600x900+150+10')
    welcome = Label(root, text='Welcome', font='Century 50', bg='yellow')
    welcome.place(x=540, y=5)

    canvas = Canvas(root, width=600, height=230, bg='violet')
    canvas.place(x=30, y=100)
    f1 = Label(canvas, text='Electronics', font='Century 25', bg='orange', relief='solid')
    f1.place(x=230, y=5)

    croma_img = PhotoImage(file='./croma.png')
    canvas.create_image(200, 60, image=croma_img, anchor=NW)
    croma_btn = Button(canvas, text='Tap to enter', font='Comic 15', fg='red', command=cromad)
    croma_btn.place(x=240, y=180)

    root.mainloop()
