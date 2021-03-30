#include<iostream>
#include "bigInt.h"

using namespace std;

int main(){
	vector<string> v{"500","700","-500","-700"};
	vector<bigInt> bv;
	for(int i=0;i<v.size();i++){
		bv.push_back(bigInt(v[i]));
	}
	for(int i=0;i<bv.size();i++){
		for(int j=0;j<bv.size();j++){
			cout<<bv[i].get()<<" "<<bv[j].get()<<" "<<bv[i].big_add(bv[j]).get()<<" "<<bv[i].big_substract(bv[j]).get()<<"\n";
		}
	}
	return 0;
}