from sklearn.datasets import load_digits
from sklearn.metrics import classification_report, confusion_matrix
from sklearn.model_selection import train_test_split
import numpy as np
import matplotlib.pyplot as plt

def init_params(layer_dims):
    np.random.seed(3)
    params = {}
    L = len(layer_dims)
    
    for l in range(1, L):
        params['W'+str(l)] = np.random.randn(layer_dims[l], layer_dims[l-1]) * 0.01
        params['b'+str(l)] = np.zeros((layer_dims[l], 1))
        
    return params

def sigmoid(Z):
    A = 1 / (1 + np.exp(-Z))
    cache = Z
    return A, cache

def softmax(Z):
    expZ = np.exp(Z - np.max(Z))
    A = expZ / expZ.sum(axis=0, keepdims=True)
    cache = Z
    return A, cache

def forward_prop(X, params):
    A = X
    caches = []
    L = len(params) // 2
    for l in range(1, L):
        A_prev = A
        Z = np.dot(params['W' + str(l)], A_prev) + params['b' + str(l)]
        linear_cache = (A_prev, params['W' + str(l)], params['b' + str(l)])
        A, activation_cache = sigmoid(Z)
        cache = (linear_cache, activation_cache)
        caches.append(cache)
    
    ZL = np.dot(params['W' + str(L)], A) + params['b' + str(L)]
    linear_cache = (A, params['W' + str(L)], params['b' + str(L)])
    AL, activation_cache = softmax(ZL)
    cache = (linear_cache, activation_cache)
    caches.append(cache)
    
    return AL, caches

def cost_function(AL, Y):
    m = Y.shape[1]
    cost = -np.sum(Y * np.log(AL + 1e-8)) / m
    return np.squeeze(cost)

def sigmoid_derivative(Z):
    A, _ = sigmoid(Z)
    return A * (1 - A)

def one_layer_backward(dA, cache, activation='sigmoid'):
    linear_cache, activation_cache = cache
    Z = activation_cache
    
    if activation == 'sigmoid':
        dZ = dA * sigmoid_derivative(Z)
    elif activation == 'softmax':
        dZ = dA  # dA is already the gradient for softmax activation
    
    A_prev, W, b = linear_cache
    m = A_prev.shape[1]
    
    dW = (1 / m) * np.dot(dZ, A_prev.T)
    db = (1 / m) * np.sum(dZ, axis=1, keepdims=True)
    dA_prev = np.dot(W.T, dZ)
    
    return dA_prev, dW, db

def backprop(AL, Y, caches):
    grads = {}
    L = len(caches)
    m = AL.shape[1]
    Y = Y.reshape(AL.shape)
    
    dAL = AL - Y
    
    current_cache = caches[L - 1]
    grads['dA' + str(L - 1)], grads['dW' + str(L)], grads['db' + str(L)] = one_layer_backward(dAL, current_cache, activation='softmax')
    
    for l in reversed(range(L - 1)):
        current_cache = caches[l]
        dA_prev_temp, dW_temp, db_temp = one_layer_backward(grads["dA" + str(l + 1)], current_cache)
        grads["dA" + str(l)] = dA_prev_temp
        grads["dW" + str(l + 1)] = dW_temp
        grads["db" + str(l + 1)] = db_temp
        
    return grads

def update_parameters(parameters, grads, learning_rate):
    L = len(parameters) // 2
    
    for l in range(L):
        parameters['W' + str(l + 1)] -= learning_rate * grads['dW' + str(l + 1)]
        parameters['b' + str(l + 1)] -= learning_rate * grads['db' + str(l + 1)]
        
    return parameters

def train(X, Y, layer_dims, epochs, lr):
    params = init_params(layer_dims)
    cost_history = []
    
    for i in range(epochs):
        Y_hat, caches = forward_prop(X, params)
        cost = cost_function(Y_hat, Y)
        cost_history.append(cost)
        grads = backprop(Y_hat, Y, caches)
        
        params = update_parameters(params, grads, lr)
        
    return params, cost_history

def predict(X, params):
    A, _ = forward_prop(X, params)
    predictions = np.argmax(A, axis=0)
    return predictions

def main():
    # Load dataset
    digits = load_digits()
    X = digits.data.T
    y = digits.target
    Y = np.eye(10)[y].T
    X_train, X_test, Y_train, Y_test, y_train, y_test = train_test_split(X.T, Y.T, y, test_size=0.2, random_state=42)
    X_train, X_test, Y_train, Y_test = X_train.T, X_test.T, Y_train.T, Y_test.T

    layer_dims = [64, 32, 16, 10]  # Example architecture
    params, cost_history = train(X_train, Y_train, layer_dims, epochs=10000, lr=0.1)
    
    y_pred = predict(X_test, params)
    cm = confusion_matrix(y_test, y_pred)
    
    plt.figure(figsize=(10, 7))
    plt.imshow(cm, interpolation='nearest', cmap=plt.cm.Blues)
    plt.title('Confusion Matrix')
    plt.colorbar()
    tick_marks = np.arange(10)
    plt.xticks(tick_marks, digits.target_names, rotation=45)
    plt.yticks(tick_marks, digits.target_names)
    
    plt.xlabel('Predicted Label')
    plt.ylabel('True Label')
    
    for i in range(cm.shape[0]):
        for j in range(cm.shape[1]):
            plt.text(j, i, format(cm[i, j], 'd'), horizontalalignment="center", color="white" if cm[i, j] > cm.max()/2 else "black")
    
    plt.show()

if __name__ == '__main__':
    main()