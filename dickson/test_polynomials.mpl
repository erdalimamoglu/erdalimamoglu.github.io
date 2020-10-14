#################################################################

read "dickson_interpolation.mpl";

#################################################################

# Example 1: A Cyclotomic Polynomial

i := 105:
cp := NumberTheory:-CyclotomicPolynomial(i,x):

#################################################################

# Example 2: A Sparse Polynomial

t := 5:
n := 10^2:
sp := randpoly([x],terms=t,coeffs=rand(-n..n),expons=rand(0..n)):

#################################################################

# Example 3: A Dense Polynomial

m := 10^2:
dp := randpoly([x],coeffs=rand(-m..m),degree=m,dense):

#################################################################

# Example 4: A Multivariable Sparse Polynomial

vars := [x,y,z]:
t := 5:
h := 10^2:
msp := collect(randpoly(vars,terms=t,coeffs=rand(-h..h),expons=rand(0..h)),x):

#################################################################

# Example 5: A Multivariable Dense Polynomial

vars := [x,y,z]:
k := 10^1:
mdp := collect(randpoly(vars,coeffs=rand(-k..k),degree=k,dense),x):

#################################################################

# Example Test Run

f := sp:
t := degree(f,x)+1;
rou := 2;

# Activate the lines below to test cheby_2.
r := cheby_2(rou, f, t); 
g := add(i[1]*ChebyshevU(i[2],x),i=r):

# Activate the lines below to test dickson_2. If you wish, you may change a.
# a := 5; 
# b := sqrt(a); 
# r := dickson_2(rou, f, t, b); 
# g := add(i[1]*DicksonE(i[2],a,x),i=r):

# If is_zero=0, then everything is ok.

is_zero := simplify(f-g); 

#################################################################





