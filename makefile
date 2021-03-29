big_int_test: application_my.o bigInt_constructors.o methods_one.o 
	g++ application_my.o bigInt_constructors.o methods_one.o -o big_int_test
application_my.o: application_my.cpp
	g++ -c application_my.cpp
bigInt_constructors.o: bigInt_constructors.cpp
	g++ -c bigInt_constructors.cpp
methods_one.o: methods_one.cpp
	g++ -c methods_one.cpp
clean: 
	rm *o big_int_test

