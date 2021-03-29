#include<iostream>
#include "bigInt.h"

using namespace std;

int main(){
	try{
		bigInt bi("-123");
		cout<<"completed"<<"\n";
		// cout<<bigInt.value(145)<<"\n";
		cout<<bi.get()<<"\n";
		cout<<bi.big_abs()<<"\n";

	}catch(bigIntException e){
		cout<<e.what()<<"\n";
	}
	return 0;
}