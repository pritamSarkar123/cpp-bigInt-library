#include<iostream>
#include "bigInt.h"

using namespace std;

int main(){
	bigInt d(-11);
	bigInt e(5);
	cout<<d<<" "<<bigInt::toBinary(d)<<endl;
	cout<<e<<" "<<bigInt::toBinary(e)<<endl;
	e=d|e;
	cout<<e<<" "<<bigInt::toBinary(e)<<endl;
	return 0;
}