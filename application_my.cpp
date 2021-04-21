#include<iostream>
#include "bigInt.h"

using namespace std;

int main(){
	bigInt b(16);
	cout<<b.primeProbability(0)<<endl;
	return 0;
}