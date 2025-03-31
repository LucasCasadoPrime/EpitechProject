import sys
from function import *

def main():
    tab = []
    check_param()
    sqi = error_mng()
    for i in range(int(sqi)):
        tab.append([])
        for j in range(int(sqi)):
            tab[i].append(sys.argv[i * int(sqi) + j + 2])
    tab = launch(tab)
    print_mat(tab)