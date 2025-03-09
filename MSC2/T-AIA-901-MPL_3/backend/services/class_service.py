from transformers import pipeline


class CLASSService:
    def __init__(self, model_name):
        self.model_name = model_name
        self.classifier = pipeline(
            "text-classification", model=model_name, tokenizer=model_name, framework="tf"
        )

    def predict_class(self, text):

        predictions = self.classifier(text)

        label = predictions[0]["label"]

        return label
