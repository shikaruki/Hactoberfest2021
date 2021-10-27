import pyttsx3 #pip install pyttsx3
import speech_recognition as sr #pip install speechRecognition
import datetime
import wikipedia #pip install wikipedia
import webbrowser
import PyPDF2
import tkinter as tk
from tkinter import Variable, filedialog

# import pyaudio
root = tk.Tk()
root.withdraw()

engine = pyttsx3.init('sapi5')
voices = engine.getProperty('voices')
# print(voices[1].id)
engine.setProperty('voice', voices[1].id)


# def file():
#    # path of the PDF file
#     path = filedialog.askopenfilename()
#     print(path)

def speak(audio):
    engine.say(audio)
    engine.runAndWait()


def wishMe():
    speak("Please Enter Your Name:- ")
    print("Enter Here:- ")
    name = input("")
    hour = int(datetime.datetime.now().hour)
    if hour>=0 and hour<12:
        speak("Good Morning! {}".format(name))

    elif hour>=12 and hour<18:
        speak("Good Afternoon! {}".format(name))

    else:
        speak("Good Evening! {}".format(name))  

    speak("I am Turtle. Please tell me how may I help you")   
  
def pdfspeak():
    # speak("Please Select Your File ")
    path = filedialog.askopenfilename()
    print(path)
    # creating a PdfFileReader object
    pdfReader = PyPDF2.PdfFileReader(path)
  
# the page with which you want to start
# this will read the page of 25th page.
    from_page = pdfReader.getPage(0)
  
# extracting the text from the PDF
    text = from_page.extractText()
    engine = pyttsx3.init('sapi5')
# reading the text
    voices = engine.getProperty('voices')
# print(voices[1].id)
    engine.setProperty('voice', voices[1].id)
    speak = pyttsx3.init()
    speak.say(text)
    speak.runAndWait() 

def takeCommand():
    #It takes microphone input from the user and returns string output

    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("Listening...")
        r.pause_threshold = 1
        audio = r.listen(source)

    try:
        print("Recognizing...")    
        query = r.recognize_google(audio, language='en-in')
        print(f"User said: {query}\n")

    except Exception as e:
        # print(e)    
        print("Say that again please...")  
        return "None"
    return query

if __name__ == "__main__":
    wishMe() 
    while True:
        query = takeCommand().lower()
        if 'wikipedia' in query:
                speak('Searching Wikipedia...')
                query = query.replace("wikipedia", "")
                results = wikipedia.summary(query, sentences=2)
                speak("According to Wikipedia")
                print(results)
                speak(results)

        elif 'open youtube' in query:
            webbrowser.open("youtube.com")

        elif 'open google' in query:
            webbrowser.open("google.com")

        elif 'the time' in query:
            strTime = datetime.datetime.now().strftime("%H:%M:%S")    
            speak(f"Sir, the time is {strTime}")

        elif 'play book' in query:
            speak("Playing Your Book. Please Select book file to Play")
            pdfspeak()

        elif  'play pdf' in query:
            speak("Playing Your Pdf. Please Select Pdf file to Play")
            pdfspeak()

        elif  'play story' or 'tell story' in query:
            speak("Playing Your Story. Please Select Story file to Play")
            pdfspeak()
        
            
