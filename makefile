big_int_test: application_my.o bigInt_constructors.o methods_one.o compare_to.o add_sub.o big_mult.o big_div_pow.o gcd_lcm.o rootFind.o bigIntBin.o bigIntBin2.o primeFinder.o
	g++ application_my.o bigInt_constructors.o methods_one.o compare_to.o add_sub.o big_mult.o big_div_pow.o gcd_lcm.o rootFind.o bigIntBin.o bigIntBin2.o primeFinder.o -o big_int_test
application_my.o: application_my.cpp
	g++ -c application_my.cpp
bigInt_constructors.o: bigInt_constructors.cpp
	g++ -c bigInt_constructors.cpp
methods_one.o: methods_one.cpp
	g++ -c methods_one.cpp
compare_to: compare_to.cpp
	g++ -c compare_to.cpp
add_sub.o: add_sub.cpp
	g++ -c add_sub.cpp
big_mult.o: big_mult.cpp
	g++ -c big_mult.cpp
big_div_pow.o: big_div_pow.cpp
	g++ -c big_div_pow.cpp
gcd_lcm.o: gcd_lcm.cpp
	g++ -c gcd_lcm.cpp
rootFind.o: rootFind.cpp
	g++ -c rootFind.cpp
bigIntBin.o: bigIntBin.cpp
	g++ -c bigIntBin.cpp
bigIntBin2.o: bigIntBin2.cpp
	g++ -c bigIntBin2.cpp
primeFinder.o: primeFinder.cpp
	g++ -c primeFinder.cpp
clean: 
	rm *o big_int_test

