from sklearn.datasets import load_breast_cancer
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn.preprocessing import StandardScaler
from sklearn.metrics import confusion_matrix, classification_report
import seaborn as sns
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

bc = load_breast_cancer()

X, y = bc.data, bc.target


def print_target_count(y):
    unique_classes, class_counts = np.unique(y, return_counts=True)
    for cls, count in zip(unique_classes, class_counts):
        print(f"Classe {cls}: {count} échantillons")


def coef_correlation(X, y):
    num_features = X.shape[1]
    for i in range(num_features):
        feature_values = X[:, i]
        correlation = np.corrcoef(feature_values, y)[0, 1]
        print(f"Caractéristique {i+1}: {correlation}")

def head(X, y):
    df = pd.DataFrame(X, columns=bc.feature_names)
    df['target'] = y
    print(df.head())


if __name__ == "__main__":
    head(X, y)
    print()
    print_target_count(y)
    print()
    coef_correlation(X, y)
    print()

    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2)
    
    sc = StandardScaler()
    X_train = sc.fit_transform(X_train)
    X_test = sc.transform(X_test)

    rf = RandomForestClassifier(n_estimators=400)
    rf.fit(X_train, y_train)


    y_pred = rf.predict(X_test)

    print(confusion_matrix(y_test, y_pred))
    print(classification_report(y_test, y_pred))

