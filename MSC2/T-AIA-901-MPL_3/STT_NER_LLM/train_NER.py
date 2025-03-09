import pandas as pd
from datasets import Dataset, DatasetDict
from transformers import AutoTokenizer, AutoModelForTokenClassification, TrainingArguments, Trainer
from transformers import DataCollatorForTokenClassification
from seqeval.metrics import classification_report
from transformers import EarlyStoppingCallback

# Load the data
df = pd.read_csv('ner_training_data.csv')

# Convert the data into the format required by the Hugging Face datasets library
def convert_to_hf_format(df):
    tokens = []
    labels = []
    current_tokens = []
    current_labels = []
    
    for _, row in df.iterrows():
        if row['token'] == '?':  # Assuming '?' indicates the end of a sentence
            current_tokens.append(row['token'])
            current_labels.append(row['ner_tag'])
            tokens.append(current_tokens)
            labels.append(current_labels)
            current_tokens = []
            current_labels = []
        else:
            current_tokens.append(row['token'])
            current_labels.append(row['ner_tag'])
    
    if current_tokens:
        tokens.append(current_tokens)
        labels.append(current_labels)
    
    return tokens, labels

tokens, labels = convert_to_hf_format(df)

# Debug prints to check the data
print(f"Number of samples: {len(tokens)}")
print(f"First sample tokens: {tokens[0] if tokens else 'No tokens'}")
print(f"First sample labels: {labels[0] if labels else 'No labels'}")

# Create a Hugging Face dataset
dataset = Dataset.from_dict({"tokens": tokens, "ner_tags": labels})

# Check the dataset
print(dataset)

# Split the dataset into train and test sets
if len(tokens) > 1:
    dataset = dataset.train_test_split(test_size=0.2)
else:
    raise ValueError("Not enough samples to split into train and test sets.")

# Define the label list
label_list = ["O", "B-START", "I-START", "B-END", "I-END"]

# Load the tokenizer and model
model_name = "distilbert-base-uncased"
tokenizer = AutoTokenizer.from_pretrained(model_name)
model = AutoModelForTokenClassification.from_pretrained(model_name, num_labels=len(label_list))

# Tokenize the dataset
def tokenize_and_align_labels(examples):
    tokenized_inputs = tokenizer(examples["tokens"], truncation=True, is_split_into_words=True)
    labels = []
    for i, label in enumerate(examples["ner_tags"]):
        word_ids = tokenized_inputs.word_ids(batch_index=i)
        previous_word_idx = None
        label_ids = []
        for word_idx in word_ids:
            if word_idx is None:
                label_ids.append(-100)
            elif word_idx != previous_word_idx:
                label_ids.append(label[word_idx])
            else:
                label_ids.append(-100)
            previous_word_idx = word_idx
        labels.append(label_ids)
    tokenized_inputs["labels"] = labels
    return tokenized_inputs

tokenized_datasets = dataset.map(tokenize_and_align_labels, batched=True)

# Define the data collator
data_collator = DataCollatorForTokenClassification(tokenizer)

# Define the training arguments with weight decay and early stopping
training_args = TrainingArguments(
    output_dir="./results",
    evaluation_strategy="epoch",
    save_strategy="epoch",  # Ensure save strategy matches evaluation strategy
    learning_rate=2e-5,
    per_device_train_batch_size=16,
    per_device_eval_batch_size=16,
    num_train_epochs=3,
    weight_decay=0.01,
    load_best_model_at_end=True,
    metric_for_best_model="eval_loss",
    greater_is_better=False,
)

# Define the trainer
def compute_metrics(p):
    predictions, labels = p
    predictions = predictions.argmax(axis=-1)
    true_labels = [[label_list[l] for l in label if l != -100] for label in labels]
    true_predictions = [
        [label_list[p] for (p, l) in zip(prediction, label) if l != -100]
        for prediction, label in zip(predictions, labels)
    ]
    return classification_report(true_labels, true_predictions, output_dict=True)

trainer = Trainer(
    model=model,
    args=training_args,
    train_dataset=tokenized_datasets["train"],
    eval_dataset=tokenized_datasets["test"],
    tokenizer=tokenizer,
    data_collator=data_collator,
    compute_metrics=compute_metrics,
    callbacks=[EarlyStoppingCallback(early_stopping_patience=3)]
)

# Train the model
trainer.train()

# Save the model
model.save_pretrained("./ner_model")
tokenizer.save_pretrained("./ner_model")