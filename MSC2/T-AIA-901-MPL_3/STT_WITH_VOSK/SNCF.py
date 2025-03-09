import os
import json
import pyaudio
from vosk import Model, KaldiRecognizer
import openai
from dotenv import load_dotenv

load_dotenv()
openai.api_key = os.getenv("OPENAI_API_KEY")

model_path = 'model-fr-big'
if not os.path.exists(model_path):
    print(f"Erreur : le chemin vers le modèle Vosk '{model_path}' n'existe pas.")
    exit(1)
    
model = Model(model_path)
p = pyaudio.PyAudio()
stream = p.open(format=pyaudio.paInt16, channels=1, rate=16000, input=True, frames_per_buffer=8192)
recognizer = KaldiRecognizer(model, 16000)

def speak_say(text):
    print(f"[TTS] Parler : {text}")
    os.system(f'say "{text}"')

def listen_and_recognize():
    print("[STT] Prêt à écouter, appuyez sur 'Enter' pour continuer...")
    input()
    print("[STT] Écoute...")
    while True:
        try:
            data = stream.read(4096, exception_on_overflow=False)
            if recognizer.AcceptWaveform(data):
                result = json.loads(recognizer.Result())
                text = result.get('text', '')
                if text:
                    print(f"[STT] Texte reconnu : {text}")
                    return text
        except IOError as e:
            print("[STT] Overflow, continuez à parler...")
            continue

def generate_response(text):
    print("[GPT-3.5] Analyse des informations de voyage...")
    try:
        response = openai.ChatCompletion.create(
            model="gpt-3.5-turbo",
            messages=[
                {"role": "system", "content": "Vous êtes un assistant conçu pour extraire les détails de voyage comme la ville de départ, la ville d'arrivée, la date et l'heure."},
                {"role": "user", "content": text}
            ]
        )
        response_text = response['choices'][0]['message']['content']
        print(f"[GPT-3.5] Réponse : {response_text}")
        return response_text
    except Exception as e:
        print(f"Erreur lors de la génération de la réponse : {e}")
        return "Une erreur s'est produite lors de l'analyse des informations."


def main():
    while True:
        text = listen_and_recognize()
        if text:
            response_text = generate_response(text)
            speak_say(response_text)

if __name__ == "__main__":
    try:
        main()
    finally:
        if stream.is_active():
            stream.stop_stream()
        if stream.is_open():
            stream.close()
        p.terminate()
