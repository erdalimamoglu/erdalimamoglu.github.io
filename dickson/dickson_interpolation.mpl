#################################################################

print("------------------------------");
print("------------------------------");
print(" This Maple Package is implemented by Erdal Imamoglu <eimamoglu@klu.edu.tr>");
print("");
print("This package contains procedures to write a given polynomial f in terms of Chebyshev Polynomials of the 1st and 2nd Kind, and in terms of Dickson Polynomials of the 1st and 2nd Kind.");
print("");
print("References");
print("[1] Imamoglu, E., Kaltofen, E. L., & Yang, Z. (2018, July). Sparse polynomial interpolation with arbitrary orthogonal polynomial bases. In Proceedings of the 2018 ACM International Symposium on Symbolic and Algebraic Computation (pp. 223-230).");
print("");

#################################################################

lprint("");
lprint("----------- Prony's Algorithm -----------");
lprint("Use prony(rou, aa, ee, t)");
lprint("Here rou = evaluation point, aa = list of evaluation points, ee = list of evaluations, t = sparsity or an upper bound");
lprint("");

prony := proc(rou, aa::list, ee::list, t::nonnegint)

	# rou = evaluation point that is used to compute evaluation points
	# aa = list of evaluation points
	# ee = list of evaluations at evaluation points
	# t = sparsity or an upper bound for sparsity

	local a, e, H, i, lambda, L, R, HL, EQ, eqns, sols, sol, tlp, z, sp,
	pw, tmp, TV, j, C, RR, c, TVC, EQ2, eqns2, sols2, reconstructed_f;

	#option trace;
	option remember;

	for i from 0 to 2*t-1 do
		a[i] := aa[i+1];
		e[i] := ee[i+1];
	od;

	# H,L,R, form those necessary matrices for computation

	H := LinearAlgebra:-HankelMatrix([seq(e[i], i=0..2*t-2)]);
	L := Matrix(t, 1, [seq(lambda[i], i=0..t-1)]);
	R := Matrix(t,1, [seq(e[i], i=t..2*t-1)]);

	# H*L = R, solve this matrix system for lambda's

	HL := LinearAlgebra:-Multiply(H, L);
	EQ := HL + R;
	eqns := {seq(EQ[i][1]=0, i=1..t)};
	sols := solve(eqns, [seq(lambda[i], i=0..t-1)]);

	# tlp, compute the term locator polynomial tlp

	sol := sols[1];
	for i from 1 to t do
		lambda[i-1] := op(sol[i])[2];
	od:
	tlp := collect( simplify(add(lambda[i]*z^(i),i=0..t-1) + z^t ),z):

	# compute the roots of the term locator polynomial tlp

	# line below takes too much time to terminate

	sp := PolynomialTools:-Split(tlp, z);

	# compute the logs of the roots

	for i from 1 to t do
		tmp := solve(op(sp)[i],z):
		tmp := log[rou](tmp):
		pw[i] := round(evalf(tmp));
		# the pw[i] are the exponents of the unknown polynomial
	od:

	#sp := [solve(tlp=0,z)]; 

	#for i from 1 to t do 
		#tmp := log[rou](sp[i]);
		#pw[i] := round(evalf(tmp));
	#od;	

	# TV, C, RR, form those necessary matrices for computation

	TV := Matrix(t,t,[ seq( seq(a[j]^pw[i], i=1..t), j=0..t-1 ) ]);
	C := Matrix(t,1, [seq(c[i],i=1..t)] );
	RR := Matrix(t,1, [seq(e[i], i=0..t-1)] );

	# compute the coefficients of the unknown polynomial

	TVC := LinearAlgebra:-Multiply(TV,C);
	EQ2 := TVC - RR;
	eqns2 := {seq(EQ2[i][1]=0, i=1..t)};
	sols2 := simplify( solve(eqns2,{seq(c[i],i=1..t)}) );

	# return the unkown polynomial

	reconstructed_f := add(op(sols2[i])[2]*x^pw[i],i=1..t);
	return reconstructed_f;
	#lprint(reconstructed_f);
	#return [ [ seq(op(sols2[i])[2],i=1..t) ], [ seq(pw[i],i=1..t) ] ];

end proc:

#################################################################

lprint("");
lprint("----------- Chebyshev-1 Interpolation -----------");
lprint("Use cheby_1(rou, bbp, chebyshev_sparsity)");
lprint("Here rou = evaluation point, bbp = a polynomial, chebyshev_sparsity = a bound for the sparsity");
lprint("NOTE: ChebyshevT(0,x) should not appear in the representation! If [[.,a negative number],...] appears in the result, it means that an apporximation to the input polynomial is found. There is a solution for this problem in [1], but we decided not to implement it.");
lprint("");

cheby_1 := proc(rou, pre_f, cheby_sparsity)

	local t, g, tL, ar, i, al, a, e, er, el, pre_ans, s, so, cfs, dgr, ans, y;

	t := cheby_sparsity;

	g := collect(subs(x=(y+1/y)/2, pre_f), y);
	tL := nops(g);

	ar := [seq(rou^i,i=0..(2*t))];
	al := [seq(rou^(i),i=-(2*t)..-1)];
	a := [op(al),op(ar)];

	# save same time here:
	#e := [seq(eval(g,y=i),i=a)];
	er := [seq(eval(g,y=i),i=ar)];
	el := ListTools:-Reverse(er[2..-1]);
	e := [op(el),op(er)];

	pre_ans := prony(rou, a, e, tL);

	s := sort(pre_ans);
	so := [op(s)];
	cfs := [ seq( `if`(degree(i,x)>=0,2*coeffs(i,x),NULL), i=so ) ];
	dgr := [ seq( degree(so[i],x),i=1..nops(cfs) ) ];

	ans := [ seq( [cfs[i],dgr[i]], i=1..nops(dgr) ) ];
	ans := sort( ans, (i,j)-> i[2]<j[2] );
	return ans;

