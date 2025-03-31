from matrice_mng import *

def exp(tab):
    tmp = identity_mat(len(tab))
    for i in range(1, 50):
        tmp = add_mat(tmp, div_mat(pow_mat(tab, i), factorial(i)))
    return tmp

def cos(tab):
    tmp = identity_mat(len(tab))
    for i in range(1, 40):
        if i % 2 == 0:
            tmp = add_mat(tmp, div_mat(pow_mat(tab, 2 * i), factorial(2 * i)))
        else:
            tmp = sub_mat(tmp, div_mat(pow_mat(tab, 2 * i), factorial(2 * i)))
    return tmp

def sin(tab):
    tmp = tab
    for i in range(1, 40):
        if i % 2 == 0:
            tmp = add_mat(tmp, div_mat(pow_mat(tab, 2 * i + 1), factorial(2 * i + 1)))
        else:
            tmp = sub_mat(tmp, div_mat(pow_mat(tab, 2 * i + 1), factorial(2 * i + 1)))
    return tmp

def cosh(tab):
    tmp = identity_mat(len(tab))
    for i in range(1, 40):
        tmp = add_mat(tmp, div_mat(pow_mat(tab, 2 * i), factorial(2 * i)))
    return tmp

def sinh(tab):
    tmp = tab
    for i in range(1, 40):
        tmp = add_mat(tmp, div_mat(pow_mat(tab, 2 * i + 1), factorial(2 * i + 1)))
    return tmp