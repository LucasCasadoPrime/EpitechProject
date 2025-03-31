import sys
import math
from math_func import *

def print_help():
    print("USAGE\n"
          "\t./108trigo fun a0 a1 a2....\n"
          "\n"
          "DESCRIPTION\n"
          "\tfun\tfunction to be applied,"
          ' among at least "EXP", "COS", "SIN", "COSH" and "SINH"\n'
          '\tai\tcoeficients of the matrix')
    exit(0)
def tab_fcts():
    fct_tab = [exp, cos, cosh, sinh]


def error_mng():
    i = len(sys.argv) - 2
    sqi = trunc(sqrt(i))
    if trunc(sqrt(i)) ** 2 != i:
        print("Missing arguments.\nUsage: ./108trigo fun a0 a1 a2 ...", file=sys.stderr)
        exit(84)
    return sqi

def check_param():
    if "--help" in sys.argv or "-h" in sys.argv:
        print_help()
    if len(sys.argv) <= 2 or sys.argv[1] not in ["EXP", "COS", "SIN", "COSH", "SINH"]:
        print("Missing arguments.\nUsage: ./108trigo fun a0 a1 a2 ...", file=sys.stderr)
        exit(84)
    try:
        for i in range(2, len(sys.argv)):
            sys.argv[i] = float(sys.argv[i])
    except ValueError:
        print("Argument %d (%s) isn't a number" % (i, sys.argv[i]), file=sys.stderr)
        exit(84)


def launch(tab):
    args = ["EXP", "COS", "SIN", "COSH", "SINH"]
    fct_tab = [exp, cos, sin, cosh, sinh]
    for i in range(len(fct_tab)):
        if sys.argv[1] == args[i]:
            tab = fct_tab[i](tab)
    return tab
def print_mat(tab):
    for i in range(len(tab)):
        for j in range(len(tab[i])):
            print("%.2f%c" % (tab[i][j], '\t' if (j != len(tab[i]) - 1) else '\n'), end="")
