import os
from PIL import Image
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.svm import SVC
from sklearn.metrics import recall_score, precision_score, f1_score, accuracy_score
from sklearn.metrics import confusion_matrix


categories = ['NORMAL', 'PNEUMONIA']
images = []
labels = []

target_size = (150, 150)

def preprocess_image(img):
    img = img.convert('L')
    img = img.resize(target_size)
    img_array = np.array(img)
    return img_array

def load_data(data_dir):
    for label, category in enumerate(categories):
        category_dir = os.path.join(data_dir, category)
        for filename in os.listdir(category_dir):
            if filename.endswith('.jpeg'):
                img_path = os.path.join(category_dir, filename)
                with Image.open(img_path) as img:
                    img_array = preprocess_image(img)
                    images.append(img_array)
                    labels.append(label)

def main():
    print("Loading data...")
    load_data('../data')
    print("Data loaded")
    
    images_np_flatten = np.array(images).reshape(len(images), -1)

    x_train, x_test, y_train, y_test = train_test_split(images_np_flatten, labels, test_size=0.2, random_state=42)

    print("Training model...")
    model = SVC()
    model.fit(x_train, y_train)
    print("Model trained")

    y_pred_train = model.predict(x_train)
    y_pred_test = model.predict(x_test)

    print("Train recall:", recall_score(y_train, y_pred_train))
    print("Test recall:", recall_score(y_test, y_pred_test))

    print("Confusion matrix:")
    print(confusion_matrix(y_test, y_pred_test))

if __name__ == '__main__':
    main()