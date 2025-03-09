import gradio as gr
from transformers import AutoTokenizer, AutoModelForTokenClassification
import torch

# Load the trained model and tokenizer
model_name = "Crysy-rthomas/T-AIA-CamemBERT-V1"  # Path to the directory where the model is saved
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

    # Extract and merge START and END labels
    start_tokens = []
    end_tokens = []
    current_start = []
    current_end = []

    for token, label in zip(tokens, predicted_labels):
        if token in ["[SEP]", "[CLS]"]:
            continue
        token = token.replace('▁', ' ')  # Replace ▁ with space
        if "START" in label:
                current_start.append(token)
        elif "END" in label:
                current_end.append(token)
        else:
            if current_start:
                start_tokens.append(" ".join(current_start))
                current_start = []
            if current_end:
                end_tokens.append(" ".join(current_end))
                current_end = []

    # Handle any remaining tokens
    if current_start:
        start_tokens.append(" ".join(current_start))
    if current_end:
        end_tokens.append(" ".join(current_end))

    # Format the result as a table
    table = "<table><tr><th>START</th><th>END</th></tr>"
    max_len = max(len(start_tokens), len(end_tokens))
    for i in range(max_len):
        start = start_tokens[i] if i < len(start_tokens) else ""
        end = end_tokens[i] if i < len(end_tokens) else ""
        table += f"<tr><td>{start}</td><td>{end}</td></tr>"
    table += "</table>"

    return table

# Create the Gradio interface
iface = gr.Interface(
    fn=predict_ner,
    inputs="text",
    outputs="html",
    title="Named Entity Recognition (NER) Demo",
    description="Enter a sentence to see the named entity recognition results."
)

# Launch the interface
if __name__ == "__main__":
    iface.launch(share=True)