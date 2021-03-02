from sympy import *

x,a = symbols('x a')

init_printing()

print("""
------------------------------------------------------------
x, a		    	= Symbols

ChebyshevT(n,x)     = Chebyshev Polynomial of the 1st Kind
ChebyshevU(n,x)     = Chebyshev Polynomial of the 2nd Kind
Chebychev(n,x,k)    = Chebyshev Polynomial of the k-th Kind (k=1,2,3,4)

DicksonD(n,x,a)	    = Dickson Polynomial of the 1st Kind
DicksonE(n,x,a)     = Dickson Polynomial of the 2nd Kind
DicksonKP1(n,k,x,a) = Dickson Polynomial of the (k+1)-st Kind
------------------------------------------------------------
""")

#------------------------------------------------------------

def Chebyshev(n,x,k):
	A = Matrix([ [0,1],[-1,2*x] ])
	p1 = [x, 2*x, 2*x-1, 2*x+1]
	P0 = Matrix([ [1],[ p1[k-1] ] ])
	P = A**n * P0
	return expand( P[0,0] )

def ChebyshevT(n,x):
	return Chebyshev(n,x,1)

def ChebyshevU(n,x):
	return Chebyshev(n,x,2)

def ChebyshevV(n,x):
	return Chebyshev(n,x,3)

def ChebyshevW(n,x):
	return Chebyshev(n,x,4)

#------------------------------------------------------------

def DicksonKP1(n,k,x,a):
        A = Matrix([ [0,1],[-a,x] ])
        P0 = Matrix([ [2-k],[x] ])
        P = A**n * P0
        return expand( P[0,0] )

def DicksonD(n,x,a):
	return DicksonKP1(n,0,x,a)

def DicksonE(n,x,a):
	return DicksonKP1(n,1,x,a)

#------------------------------------------------------------
