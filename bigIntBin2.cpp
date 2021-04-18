#include "bigInt.h"
/*
	bigInt operator << (long long n);
	void operator <<=(long long n);
	bigInt operator >> (long long n);
	void operator >>=(long long n);

	bool big_test_bit(long long n);
	int getLowestSetBit();
	long long getLowestSetBit();// returns the inde of the lowest set bit in the bigint<-
	bool big_test_bit(long long n); //Returns true if and only if the designated bit is set.<-
	int big_signum();//Returns the signum function of this BigInteger.

	bigInt operator ~ (); //~b
	void bitwise_not_update(); //~b
	static string big_not(string s);

	static string filter(string &s1,string &s2);

	bigInt operator & (bigInt another);
	bigInt operator & (long long number);
	bigInt operator & (string input_string) throw (bigIntException);
	void bitwise_and_update(bigInt another);
	void bitwise_and_update(long long number);
	void bitwise_and_update(string input_string) throw (bigIntException);

	bigInt operator | (bigInt another);
	bigInt operator | (long long number);
	bigInt operator | (string input_string) throw (bigIntException);
	void bitwise_or_update(bigInt another);
	void bitwise_or_update(long long number);
	void bitwise_or_update(string input_string) throw (bigIntException);

	bigInt operator ^ (bigInt another);
	bigInt operator ^ (long long number);
	bigInt operator ^ (string input_string) throw (bigIntException);
	void bitwise_xor_update(bigInt another);
	void bitwise_xor_update(long long number);
	void bitwise_xor_update(string input_string) throw (bigIntException);

	static string big_and(string s1,string s2);
*/
//-------------------------------------------------------------------------
bigInt bigInt::operator & (long long number){
	return bigInt(big_and(integer,to_string(number)));
}
bigInt bigInt::operator & (bigInt another){
	return bigInt(big_and(integer,another.integer));
}
bigInt bigInt::operator & (string input_string) throw (bigIntException){
	if(checkValidInt(input_string)){
		return bigInt(big_and(integer,input_string));
	}throw bigIntException();
}
void bigInt::bitwise_and_update(long long number){
	integer=big_and(integer,to_string(number));
}
void bigInt::bitwise_and_update(bigInt another){
	integer=big_and(integer,another.integer);
}
void bigInt::bitwise_and_update(string input_string) throw (bigIntException){
	if(checkValidInt(input_string)){
		integer=big_and(integer,input_string);
	}throw bigIntException();
}
//------------------------------------------------------------------
bigInt bigInt::operator | (long long number){
	return bigInt(big_or(integer,to_string(number)));
}
bigInt bigInt::operator | (bigInt another){
	return bigInt(big_or(integer,another.integer));
}
bigInt bigInt::operator | (string input_string) throw (bigIntException){
	if(checkValidInt(input_string)){
		return bigInt(big_or(integer,input_string));
	}throw bigIntException();
}
void bigInt::bitwise_or_update(long long number){
	integer=big_or(integer,to_string(number));
}
void bigInt::bitwise_or_update(bigInt another){
	integer=big_or(integer,another.integer);
}
void bigInt::bitwise_or_update(string input_string) throw (bigIntException){
	if(checkValidInt(input_string)){
		integer=big_or(integer,input_string);
	}throw bigIntException();
}
//----------------------------------------------------------------------
bigInt bigInt::operator ^ (long long number){
	return bigInt(big_xor(integer,to_string(number)));
}
bigInt bigInt::operator ^ (bigInt another){
	return bigInt(big_xor(integer,another.integer));
}
bigInt bigInt::operator ^ (string input_string) throw (bigIntException){
	if(checkValidInt(input_string)){
		return bigInt(big_xor(integer,input_string));
	}throw bigIntException();
}
void bigInt::bitwise_xor_update(long long number){
	integer=big_xor(integer,to_string(number));
}
void bigInt::bitwise_xor_update(bigInt another){
	integer=big_xor(integer,another.integer);
}
void bigInt::bitwise_xor_update(string input_string) throw (bigIntException){
	if(checkValidInt(input_string)){
		integer=big_xor(integer,input_string);
	}throw bigIntException();
}
//----------------------------------------------------------------------
string bigInt::filter(string &s1,string &s2){
	s1=bigIntToBinary(s1);
	s2=bigIntToBinary(s2);
	bool s1_neg=false;
	bool s2_neg=false;
	long long s1_len=s1.length();
	long long s2_len=s2.length();
	if(s1[0]=='2'){ 
		s1_neg=true;
		s1=s1.substr(1,s1.length()-1);
		s1_len-=1;
	}
	if(s2[0]=='2'){
		s2_neg=true;
		s2=s2.substr(1,s2.length()-1);
		s2_len-=1;
	}
	long long diff=0;
	if(s1_len>s2_len){
		diff=s1_len-s2_len;
		if(s2_neg){
			while(diff!=0){
				s2="1"+s2;
				diff--;
			}
		}else{
			while(diff!=0){
				s2="0"+s2;
				diff--;
			}
		}
	}else if(s2_len>s1_len){
		diff=s2_len-s1_len;
		if(s1_neg){
			while(diff!=0){
				s1="1"+s1;
				diff--;
			}
		}else{
			while(diff!=0){
				s1="0"+s1;
				diff--;
			}
		}
	}
	string neg_status="00";
	if(s1_neg) neg_status[0]='1';
	if(s2_neg) neg_status[1]='1';
	return neg_status;
}
string bigInt::big_and(string s1,string s2){
	string neg_status=filter(s1,s2);
	long long len=s1.length();
	string ans="";
	long long i=len-1;
	while(i>=0){
		if(s1[i]=='1' && s2[i]=='1'){
			ans="1"+ans;
		}else ans="0"+ans;
		i--;
	}
	if(neg_status[0]=='1' && neg_status[1]=='1') ans="2"+ans;
	return binaryToBigInt(ans);
}
string bigInt::big_or(string s1,string s2){
	string neg_status=filter(s1,s2);
	long long len=s1.length();
	string ans="";
	long long i=len-1;
	while(i>=0){
		if(s1[i]=='1' || s2[i]=='1'){
			ans="1"+ans;
		}else ans="0"+ans;
		i--;
	}
	if(neg_status[0]=='1' || neg_status[1]=='1') ans="2"+ans;
	return binaryToBigInt(ans);
}
string bigInt::big_xor(string s1,string s2){
	string neg_status=filter(s1,s2);
	long long len=s1.length();
	string ans="";
	long long i=len-1;
	while(i>=0){
		if((s1[i]=='0' && s2[i]=='1') || (s1[i]=='1' && s2[i]=='0')){
			ans="1"+ans;
		}else ans="0"+ans;
		i--;
	}
	if((neg_status[0]=='1' && neg_status[1]=='0') || (neg_status[0]=='0' && neg_status[1]=='1')) ans="2"+ans;
	return binaryToBigInt(ans);
}
//-------------------------------------------------------------------
string bigInt::big_not(string s){
	string bin=bigIntToBinary(s);
	if(bin[0]=='2'){
		bin=bin.substr(1,bin.length()-1);
	}
	string ans="";
	long long len=bin.length();
	long long i=len-1;
	while(i>=0){
		if(bin[i]=='1') ans='0'+ans;
		else ans='1'+ans;
		i--;
	}
	return binaryToBigInt(ans);
}
bigInt bigInt::operator ~(){
	return bigInt(big_not(integer));
}
void bigInt::bitwise_not_update(){
	integer=big_not(integer);
}
//--------------------------------------------------------------------
int bigInt::big_signum(){
	return big_compare(integer,"0");
}
long long bigInt::getLowestSetBit(){
	string bin=bigIntToBinary(integer);
	if(bin[0]=='2'){
		bin=bin.substr(1,bin.length()-1);
	}
	long long i=bin.length()-1;
	while(i>=0){
		if(bin[i]=='1') return i;
		i--;
	}
	return -1;
}
bool bigInt::big_test_bit(long long n){
	string bin=bigIntToBinary(integer);
	if(bin[0]=='2'){
		bin=bin.substr(1,bin.length()-1);
	}
	long long len=bin.length();
	if(len<=n) return false;
	if(bin[n]=='1') return true;
	else return false;
}
//-------------------------------------------------------------------------------
bigInt bigInt::operator >> (long long n){
	string bin=bigIntToBinary(integer);
	bool negative=false;
	if(bin[0]=='2'){
		negative=true;
		bin=bin.substr(1,bin.length()-1);
	}
	long long old_length=bin.length();
	if(old_length <= n){
		return bigInt("0");
	}
	bin=bin.substr(0,old_length-n);
	if(negative) bin="2"+bin;
	return bigInt(binaryToBigInt(bin));
}
void bigInt::operator >>=(long long n){
	string bin=bigIntToBinary(integer);
	bool negative=false;
	if(bin[0]=='2'){
		negative=true;
		bin=bin.substr(1,bin.length()-1);
	}
	long long old_length=bin.length();
	if(old_length <= n){
		integer=binaryToBigInt("0");
		return;
	}
	bin=bin.substr(0,old_length-n);
	if(negative) bin="2"+bin;
	integer=binaryToBigInt(bin);
}
bigInt bigInt::operator << (long long n){
	string bin=bigIntToBinary(integer);
	long long i=0;
	while(i+8<n){
		bin+="00000000";
		i+=8;
	}
	while(i<n){
		bin+="0";
		i++;
	}
	return bigInt(binaryToBigInt(bin));
}
void bigInt::operator <<=(long long n){
	string bin=bigIntToBinary(integer);
	long long i=0;
	while(i+8<n){
		bin+="00000000";
		i+=8;
	}
	while(i<n){
		bin+="0";
		i++;
	}
	integer=binaryToBigInt(bin);
}