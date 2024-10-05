import pyttsx3
 
converter = pyttsx3.init() 
voice_id = "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\Voices\Tokens\TTS_MS_EN-US_ZIRA_11.0"
  
# Use female voice
converter.setProperty('voice', voice_id)
converter.setProperty('rate', 150)

# Set volume 0-1
converter.setProperty('volume', 0.7)
  
converter.say("Hey, how's your day?")  #type the text to speak here
 
converter.runAndWait()
