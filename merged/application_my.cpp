#include<iostream>
#include "bigInt.h"

using namespace std;

int main(){
	bigInt b(1373);
	cout<<b.primeProbability(10)<<endl;
	bigInt c=b;
	cout<<c<<endl;
	return 0;
}