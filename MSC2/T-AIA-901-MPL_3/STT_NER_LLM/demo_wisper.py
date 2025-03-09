from firework_service import FireworksService
import gradio as gr
import whisper

# Initialize Whisper model
model = whisper.load_model("medium")

# Initialize Firework (You'll need your Firework credentials here)
firework_service = FireworksService()

def transcribe_and_notify(audio):
    # Use Whisper to transcribe the audio
    result = model.transcribe(audio)
    text = result['text']
    
    # Send the transcribed text to Firework
    response = firework_service.inference([{"role": "user", "content": text}]
    )
    
    return text, response

# Set up Gradio interface
iface = gr.Interface(
    fn=transcribe_and_notify,
    inputs=gr.Audio(type="filepath"),
    outputs=["text", "text"],  # Display both the transcription and Firework response
    title="Whisper Transcription with Firework",
    description="Transcribe audio using Whisper and send it as a notification via Firework."
)

# Launch the Gradio app
iface.launch()
