#include<iostream>
#include "bigInt.h"

using namespace std;

int main(){
	// vector<string> v{"25","5","-25","-5"};
	// vector<bigInt> bv;
	// for(int i=0;i<v.size();i++){
	// 	bv.push_back(bigInt(v[i]));
	// }
	// cout<<"big additions and subtractions\n";
	// for(int i=0;i<bv.size();i++){
	// 	for(int j=0;j<bv.size();j++){
	// 		cout<<bv[i].get()<<" "<<bv[j].get()<<" "<<(bv[i]-bv[j]).get()<<" "<<(bv[i]-bv[j]).get()<<"\n";
	// 	}
	// }
	// cout<<"big multiplications\n";
	// for(int i=0;i<bv.size();i++){
	// 	for(int j=0;j<bv.size();j++){
	// 		cout<<bv[i].get()<<" "<<bv[j].get()<<" "<<(bv[i]*bv[j]).get()<<"\n";
	// 	}
	// }
	// cout<<"big factors"<<endl;
	// cout<<bigInt::big_factorial("100").get()<<"\n";
	// cout<<"nothing new added , only git from vs code is checked"<<endl;

	// cout<<bigInt::big_root("17","3")<<"\n";
	// cout<<bigInt::big_root("125","3")<<"\n";
	// cout<<bigInt::big_root("171","3")<<"\n";
	// cout<<bigInt::big_root("17","5")<<"\n";
	// cout<<bigInt::big_root("125","5")<<"\n";
	// cout<<bigInt::big_root("171","5")<<"\n";

	// cout<<bigInt::bigIntToBinary("11")<<endl;
	// cout<<bigInt::bigIntToBinary("-11")<<endl;
	// cout<<bigInt::binaryToBigInt("1011")<<endl;
	// cout<<bigInt::binaryToBigInt("20101")<<endl;
	// bigInt b1(11);
	// bigInt b2(-112);
	// cout<<b1.bit_count('0')<<" "<<b1.bit_count('1')<<endl;
	// cout<<b2.bit_length()<<endl;
	// cout<<b1.hashCode()<<endl;
	// cout<<b2.hashCode()<<endl;
	bigInt b(11);
	b.bit_clear_and_update(3);
	cout<<b.get()<<endl;
	return 0;
}