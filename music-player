import pygame
import tkinter as tkr
from tkinter.filedialog import askdirectory
import os

musicplayer =tkr.Tk()

musicplayer.title("music player")

musicplayer.geometry("450x350")

directory = askdirectory()

os.chdir(directory)

songlist = os.listdir()

playlist = tkr.Listbox(musicplayer, font = "canbria 14 bold", bg = "cyan2", selectmode = tkr.SINGLE)

for item in songlist:
    pos=0
    playlist.insert(pos, item)
    pos= pos + 1

pygame.init()
pygame.mixer.init()

def play ():
    pygame.mixer.music.load(playlist.get(tkr.ACTIVE))
    var.set(playlist.get(tkr.ACTIVE))
    pygame.mixer.music.play()

def exitmusicplayer():
    pygame.mixer.music.stop()

def pause():
    pygame.mixer.music.pause()

def resume():
    pygame.mixer.music.unpause

Button_play = tkr.Button(musicplayer,width=5,height=3,font="cambria 20 bold", text="play music", command=play , bg="lime green", fg="black")
Button_stop = tkr.Button(musicplayer,width=5,height=3,font="cambria 20 bold", text="stop music",command=exitmusicplayer, bg="red", fg="black")
Button_pause = tkr.Button(musicplayer,width=5,height=3,font="cambria 16 bold", text="pause music",command=pause, bg="yellow",fg="black")
Button_resume = tkr.Button(musicplayer,width=5,height=3,font="cambria 16 bold", text="resume music",command=resume, bg="skyblue", fg="black")

var = tkr.StringVar()
songtitle = tkr.Label(musicplayer, font="Helvetica 12 bold", textvariable=var)
songtitle.pack()

Button_play.pack(fill="x")
Button_stop.pack(fill="x")
Button_pause.pack(fill="x")
Button_resume.pack(fill="x")
playlist.pack(fill="both", expand="yes")

musicplayer.mainloop()
