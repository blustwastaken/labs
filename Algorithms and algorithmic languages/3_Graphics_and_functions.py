import math
import pylab as pb
import numpy as np

def mainFunction(n):
        result = 1
        for i in range(2, int(n+1)):
                result += math.sin(i)/math.pow(i,2)
        return result

def sumOfMainFunctions(n):
        result = 0
        for k in range(1, int(n+1)):
                result += mainFunction(k)
        return result

def tabulateFunction(func, left, right, step):
        while left < right:
                print("S(",round(left,3),") =", round(func(left),3))
                left += step

def printGraphic(firstFunc, secondFunc, left, right, firstStep, secondStep):
        xU = np.arange(left,right,firstStep)
        yU = [firstFunc(x) for x in xU]
        xG = np.arange(left, right, secondStep)
        yG = [secondFunc(x) for x in xG]
        pb.scatter(xU,yU, color="navy", label="y = S(n)")
        pb.plot(xG, yG, color = "black", label = "y = f(n)")
        pb.grid()
        pb.legend()
        pb.show()

a = float(input())
b = float(input())
h = float(input())
h1 = float(input())

tabulateFunction(sumOfMainFunctions, a, b, h)
printGraphic(mainFunction, sumOfMainFunctions, a, b, h, h1)
