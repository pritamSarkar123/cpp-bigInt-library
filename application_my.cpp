#include<iostream>
#include "bigInt.h"

using namespace std;

int main(){
	vector<string> v{"25","5","-25","-5"};
	vector<bigInt> bv;
	for(int i=0;i<v.size();i++){
		bv.push_back(bigInt(v[i]));
	}
	cout<<"big additions and subtractions\n";
	for(int i=0;i<bv.size();i++){
		for(int j=0;j<bv.size();j++){
			cout<<bv[i].get()<<" "<<bv[j].get()<<" "<<(bv[i]-bv[j]).get()<<" "<<(bv[i]-bv[j]).get()<<"\n";
		}
	}
	cout<<"big multiplications\n";
	for(int i=0;i<bv.size();i++){
		for(int j=0;j<bv.size();j++){
			cout<<bv[i].get()<<" "<<bv[j].get()<<" "<<(bv[i]*bv[j]).get()<<"\n";
		}
	}
	cout<<"big factors"<<endl;
	cout<<bigInt::big_factorial("100").get()<<"\n";
	return 0;
}