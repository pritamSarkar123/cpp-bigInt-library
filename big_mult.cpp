#include "bigInt.h"
/*
		
		bigInt operator * (long long number);
		bigInt operator * (string input_string) throw (bigIntException);
		bigInt operator * (bigInt another);

		void operator *= (long long number);
		void operator *= (string input_string) throw (bigIntException);
		void operator *= (bigInt another);	

		static string big_mul(string s1, string s2);
	
		static bigInt big_factorial(const long long &number);
		static bigInt big_factorial(const string &input_string) throw (bigIntException);
		static bigInt big_factorial(const bigInt &another);
		static string big_fact(const string &s1);

*/
bigInt bigInt:: operator * (long long number){
	return bigInt(big_mul(integer,to_string(number)));
}
bigInt bigInt:: operator * (bigInt another){
	return bigInt(big_mul(integer,another.integer));
}
bigInt bigInt:: operator * (string input_string) throw (bigIntException){
	if(checkValidInt(input_string)){
		return bigInt(big_mul(integer,input_string));
	}else{
		throw bigIntException();
	}
}
//---------------------------------------------------------------------
void bigInt:: operator *= (long long number){
	integer = big_mul(integer,to_string(number));
}
void bigInt:: operator *= (bigInt another){
	integer = big_mul(integer,another.integer);
}
void bigInt:: operator *= (string input_string) throw (bigIntException){
	if(checkValidInt(input_string)){
		integer = big_mul(integer,input_string);
	}else{
		throw bigIntException();
	}
}

//---------------------------------------------------------------------

string bigInt::big_mul(string s1, string s2){
	if(s1=="0" || s2=="0") return "0";
	bool positive_op= ((s1[0]=='-' && s2[0]=='-')||(s1[0]!='-' && s2[0]!='-'))?true:false;
	if(s1[0]=='-') s1=s1.substr(1,s1.length()-1);
	if(s2[0]=='-') s2=s2.substr(1,s2.length()-1);	// s1 < s2
	if(big_compare(s2,s1)==-1) swap(s1,s2);
	int s1_len=s1.length();
	int s2_len=s2.length();
	int ans_int[s1_len+s2_len]={0};
	int len=s1_len+s2_len;
	for(int i=s1_len-1;i>=0;i--){
		for(int j=s2_len-1;j>=0;j--){
			ans_int[i+j+1]+=((s1[i]-'0')*(s2[j]-'0'));
			ans_int[i+j]+=(ans_int[i+j+1]/10);
			ans_int[i+j+1]%=10;
		}
	}
	int i=0;
	while(i<len && ans_int[i]==0) i++;
	string s="";
	if(!positive_op) s.push_back('-');
	while(i<len) s.push_back(ans_int[i++]+'0');
	return s;
}

string bigInt::big_fact(const string &s1){
	if(s1=="0") return "1";
	if(s1[0]=='-') return "0";
	string s2="2";
	string s="1";
	while(big_compare(s1,s2)!=0){
		s=big_mul(s,s2);
		s2=big_sum(s2,"1");
	}
	s=big_mul(s,s2);
	s2=big_sum(s2,"1");
	return s;
}
bigInt bigInt::big_factorial(const long long &number){
	return bigInt(big_fact(to_string(number)));
}
bigInt bigInt::big_factorial(const string &input_string) throw (bigIntException){
	if(checkValidInt(input_string)){
		return bigInt(big_fact(input_string));
	}else throw bigIntException();
}
bigInt bigInt::big_factorial(const bigInt &another){
	return bigInt(big_fact(another.integer));
}