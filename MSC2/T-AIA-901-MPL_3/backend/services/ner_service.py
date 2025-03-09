from transformers import AutoTokenizer, AutoModelForTokenClassification
import torch

class NERService:
    def __init__(self, model_name):
        self.model_name = model_name
        self.tokenizer = AutoTokenizer.from_pretrained(model_name)
        self.model = AutoModelForTokenClassification.from_pretrained(model_name)
        self.label_list = ["O", "B-START", "I-START", "B-END", "I-END"]

    # Function to make predictions
    def predict_ner(self, text):
        tokens = self.tokenizer(text, return_tensors="pt", truncation=True)
        with torch.no_grad():
            outputs = self.model(**tokens)
        predictions = torch.argmax(outputs.logits, dim=2)
        predicted_labels = [self.label_list[prediction] for prediction in predictions[0].numpy()]
        tokens = self.tokenizer.convert_ids_to_tokens(tokens["input_ids"][0])

        # Extract and merge START and END labels
        start_tokens = []
        end_tokens = []
        current_start = []
        current_end = []

        for token, label in zip(tokens, predicted_labels):
            if token in ["[SEP]", "[CLS]"]:
                continue
            token = token.replace('▁', '')  # Replace ▁ with space
            if "START" in label:
                    current_start.append(token)
            elif "END" in label:
                    current_end.append(token)
        # Handle any remaining tokens
        if current_start:
            start_tokens.append(" ".join(current_start))
        if current_end:
            end_tokens.append(" ".join(current_end))

        return {"departure": start_tokens[0], "arrival": end_tokens[0]}