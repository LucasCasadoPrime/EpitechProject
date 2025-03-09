import gradio as gr
from transformers import pipeline

# Load the trained model and tokenizer
model = "InesPL84/T-AIA-DISTILCAMEMBERT-BASE-TEXT-CLASSIFICATION"
classifier = pipeline("text-classification", model=model, tokenizer=model)

def predict(text):
    predictions = classifier(text)
    label = predictions[0]['label']
    score = predictions[0]['score']
    return {'label': label, 'score': score}

# Create the Gradio interface
iface = gr.Interface(
    fn=predict,
    inputs="text",
    outputs="json",
)

# Launch the interface
if __name__ == "__main__":
    iface.launch(share=True)