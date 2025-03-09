import gradio as gr
from transformers import AutoTokenizer, AutoModelForTokenClassification
import torch

# Load the trained model and tokenizer
model_name = "../models/ner_v2"  # Path to the directory where the model is saved
tokenizer = AutoTokenizer.from_pretrained(model_name)
model = AutoModelForTokenClassification.from_pretrained(model_name)

# Define the label list
label_list = ["O", "B-START", "I-START", "B-END", "I-END"]

# Function to make predictions
def predict_ner(text):
    tokens = tokenizer(text, return_tensors="pt", truncation=True)
    with torch.no_grad():
        outputs = model(**tokens)
    predictions = torch.argmax(outputs.logits, dim=2)
    predicted_labels = [label_list[prediction] for prediction in predictions[0].numpy()]
    tokens = tokenizer.convert_ids_to_tokens(tokens["input_ids"][0])
    result = [(token, label) for token, label in zip(tokens, predicted_labels)]
    return result

# Create the Gradio interface
iface = gr.Interface(
    fn=predict_ner,
    inputs="text",
    outputs="json",
    title="Named Entity Recognition (NER) Demo",
    description="Enter a sentence to see the named entity recognition results."
)

# Launch the interface
if __name__ == "__main__":
    iface.launch()