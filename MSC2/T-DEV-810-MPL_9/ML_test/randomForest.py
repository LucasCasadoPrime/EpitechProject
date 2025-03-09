import os
import pandas as pd
import numpy as np
import warnings
from PIL import Image
from sklearn.ensemble import RandomForestClassifier
from imblearn.under_sampling import TomekLinks
from imblearn.combine import SMOTETomek
from sklearn.preprocessing import StandardScaler
from sklearn.metrics import confusion_matrix, accuracy_score, f1_score, recall_score, precision_score, roc_curve, auc, precision_recall_curve
from tensorflow.keras.preprocessing.image import ImageDataGenerator
import matplotlib.pyplot as plt

warnings.filterwarnings("ignore")

# Constants
labels = ['PNEUMONIA', 'NORMAL']
img_size = 128

def preprocess_image(img):
    img = img.convert('L')
    img = img.resize((img_size, img_size))
    img = np.array(img) / 255.0
    return img

def load_data(data_dir):
    data = []
    for label in labels:
        path = os.path.join(data_dir, label)
        class_num = labels.index(label)
        for img_name in os.listdir(path):
            if img_name == '.DS_Store':
                continue
            try:
                img_path = os.path.join(path, img_name)
                img = Image.open(img_path)
                img = preprocess_image(img)
                data.append([img, class_num])
            except Exception as e:
                print(f"Error: {e} occurred while processing image: {img_path}")
    return pd.DataFrame(data, columns=['image', 'label'])

print("Loading data...")

train = load_data('./data/train')
test = load_data('./data/test')

X_train = np.stack(train['image'].values)
y_train = np.array(train['label'].tolist())

X_test = np.stack(test['image'].values)
y_test = np.array(test['label'].tolist())

# Add a channel dimension
X_train = X_train.reshape(-1, img_size, img_size, 1)
X_test = X_test.reshape(-1, img_size, img_size, 1)

# Create an ImageDataGenerator for data augmentation
print("Augmenting data...")
datagen = ImageDataGenerator(
    rotation_range=10,
    width_shift_range=0.1,
    height_shift_range=0.1,
    zoom_range=0.1,
    horizontal_flip=True,
    vertical_flip=True,
    brightness_range=[0.5, 1.5]
)

# Initialize an empty list to store augmented data
augmented_data = []

# Generate augmented data batches and concatenate them
batch_size = 256
num_batches = 2  # Number of times to generate augmented data
for _ in range(num_batches):
    for X_batch, y_batch in datagen.flow(X_train, y_train, batch_size=batch_size):
        augmented_data.append(X_batch)
        augmented_data.append(y_batch)
        break

# Concatenate augmented data
X_train_augmented = np.concatenate(augmented_data[::2])
y_train_augmented = np.concatenate(augmented_data[1::2])

X_train = np.concatenate((X_train, X_train_augmented))  
y_train = np.concatenate((y_train, y_train_augmented))

print(f"Train NORMAL images: {len(y_train[y_train == 0])}")
print(f"Train PNEUMONIA images: {len(y_train[y_train == 1])}")

# Reshape data for the model
X_train = X_train.reshape(-1, img_size * img_size)
X_test = X_test.reshape(-1, img_size * img_size)

# Handle class imbalance with SMOTETomek
print("Handling class imbalance...")
resample = SMOTETomek(tomek=TomekLinks(sampling_strategy='majority'))
X_train, y_train = resample.fit_resample(X_train, y_train)

# Define the model
print("Defining model...")
sc = StandardScaler()
rf = RandomForestClassifier(n_estimators=100, random_state=42)
X_train = sc.fit_transform(X_train)
X_test = sc.transform(X_test)

# Train the model
print("Training model...")
rf.fit(X_train, y_train)

# Evaluate the model
print("Evaluating model...")
y_test_pred = rf.predict(X_test)
y_train_pred = rf.predict(X_train)

# Confusion Matrix and Metrics
cm = confusion_matrix(y_test, y_test_pred)
tn, fp, fn, tp = cm.ravel()

print("Confusion Matrix:")
print(cm)
print(f"Train Accuracy: {accuracy_score(y_train, y_train_pred)}")
print(f"Test Accuracy: {accuracy_score(y_test, y_test_pred)}\n")

print(f"Train F1 Score: {f1_score(y_train, y_train_pred)}")
print(f"Test F1 Score: {f1_score(y_test, y_test_pred)}\n")

print(f"Train Recall: {recall_score(y_train, y_train_pred)}")
print(f"Test Recall: {recall_score(y_test, y_test_pred)}")

print(f"Train Precision: {precision_score(y_train, y_train_pred)}")
print(f"Test Precision: {precision_score(y_test, y_test_pred)}")

# False Positives and False Negatives Ratios
print(f"False Positive Rate: {fp / (fp + tn)}")
print(f"False Negative Rate: {fn / (fn + tp)}")

# Combine all data and results into a single DataFrame for export
results = pd.DataFrame({
    'True Labels': y_test,
    'Predicted Labels': y_test_pred
})

results.to_csv('combined_results.csv', index=False)
print("Combined results saved to 'combined_results.csv'")

# Plotting the Confusion Matrix
fig, ax = plt.subplots()
cax = ax.matshow(cm, cmap=plt.cm.Blues)
plt.title('Confusion matrix')
fig.colorbar(cax)
ax.set_xticklabels([''] + labels)
ax.set_yticklabels([''] + labels)
plt.xlabel('Predicted')
plt.ylabel('True')
plt.show()

# ROC Curve
fpr, tpr, _ = roc_curve(y_test, y_test_pred)
roc_auc = auc(fpr, tpr)
plt.figure()
plt.plot(fpr, tpr, color='darkorange', lw=2, label='ROC curve (area = %0.2f)' % roc_auc)
plt.plot([0, 1], [0, 1], color='navy', lw=2, linestyle='--')
plt.xlim([0.0, 1.0])
plt.ylim([0.0, 1.05])
plt.xlabel('False Positive Rate')
plt.ylabel('True Positive Rate')
plt.title('Receiver Operating Characteristic')
plt.legend(loc="lower right")
plt.show()

# Precision-Recall Curve
precision, recall, _ = precision_recall_curve(y_test, y_test_pred)
plt.figure()
plt.plot(recall, precision, lw=2, color='b', label='Precision-Recall curve')
plt.xlabel('Recall')
plt.ylabel('Precision')
plt.title('Precision-Recall curve')
plt.legend(loc="lower left")
plt.show()
