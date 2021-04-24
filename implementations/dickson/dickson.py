#####

#import scipy.linalg as la
import sympy as sym

x, y, z, i, a = sym.symbols('x y z i a')

#####

print("Type show_info() for details.");

#####

def show_info():
	print("""x, z, i, a = Symbols

ChebyshevT(n,x) = Chebyshev Polynomial of the 1st Kind
ChebyshevU(n,x) = Chebyshev Polynomial of the 2nd Kind
Chebychev(n,x,k) = Chebyshev Polynomial of the k-th Kind (k=1,2,3,4)

DicksonD(n,x,a) = Dickson Polynomial of the 1st Kind
DicksonE(n,x,a)	= Dickson Polynomial of the 2nd Kind
DicksonKP1(n,k,x,a) = Dickson Polynomial of the (k+1)-st Kind""")

#####

def prony(omega, pts, evls, t):
	lmbd = sym.IndexedBase('lmbd')
	c = sym.IndexedBase('c')

	if len(evls)%2==0:
		tt = t
	else:
		tt = t+1

	rngtt = range(tt)
	#H = la.hankel( evls[0:t], evls[t-1:-1] )
	H = sym.Matrix( [[i for i in evls[j:j+tt]] for j in rngtt] )
	L = sym.Matrix( [ [lmbd[i] for i in rngtt] ] ).transpose()
	R = sym.Matrix( [ evls[tt::] ] ).transpose()
	sols = sym.solve( [ i for i in H*L+R ], rational=True )
	tlp = ( z**tt + sum( [ lmbd[i]*z**i for i in rngtt ] ) ).subs( sols )
	delta = [ sym.log(i,omega) for i in sym.solve( tlp, rational=True ) ]
	V = sym.Matrix( [ [j**delta[i] for i in rngtt] for j in pts[0:tt] ] )
	C = sym.Matrix( [ [c[i] for i in rngtt] ] ).transpose()
	R = sym.Matrix( [ evls[0:tt] ] ).transpose()
	sols = sym.solve( [ i for i in V*C-R ], rational=True )
	ans = [ [c[j].subs(sols), delta[j]] for j in rngtt ]
	f = sum( [c[j]*x**int( delta[j] ) for j in rngtt] ).subs( sols )
	return f

#####

def cheby_2(omega, pre_f, cheby_sparsity):
	t = cheby_sparsity
	g = sym.expand( (y-1/y) * pre_f.subs(x, (y+1/y)/2))
	tL = len(g.args)
	#print(tL)
	ar = [ sym.nsimplify(omega**i) for i in range(1,2*t+1) ]
	al = [ sym.nsimplify(omega**i) for i in range(-2*t,0) ]
	a = al + [1] + al
	#print(len(a))
	er = [ sym.nsimplify(g.subs(y,i)) for i in ar ]
	el = [ -1*i for i in er ]
	e =  el + [0] + er
	#print(len(e))
	pre_ans = prony(omega,a,e,tL)

#####

def Chebyshev(n,x,k):
	A = sym.Matrix([ [0,1],[-1,2*x] ])
	p1 = [x, 2*x, 2*x-1, 2*x+1]
	P0 = sym.Matrix([ [1],[ p1[k-1] ] ])
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

#####

def DicksonKP1(n,k,x,a):
    A = sym.Matrix([ [0,1],[-a,x] ])
    P0 = sym.Matrix([ [2-k],[x] ])
    P = A**n * P0
    return expand( P[0,0] )

def DicksonD(n,x,a):
	return DicksonKP1(n,0,x,a)

def DicksonE(n,x,a):
	return DicksonKP1(n,1,x,a)

#####

# ORNEK 2: f = x^16-7*x^2-2*x+1
omega = 2
pts = [1, 2, 4, 8, 16, 32]
evls = [-7, 65505, 4294967177, 281474976710193, 18446744073709549793,
1208925819614629174698945, 79228162514264337593543921537,
5192296858534827628530496329105153]
t = 4

#####
