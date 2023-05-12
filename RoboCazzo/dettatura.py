from gtts import gTTS
from playsound import playsound

with open('speak.txt', 'r') as f:
    text = f.read().strip()

if text:
    tts = gTTS(text, lang='it')
    tts.save('dett.mp3')
    playsound('dett.mp3')



