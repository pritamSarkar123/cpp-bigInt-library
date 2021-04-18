#include<iostream>
#include "bigInt.h"

using namespace std;

int main(){
	bigInt b(11);
	cout<<b<<endl;
	b.bit_clear_and_update(3);
	cout<<b<<endl;
	cin>>b;
	cout<<b<<endl;
	return 0;
}