end proc:

#################################################################

lprint("");
lprint("----------- Chebyshev-2 Interpolation -----------");
lprint("Use cheby_2(rou, bbp, chebyshev_sparsity)");
lprint("Here rou = evaluation point, bbp = a polynomial, chebyshev_sparsity = a bound for the sparsity");
lprint("");

cheby_2 := proc(rou, pre_f, cheby_sparsity)

	local t, g, tL, ar, i, al, a, e, el, er, pre_ans, s, so, cfs, dgr, ans, y;

	t := cheby_sparsity;

	g := collect((y-1/y)*subs(x=(y+1/y)/2, pre_f), y);
	tL := nops(g);

	ar := [seq(rou^i,i=0..(2*t))];
	al := [seq(rou^(i),i=-(2*t)..-1)];
	a := [op(al),op(ar)];

	#e := [seq(eval(g,y=i),i=a)];
	er := [seq(eval(g,y=i),i=ar)];
	el := (-1) * ListTools:-Reverse(er[2..-1]);
	e := [op(el),op(er)];

	pre_ans := prony(rou, a, e, tL);

	s := sort(pre_ans);
	so := [op(s)];
	cfs := [ seq( `if`(degree(i,x)>=0,coeffs(i,x),NULL), i=so ) ];
	dgr := [ seq( degree(so[i],x)-1,i=1..nops(cfs) ) ];

	ans := [ seq( [cfs[i],dgr[i]], i=1..nops(dgr) ) ];
	ans := sort( ans, (i,j)-> i[2]<j[2] );
	return ans;

end proc:

#################################################################

lprint("");
lprint("----------- Dickson-1 Interpolation -----------");
lprint("Use dickson_1(rou, bbp, dickson_sparsity, b)");
lprint("Here rou = evaluation point, bbp = a polynomial, dickson_sparsity = a bound for the sparsity, b = square-root of the Dickson parameter a");
lprint("NOTE: This procedure uses cheby_1. Please see the note in cheby_1.");
lprint("");

dickson_1 := proc(rou, pre_f, dickson_sparsity)
	local pre_ff, v, w, i;
	pre_ff := subs(x=x*(2*b),pre_f);
	v := cheby_1( 2*b*rou, pre_ff, dickson_sparsity, b);
	w := [seq( [ simplify( i[1]/(2*b^i[2]) ), i[2] ] , i=v )];
	return w;
end proc:

#################################################################

lprint("");
lprint("----------- Dickson-2 Interpolation -----------");
lprint("Use dickson_2(rou, bbp, dickson_sparsity, b)");
lprint("Here rou = evaluation point, bbp = a polynomial, dickson_sparsity = a bound for the sparsity, b = square-root of the Dickson parameter a");
lprint("");

dickson_2 := proc(rou, pre_f, dickson_sparsity, b)
        local pre_ff, v, w, i;
        pre_ff := subs(x=x*(2*b),pre_f);
        v := cheby_2( rou, pre_ff, dickson_sparsity);
        print( v );
        w := [seq( [ simplify( i[1]/(b^(i[2])) ), i[2] ] , i=v )];
        return w;
end proc:

#################################################################

lprint("");
lprint("----------- Procedures to compute Dickson Polynomials in K[x] -----------");
lprint("Use DicksonD(n,a,x) for the 1st kind");
lprint("Use DicksonE(n,a,x) for the 2nd kind");
lprint("Here n = degree, a = an element in K, x = variable");
lprint("");

DicksonD := proc(n, a, x)
	option remember;
	local i,d;
	d[0] := 2;
	d[1] := x;
	for i from 2 to n do
		d[i] := expand( x*d[i-1] - a*d[i-2] );
		#d[i] := collect(normal(d[i]),x);
	od;
	return d[n];
end proc:

DicksonE := proc(n, a, x)
	option remember;
	local i,e;
	e[0] := 1;
	e[1] := x;
	for i from 2 to n do
		e[i] := expand( x*e[i-1] - a*e[i-2] );
		#e[i] := collect(normal(e[i]),x);
	od;
	return e[n];
end proc:

#################################################################

lprint("");
lprint("----------- Procedure to compute Dickson Polynomials of the (k+1)-th kind in K[x] -----------");
lprint("Use DicksonKP1(n,a,x,k)");
lprint("Here n = degree, a = an element in K, x = variable, k = an integer");
lprint("");

DicksonKP1 := proc(n,a,x,k)
	option remember;
	local i, dk;
	dk[0] := 2-k;
	dk[1] := x;
	for i from 2 to n do
		dk[i] := expand( x*dk[i-1] - a*dk[i-2] );
		#dk[i] := collect(normal(dk[i]),x);
	od;
	return dk[n];
end proc:

#################################################################

print("------------------------------");
print("------------------------------");

#################################################################

