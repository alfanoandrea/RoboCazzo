import speech_recognition as sr
import os

r = sr.Recognizer()
with sr.Microphone() as source:
    print("Calibrazione del microfono in corso... attendere qualche secondo...")
    r.adjust_for_ambient_noise(source, duration=5)

