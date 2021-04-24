#####

read "dickson.mpl":

coeff_range := 10;
sparsity_range := 10;

#####

tm0 := time();

#####

# Example 1: Integer Coefficients, DicksonD, the parameter 'a' is a complete square

n := coeff_range:
m := sparsity_range:
t := rand(1..m)():
cf := [ seq(rand(-n..n)(), i=1..t) ]:
dgr := [ seq(rand(1..m)(), i=1..t) ]:
t := nops(dgr):
a := 1:
b := sqrt(a):
f := simplify( add( cf[i]*DicksonD(dgr[i],x,a), i=1..t) ):
rou := rand(1..m)():
ans := dickson_1(rou, f, t, b):
g := add(i[1]*DicksonD(i[2],x,a),i=ans):
is_zero := simplify(f-g):

lprint(""):
lprint("Example 1: Integer Coefficients, DicksonD, a is a complete square"):
lprint("Example 1:","a=",a,"t=",t,"deg(f)=",degree(f,x),"--->",is_zero):
lprint(""):

#####

# Example 2: Rational Coefficients, DicksonD, the parameter 'a' is a complete square

n := coeff_range:
m := sparsity_range:
t := rand(1..m)():
cf := [ seq(rand(-n..n)()/rand(1..n)(), i=1..t) ]:
dgr := [ seq(rand(1..m)(), i=1..t) ]:
t := nops(dgr):
a := 9:
b := sqrt(a):
f := simplify( add( cf[i]*DicksonD(dgr[i],x,a), i=1..t) ):
rou := rand(1..m)():
ans := dickson_1(rou, f, t, b):
g := add(i[1]*DicksonD(i[2],x,a),i=ans):
is_zero := simplify(f-g):

lprint(""):
lprint("Example 2: Rational Coefficients, DicksonD, a is a complete square"):
lprint("Example 2:","a=",a,"t=",t,"deg(f)=",degree(f,x),"--->",is_zero):
lprint(""):

#####

# Example 3: Integer Coefficients, DicksonE, the parameter 'a' is a complete square

n := coeff_range:
m := sparsity_range:
t := rand(1..m)():
cf := [ seq(rand(-n..n)(), i=1..t) ]:
dgr := [ seq(rand(0..m)(), i=1..t) ]:
t := nops(dgr):
a := 25:
b := sqrt(a):
f := simplify( add( cf[i]*DicksonE(dgr[i],x,a), i=1..t) ):
rou := rand(1..m)():
ans := dickson_2(rou, f, t, b):
g := add(i[1]*DicksonE(i[2],x,a),i=ans):
is_zero := simplify(f-g):

lprint(""):
lprint("Example 3: Integer Coefficients, DicksonE, a is a complete square"):
lprint("Example 3:","a=",a,"t=",t,"deg(f)=",degree(f,x),"--->",is_zero):
lprint(""):

#####

# Example 4: Rational Coefficients, DicksonE, the parameter 'a' is a complete square

n := coeff_range:
m := sparsity_range:
t := rand(1..m)():
cf := [ seq(rand(-n..n)()/rand(1..n)(), i=1..t) ]:
dgr := [ seq(rand(0..m)(), i=1..t) ]:
t := nops(dgr):
a := 49:
b := sqrt(a):
f := simplify( add( cf[i]*DicksonE(dgr[i],x,a), i=1..t) ):
rou := rand(1..m)():
ans := dickson_2(rou, f, t, b):
g := add(i[1]*DicksonE(i[2],x,a),i=ans):
is_zero := simplify(f-g):

lprint(""):
lprint("Example 4: Rational Coefficients, DicksonE, a is a complete square"):
lprint("Example 4:","a=",a,"t=",t,"deg(f)=",degree(f,x),"--->",is_zero):
lprint(""):

#####

# Example 5: Integer Coefficients, DicksonD, the parameter 'a' is not a complete square

n := coeff_range:
m := sparsity_range:
t := rand(1..m)():
cf := [ seq(rand(-n..n)(), i=1..t) ]:
dgr := [ seq(rand(1..m)(), i=1..t) ]:
t := nops(dgr):
a := 3:
b := sqrt(a):
f := simplify( add( cf[i]*DicksonD(dgr[i],x,a), i=1..t) ):
rou := rand(1..m)():
ans := dickson_1(rou, f, t, b):
g := add(i[1]*DicksonD(i[2],x,a),i=ans):
is_zero := simplify(f-g):

lprint(""):
lprint("Example 5: Integer Coefficients, DicksonD, a is not a complete square "):
lprint("Example 5:","a=",a,"t=",t,"deg(f)=",degree(f,x),"--->",is_zero):
lprint(""):

#####

# Example 6: Rational Coefficients, DicksonD, the parameter 'a' is not a complete square

n := coeff_range:
m := sparsity_range:
t := rand(1..m)():
cf := [ seq(rand(-n..n)()/rand(1..n)(), i=1..t) ]:
dgr := [ seq(rand(1..m)(), i=1..t) ]:
t := nops(dgr):
a := 7:
b := sqrt(a):
f := simplify( add( cf[i]*DicksonD(dgr[i],x,a), i=1..t) ):
rou := rand(1..m)():
ans := dickson_1(rou, f, t, b):
g := add(i[1]*DicksonD(i[2],x,a),i=ans):
is_zero := simplify(f-g):

lprint(""):
lprint("Example 6: Rational Coefficients, DicksonD, a is not a complete square"):
lprint("Example 6:","a=",a,"t=",t,"deg(f)=",degree(f,x),"--->",is_zero):
lprint(""):

#####

# Example 7: Integer Coefficients, DicksonE, the parameter 'a' is not a complete square

n := coeff_range:
m := sparsity_range:
t := rand(1..m)():
cf := [ seq(rand(-n..n)(), i=1..t) ]:
dgr := [ seq(rand(0..m)(), i=1..t) ]:
t := nops(dgr):
a := 6:
b := sqrt(a):
f := simplify( add( cf[i]*DicksonE(dgr[i],x,a), i=1..t) ):
rou := rand(1..m)():
ans := dickson_2(rou, f, t, b):
g := add(i[1]*DicksonE(i[2],x,a),i=ans):
is_zero := simplify(f-g):

lprint(""):
lprint("Example 7: Integer Coefficients, DicksonE, a is not a complete square"):
lprint("Example 7:","a=",a,"t=",t,"deg(f)=",degree(f,x),"--->",is_zero):
lprint(""):

#####

# Example 8: Rational Coefficients, DicksonE, the parameter 'a' is not a complete square

n := coeff_range:
m := sparsity_range:
t := rand(1..m)():
cf := [ seq(rand(-n..n)()/rand(1..n)(), i=1..t) ]:
dgr := [ seq(rand(0..m)(), i=1..t) ]:
t := nops(dgr):
a := 8:
b := sqrt(a):
f := simplify( add( cf[i]*DicksonE(dgr[i],x,a), i=1..t) ):
rou := rand(1..m)():
ans := dickson_2(rou, f, t, b):

g := add(i[1]*DicksonE(i[2],x,a),i=ans):
is_zero := simplify(f-g):

lprint(""):
lprint("Example 8: Rational Coefficients, DicksonE, a is not a complete square"):
lprint("Example 8:","a=",a,"t=",t,"deg(f)=",degree(f,x),"--->",is_zero):
lprint(""):

#####

print(time()-tm0);

#####
