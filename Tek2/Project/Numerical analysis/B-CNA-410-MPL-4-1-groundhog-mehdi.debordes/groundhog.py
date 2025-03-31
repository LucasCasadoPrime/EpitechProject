#!/usr/bin/env python3

import sys, math
from statistics import *
from decimal import *


def error(a):
    if (len(a) != 2 or a[1] == '-h'):
        print("SYNOPSIS")
        print("    ./groundhog period")
        print("DESCRIPTION")
        print("     period     the number of days defining a period")
        sys.exit(0)


def standard_deviation(l,a, res=0.00, res2=0.00, ret = 0.00):
    for i in range(int(len(l)-a), len(l)):
        res += float(l[i])
        res2 += pow(float(l[i]), 2)
    ret = round(math.sqrt((res2 / a) - (pow(res/a, 2))),2)
    return(float(ret))


def get_for_sd(l,a,index):
    if len(l) < a:
        return("nan")
    for i in range(index,len(l)):
        if (len(l[int(i):int(a+i)]) == a):
            return(standard_deviation(l[int(i):int(a+index)], a))


def increase_average(l,a):
    taux = 0
    if len(l) <= a:
        return("nan")
    b = len(l) - a
    while (b != len(l)):
        if float(l[int(b)]) > float(l[int(b-1)]):
            taux+= float(l[int(b)]) - float(l[int(b-1)])
        b = b + 1
    return(float(round(taux/a,2)))


def evolution(l,a,ret=0):
    if l[len(l) - int(a) - 1] == 0:
        return("nan")
    else:
        ret = (float(l[-1])-float(l[len(l) - int(a) - 1]))/float(l[len(l) - int(a) - 1])*100
        
        if ret == 0:
            ret = "nan"
            return(ret)
        return(int(round(ret, 2)))


def get_weir_value(l, a ,ni):
    tmp = []
    for i in range(int(len(l)) - int(a), int(len(l))):
        tmp.append(l[i])
    tmp.sort()
    if (len(tmp) % 2) == 0:
        med = median(tmp)
    else:
        med = ((float(median_low(tmp)) + float(median_high(tmp))) / 2)
    if (len(tmp) % 4) == 0:
        quartile1 = tmp[len(tmp)//4 - 1]
        quartile3 = tmp[3 * len(tmp)//4 - 1]
    else:
        quartile1 = tmp[len(tmp)//4]
        quartile3 = tmp[3 * len(tmp)//4]
    md = float(quartile3) - float(quartile1)
    ILmt = md * 0.82
    ILmtInf = float(quartile1) - ILmt
    ILmtSup = float(quartile3) + ILmt
    if (float(ni) < ILmtInf or float(ni) > ILmtSup):
            return float(ni)


def groundhog(a):
    try:
        a = float(a[1])
    except:
        print("Invalid argument")
        sys.exit(84)
    periods = []
    weirdest = []
    i = 0
    index = 0
    while(1):
        newPeriods = input("")
        if (float(newPeriods)):
            periods.append(newPeriods)
            i+=1
            if str(newPeriods) == "STOP":
                print(str(len(weirdest)) + " weirdest values are ", end='')
                print(sorted(weirdest))
                sys.exit(0)
            elif (float(i) < a):
                print("g=nan\t\tr=nan%\t\ts=nan")
            elif (float(i) >= a):
                if get_weir_value(periods, a, newPeriods)!= None:
                    weirdest.append(get_weir_value(periods, a, newPeriods))
                print("g=" + str(increase_average(periods,a)), end="")
                print("\t\tr=" + str(evolution(periods,a)) + "%", end="")
                print("\t\ts=" + str(get_for_sd(periods,a,index)))
                index+=1
        else: 
            print("Invalid input")
            sys.exit(84)


def main(argv):
    error(argv)
    groundhog(argv)


if __name__ == "__main__":
    main(sys.argv)