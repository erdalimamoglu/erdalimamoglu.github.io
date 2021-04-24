from scipy.linalg import *
import math
from sympy import *

x, z, i = symbols('x z i')
lmbd = IndexedBase('lmbd')
c = IndexedBase('c')

#-----

def prony(rou, aa, ee, t):
    l  = math.ceil( len(ee)/2 )
    H = hankel( ee[ 0:l ], ee[ l-1:-1 ] )
    L = Matrix( [ [lmbd[i] for i in range(l)] ] ).transpose()
    R = Matrix( [ ee[l::] ] ).transpose()
    eqs = H*L+R
    eqs = [ i for i in eqs ]
    sols = solve( eqs )
    tlp = z**l + sum( [ lmbd[i]*z**i for i in range(0,l) ] )
    tlp = tlp.subs( sols )
    tlp_factored = factor( tlp )
    delta = solve( tlp_factored )
    delta = [math.log(i,rou) for i in delta]
    C = Matrix( [ [c[i] for i in range(l)] ] ).transpose()
    T = Matrix( [ [j**delta[i] for i in range(l)] for j in aa[0:l] ] )
    R = Matrix( [ ee[0:l] ] ).transpose()
    eqs = T*C - R
    eqs = [ i for i in eqs ]
    sols = solve( eqs )
    ans = [ [c[j].subs(sols), delta[j]] for j in range(l) ]
    #g = sum( [c[j]*x**int( delta[j] ) for j in range(l)] ).subs( sols )
    return ans

#-----

# ORNEK 1
#rou = 2
#t = 3
#aa = [1, 2, 4, 8, 16, 32]
#ee = [3, 67, 4101, 262153, 16777233, 1073741857]
### f = x^6 + x + 1

# ORNEK 2
rou = 2
t = 4
aa = [1, 2, 4, 8, 16, 32]
ee = [-7, 65505, 4294967177, 281474976710193, 18446744073709549793, 1208925819614629174698945, 79228162514264337593543921537, 5192296858534827628530496329105153]
### f = x^16-7*x^2-2*x+1

# ORNEK 3
#rou = 2
#t = 3
#aa = [1, 2, 4, 8, 16, 32]
#ee = [2, 889/2, 114673/2, 14680033/2, 1879048129/2, 240518168449/2]
### f = 7/2 * x^7 - 2*x + 1/2

# ORNEK 4
#rou = 5
#t = 2
#aa = [1, 5, 25, 125]
#ee = [2, 26/5, 626/25, 15626/125]
### f = x + 1/x

#-----
