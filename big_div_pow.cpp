#include "bigInt.h"
/*

		static string big_div(string s1,string s2);
		static string big_mod(string s1,string s2);

		bigInt operator / (int number) throw (bigIntException);
		bigInt operator / (string input_string) throw (bigIntException);
		bigInt operator / (long number) throw (bigIntException);
		bigInt operator / (long long number) throw (bigIntException);
		bigInt operator / (bigInt another) throw (bigIntException);

		void operator /= (int number) throw (bigIntException);
		void operator /= (long number) throw (bigIntException);
		void operator /= (long long number) throw (bigIntException);
		void operator /= (string input_string) throw (bigIntException);
		void operator /= (bigInt another throw (bigIntException));	

		bigInt operator % (bigInt another) throw (bigIntException);
		bigInt operator % (string input_string) throw (bigIntException);
		bigInt operator % (int number) throw (bigIntException);
		bigInt operator % (long number) throw (bigIntException);
		bigInt operator % (long long number) throw (bigIntException);
		
		void operator %= (bigInt another) throw (bigIntException);
		void operator %= (string input_string) throw (bigIntException);
		void operator %= (int number) throw (bigIntException);
		void operator %= (long number) throw (bigIntException);
		void operator %= (long long number) throw (bigIntException);

		vector<bigInt> big_divide_and_remainder(int number) throw (bigIntException);
		vector<bigInt> big_divide_and_remainder(string input_string) throw (bigIntException);
		vector<bigInt> big_divide_and_remainder(long number) throw (bigIntException);
		vector<bigInt> big_divide_and_remainder(bigInt another) throw (bigIntException);
		vector<bigInt> big_divide_and_remainder(long long number) throw (bigIntException);

		bigInt big_pow(bigInt another);
		bigInt big_pow(string input_string) throw (bigIntException);
		bigInt big_pow(int number);
		bigInt big_pow(long number);
		bigInt big_pow(long long number);
		static string big_power(string s1,string s2);
*/
string bigInt::big_power(string s1,string s2){
	if(s2=="0") return "1";
	if(s2[0]=='-') return "0";
	string result="1";
	int count=0;
	while(big_compare(s2,"0")>0){
		if(!if_even(s2)){
			result = big_mul(result,s1);
			s2 = big_sub(s2,"1");
		}
		s1 = big_mul(s1,s1);
		s2 = big_div(s2,"2");
		count++;
		if(count>20) break;
	}
	return result;
}
//----------------------------------------------------------------------
string bigInt::big_div(string s1,string s2){
	//if signs are not the same then answer is negative else it is positive
	if((s1[0]!='-' && s2[0]!='-') && big_compare(s1,s2)<0) return "0"; // -a -b and -a < -b
	if((s1[0]=='-' && s2[0]!='-') && big_compare(s1.substr(1,s1.length()-1),s2)<0) return "0"; // -a b and a < b
	if((s1[0]!='-' && s2[0]=='-') && big_compare(s1,s2.substr(1,s2.length()-1))<0) return "0"; // a -b and a < b
	if(big_compare(s1,s2)==0) return "1"; // -a -b -a==-b  or a b a==b
	bool negative = false;
	if((s1[0]!='-' && s2[0]=='-') || (s1[0]=='-' && s2[0]!='-')) negative = true;
	//dividend / divisor
	string dividend = s1[0]=='-'?s1.substr(1,s1.length()-1):s1;
	string divisor = s2[0]=='-'?s2.substr(1,s2.length()-1):s2;
	string quotient="0";
	// for(;dividend >= divisor; dividend-=divisor,quotient++);
	while(big_compare(dividend,divisor)>=0){
		dividend = big_sub(dividend,divisor);
		quotient = big_sum(quotient,"1");
	}
	return negative==false?quotient:"-"+quotient;
}
//---------------------------------------------------------------------
string bigInt::big_mod(string s1,string s2){
	string quotient = big_div(s1,s2);
	string ans = big_mul(quotient,s2);
	return big_sub(s1,ans);
}
//-----------------------------------------------------------------------------------
bigInt bigInt::operator / (int number) throw (bigIntException){
	if(!number) throw bigIntException("division by zero");
	return bigInt(big_div(integer,to_string(number)));
}
bigInt bigInt::operator / (long number) throw (bigIntException){
	if(!number) throw bigIntException("division by zero");
	return bigInt(big_div(integer,to_string(number)));
}
bigInt bigInt::operator / (long long number) throw (bigIntException){
	if(!number) throw bigIntException("division by zero");
	return bigInt(big_div(integer,to_string(number)));
}
bigInt bigInt::operator / (bigInt another) throw (bigIntException){
	if(another.integer=="0") throw bigIntException("division by zero");
	return bigInt(big_div(integer,another.integer));
}
bigInt bigInt::operator / (string input_string) throw (bigIntException){
	if(checkValidInt(input_string)){
		if(input_string=="0") throw bigIntException("division by zero");
		return bigInt(big_div(integer,input_string));
	}else throw bigIntException();
}
//------------------------------------------------------------------------------------
void bigInt::operator /= (int number) throw (bigIntException){
	if(!number) throw bigIntException("division by zero");
	integer=big_div(integer,to_string(number));
}
void bigInt::operator /= (long number) throw (bigIntException){
	if(!number) throw bigIntException("division by zero");
	integer=big_div(integer,to_string(number));
}
void bigInt::operator /= (long long number) throw (bigIntException){
	if(!number) throw bigIntException("division by zero");
	integer=big_div(integer,to_string(number));
}
void bigInt::operator /= (bigInt another) throw (bigIntException){
	if(another.integer=="0") throw bigIntException("division by zero");
	integer=big_div(integer,another.integer);
}
void bigInt::operator /= (string input_string) throw (bigIntException){
	if(checkValidInt(input_string)){
		if(input_string=="0") throw bigIntException("division by zero");
		integer=big_div(integer,input_string);
	}else throw bigIntException();
}
//-----------------------------------------------------------------------------------
bigInt bigInt::operator % (int number) throw (bigIntException){
	if(!number) throw bigIntException("division by zero");
	return bigInt(big_mod(integer,to_string(number)));
}
bigInt bigInt::operator % (long number) throw (bigIntException){
	if(!number) throw bigIntException("division by zero");
	return bigInt(big_mod(integer,to_string(number)));
}
bigInt bigInt::operator % (long long number) throw (bigIntException){
	if(!number) throw bigIntException("division by zero");
	return bigInt(big_mod(integer,to_string(number)));
}
bigInt bigInt::operator % (bigInt another) throw (bigIntException){
	if(another.integer=="0") throw bigIntException("division by zero");
	return bigInt(big_mod(integer,another.integer));
}
bigInt bigInt::operator % (string input_string) throw (bigIntException){
	if(checkValidInt(input_string)){
		if(input_string=="0") throw bigIntException("division by zero");
		return bigInt(big_mod(integer,input_string));
	}else throw bigIntException();
}
//------------------------------------------------------------------------------------
void bigInt::operator %= (int number) throw (bigIntException){
	if(!number) throw bigIntException("division by zero");
	integer=big_mod(integer,to_string(number));
}
void bigInt::operator %= (long number) throw (bigIntException){
	if(!number) throw bigIntException("division by zero");
	integer=big_mod(integer,to_string(number));
}
void bigInt::operator %= (long long number) throw (bigIntException){
	if(!number) throw bigIntException("division by zero");
	integer=big_mod(integer,to_string(number));
}
void bigInt::operator %= (bigInt another) throw (bigIntException){
	if(another.integer=="0") throw bigIntException("division by zero");
	integer=big_mod(integer,another.integer);
}
void bigInt::operator %= (string input_string) throw (bigIntException){
	if(checkValidInt(input_string)){
		if(input_string=="0") throw bigIntException("division by zero");
		integer=big_mod(integer,input_string);
	}else throw bigIntException();
}
//--------------------------------------------------------------------------------
vector<bigInt> bigInt::big_divide_and_remainder(int number) throw (bigIntException){
	if(!number) throw bigIntException("division by zero");
	vector<bigInt> ans;
	string quotient = big_div(integer,to_string(number));
	string remainder = big_mod(integer,to_string(number));
	ans.push_back(quotient);
	ans.push_back(remainder);
	return ans;
}
vector<bigInt> bigInt::big_divide_and_remainder(long number) throw (bigIntException){
	if(!number) throw bigIntException("division by zero");
	vector<bigInt> ans;
	string quotient = big_div(integer,to_string(number));
	string remainder = big_mod(integer,to_string(number));
	ans.push_back(quotient);
	ans.push_back(remainder);
	return ans;
}
vector<bigInt> bigInt::big_divide_and_remainder(long long number) throw (bigIntException){
	if(!number) throw bigIntException("division by zero");
	vector<bigInt> ans;
	string quotient = big_div(integer,to_string(number));
	string remainder = big_mod(integer,to_string(number));
	ans.push_back(quotient);
	ans.push_back(remainder);
	return ans;
}
vector<bigInt> bigInt::big_divide_and_remainder(bigInt another) throw (bigIntException){
	if(another.integer=="0") throw bigIntException("division by zero");
	integer=big_mod(integer,another.integer);
	vector<bigInt> ans;
	string quotient = big_div(integer,another.integer);
	string remainder = big_mod(integer,another.integer);
	ans.push_back(quotient);
	ans.push_back(remainder);
	return ans;
}
vector<bigInt> bigInt::big_divide_and_remainder(string input_string) throw (bigIntException){
	if(checkValidInt(input_string)){
		if(input_string=="0") throw bigIntException("division by zero");
		vector<bigInt> ans;
		string quotient = big_div(integer,input_string);
		string remainder = big_mod(integer,input_string);
		ans.push_back(quotient);
		ans.push_back(remainder);
		return ans;
	}else throw bigIntException();
}
//-------------------------------------------------------------------------------------
bigInt bigInt::big_pow(bigInt another){
	return bigInt(big_power(integer,another.integer));
}
bigInt bigInt::big_pow(int number){
	return bigInt(big_power(integer,to_string(number)));
}
bigInt bigInt::big_pow(long number){
	return bigInt(big_power(integer,to_string(number)));
}
bigInt bigInt::big_pow(long long number){
	return bigInt(big_power(integer,to_string(number)));
}
bigInt bigInt::big_pow(string input_string) throw (bigIntException){
	if(checkValidInt(input_string)){
		return bigInt(big_power(integer,input_string));
	}else throw bigIntException();
}
//----------------------------------------------------------------------