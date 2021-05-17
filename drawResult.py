import numpy as np
from matplotlib import pyplot as plt

def readxy(inputfile):
    with open(inputfile,'r') as f:
        L=f.readlines()
        L=[x.split()[:-1] for x in L]
        xlist=[float(x[0]) for x in L if len(x)==2]
        ylist=[float(x[1]) for x in L if len(x)==2]
    return xlist,ylist


if __name__=='__main__':
    inputname='/Users/yezhuoyang/Desktop/BSplineFitting/test_data/01.txt'
    control_name=inputname+"_controls.txt"
    spline_name=inputname+"_spline.txt"
    x_origin,y_origin=readxy(inputname)
    x_control,y_control=readxy(control_name)
    x_spline,y_spline=readxy(spline_name)
    plt.scatter(x_origin,y_origin,label="Sample points",s=4)
    plt.scatter(x_control,y_control,marker='X',label="control points")
    plt.plot(x_spline,y_spline,c='#CD5C5C',label="Spline")
    plt.legend()
    plt.savefig("/Users/yezhuoyang/BSpline/Tests/"+"01"+".png")