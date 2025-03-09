import streamlit as st
import json
import requests
import pandas as pd
from st_audiorec import st_audiorec
import whisper
import librosa
import soundfile as sf
import io

def transcribe_and_notify(audio):
    model = whisper.load_model("medium")
    
    audio_bytes = io.BytesIO(audio)
    audio_data, _ = librosa.load(audio_bytes, sr=16000)
    result = model.transcribe(audio_data)
    text = result['text']
    return text

st.title('NER Demo')

text = st.text_area('Où veux-tu aller ?')
# Add a switch to select the service
service = st.selectbox('Select service', ['ner', 'llm'])

wav_audio_data = st_audiorec()

if wav_audio_data is not None:
    st.audio(wav_audio_data, format='audio/wav')
    transcribed_text = transcribe_and_notify(wav_audio_data)
    print(transcribed_text)

url = 'http://51.68.191.204:8000/predict'



if st.button('Submit'):
    input_text = transcribed_text if wav_audio_data else text
    params = {'query': input_text, 'service': service}

    response = requests.post(url, params=params)
    data = json.loads(response.text.replace('.', ''))

    if 'result' in data and data['result']:
        df = pd.json_normalize(data['result'], meta=['duration', ['path']])
        if not df.empty:
            df.columns = ['Chemin', 'Durée (minutes)']
            st.dataframe(df)
        else:
            st.write("No data found in the response.")
    else:
        st.write("No result found in the response.")

# Add a file uploader for text files
uploaded_file = st.file_uploader("Choose a text file (separated by ',')", type="txt")

if uploaded_file is not None:
    # Read the content of the file
    file_content = uploaded_file.read().decode("utf-8")
    st.write("File content:")
    st.write(file_content)

    # Split the content into multiple queries (e.g., by commas)
    queries = file_content.split(',')

    # Send each query to the server
    results = []
    for query in queries:
        params = {'query': query, 'service': service}
        response = requests.post(url, params=params)
        data = json.loads(response.text.replace('.', ''))
        if 'result' in data and data['result']:
            results.extend(data['result'])  # Flatten the list of results

    # Display the results
    if results:
        df = pd.json_normalize(results)
        if not df.empty:
            df.columns = ['Chemin', 'Durée (minutes)']
            st.dataframe(df)
        else:
            st.write("No data found in the response.")
    else:
        st.write("No result found in the response.")