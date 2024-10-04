from tkinter import *
import math

root = Tk()
root.title("My Enhanced Calculator")
root.geometry("400x600")  


button_bg = "#4CAF50"  
button_fg = "white"
button_hover_bg = "#45a049"  
display_bg = "#2c3e50"  
display_fg = "white"
button_font = ("Helvetica", 16, "bold")
display_font = ("Helvetica", 24)

def create_button(parent, text, row, column, command=None, rowspan=1, columnspan=1):
    btn = Button(parent, text=text, bg=button_bg, fg=button_fg, font=button_font, 
                 command=command, height=2, width=5, relief=RAISED, bd=4)
    btn.grid(row=row, column=column, rowspan=rowspan, columnspan=columnspan, padx=5, pady=5)

    def on_enter(e):
        btn['background'] = button_hover_bg

    def on_leave(e):
        btn['background'] = button_bg

    btn.bind("<Enter>", on_enter)
    btn.bind("<Leave>", on_leave)
    
    return btn

class app(Frame):
    def __init__(self):
        Frame.__init__(self)
        self.pack(expand=YES, fill=BOTH)
        self.master.title("My Enhanced Calculator")

        display = StringVar()
        display.set("")
        
        entry = Entry(self, textvariable=display, font=display_font, relief=RIDGE, bd=20, justify='right', 
                      fg=display_fg, bg=display_bg)
        entry.grid(row=0, column=0, columnspan=4, padx=10, pady=20, sticky="nsew")

        button_definitions = [
            ('7', 1, 0), ('8', 1, 1), ('9', 1, 2), ('/', 1, 3),
            ('4', 2, 0), ('5', 2, 1), ('6', 2, 2), ('*', 2, 3),
            ('1', 3, 0), ('2', 3, 1), ('3', 3, 2), ('-', 3, 3),
            ('0', 4, 0), ('.', 4, 1), ('+', 4, 2), ('=', 4, 3),
            ('CLEAR', 5, 0), ('BACK', 5, 1), ('x^2', 5, 2), ('sqrt', 5, 3),
            ('%', 6, 0)
        ]

        for text, row, column in button_definitions:
            if text == "=":
                create_button(self, text, row, column, lambda s=self, display=display: s.calc(display))
            elif text == "CLEAR":
                create_button(self, text, row, column, lambda display=display: display.set(""))
            elif text == "BACK":
                create_button(self, text, row, column, lambda display=display: display.set(display.get()[:-1]))
            elif text == "sqrt":
                create_button(self, text, row, column, lambda display=display: display.set(str(math.sqrt(float(display.get())))))
            elif text == "x^2":
                create_button(self, text, row, column, lambda display=display: display.set(str(float(display.get())**2)))
            elif text == "%":
                create_button(self, text, row, column, lambda display=display: display.set(str(float(display.get()) / 100)))
            else:
                create_button(self, text, row, column, lambda display=display, char=text: display.set(display.get() + char))

    def calc(self, display):
        try:
            display.set(eval(display.get()))
        except:
            display.set("Error")

if __name__ == '__main__':
    app().mainloop()

icon = PhotoImage(file="YourImageName.YourImageType") 
root.tk.call('wm', 'iconphoto', root._w, icon)  
