import requests
import instaloader
import webbrowser

username = input("enter username:")
webbrowser.open(f'www.instagram.com/{username}')
time.sleep(5)
condition = TackInput().lower()
if "yes" in condition:
    bot = instaloader.Instaloader()
    bot.download_profile(username,profile_pic_only=True)
    #print('sir profile photo is downloaded)
