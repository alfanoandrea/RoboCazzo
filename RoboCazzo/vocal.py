import speech_recognition as sr
import os

r = sr.Recognizer()
while True:
    with sr.Microphone() as source:
        audio = r.listen(source, timeout=2, phrase_time_limit=2)
        text = r.recognize_google(audio, language='it-IT')
        with open('output.txt', 'w') as f:
            f.write(text)
        break

