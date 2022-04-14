from tkinter import * 
import tkinter as tk
import xlsxwriter as xl
import pandas as pd
import os

pg_root=Tk();
pg_root.geometry("844x723")
pg_root.title("ATTENDANCE SHEET")

def creat_lst(info):
    my_lst=[]
    dic={}
    for line in info:
        for i in line:
            if i=="_":
                tmp=""
                enr=""
                count=0
                for j in line:
                    if j!="_":
                        tmp+=j
                        count+=1
                    else:
                        count+=1
                        while count < len(line):
                            enr+=line[count]
                            count+=1
                        dic[tmp]=enr    

    return dic


def Take_input():
    if os.path.exists('Example.xlsx'):
        os.remove("Example.xlsx")  
    workbook=xl.Workbook('Example.xlsx')
    worksheet=workbook.add_worksheet()
    row=0
    col=0
    lst=[]
    INPUT = inputtxt.get("1.0", "end-1c")
    inputtxt.delete("1.0","end")
    lst=INPUT.split("\n")
    lst1=creat_lst(lst)
    for item,value in lst1.items():
        worksheet.write(row,col,item)
        worksheet.write(row,col+1,value)
        row+=1
    workbook.close()
    
def view_data():
    path='Example.xlsx'
    isExst=os.path.exists(path)
    if isExst:        
        df=pd.read_excel("Example.xlsx")
        
        print(df.head(0))
        inpt1.delete("1.0","end")
        inpt1.insert(END,df)
        title_lebel2.pack()
        inpt1.pack()
    else:
        inpt1.insert(END,"There is no any content available at now!")
        inpt1.pack()

        
title_lebel=Label(text="PLEASE INPUT THE DATA ",font="comicsense 14 bold")
inputtxt = Text(pg_root,height = 10,width = 100,bg = "light yellow",fg="black",borderwidth=3,relief=SUNKEN)
inpt1=Text(pg_root,height=11,width=50,bg="green",fg="white",borderwidth=3,relief=SUNKEN,padx=0)

b1 = Button(pg_root,text="Submit",width = 30,bg = "light cyan",
            command = lambda:Take_input())
b2 = Button(pg_root, text = "Exit",width =30,bg = "light cyan",
            command = pg_root.destroy) 

#Output = Text(pg_root, height = 5,width =50,bg = "lightcyan")
b3=Button(pg_root,text="Export the excel data Sheet",width=50,bg="lightcyan",command=lambda:view_data())

title_lebel2=Label(text="VIEW THE DATA FOR COMFORMATION ",font="comicsense 10 bold")

title_lebel.pack(pady=50)
inputtxt.pack(pady=0)
b1.pack(padx=160,pady=30)
b2.pack(padx=90)
b3.pack(pady=20)


pg_root.mainloop()



