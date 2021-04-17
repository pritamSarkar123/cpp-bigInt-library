#include "bigInt.h"

/*
	get()
	big_abs()
	checkValidInt()
	value()
	double toDouble(); // making the bigInt to double
	float toFloat(); //making the bigint into float
	int toInt();// bigInt to int
	long toLong();//  bigInt to long
	long long toLongLong();// bigInt to long
	bigInt operator ! ();
	operator = (const bigint &another);

	//-----------------------------------------
		static bool big_even (const bigInt &another); 
		static bool big_even (const string &input_string) throw (bigIntException);
		static bool big_even (const int &number);
		static bool big_even (const long &number);
		static bool big_even (const long long &number);
		static bool if_even(const string &s);
	//-----------------------------------------

	string hashCode();

*/

string bigInt::get(){
	//returns the actual int string
	return integer;
}
string bigInt::big_abs(){
	if(integer[0]=='-') return integer.substr(1,integer.length()-1); //1st one must be the sign
	return integer;
}

bool bigInt::checkValidInt(string input_string){
	//check whether the string of a valid integer or not
	regex int_format("[+-]?[0-9]+");
	if(regex_match(input_string,int_format)) return true;
	else return false;
}
string bigInt::value(int number){
	return to_string(number);
}
string bigInt::value(long number){
	return to_string(number);
}
string bigInt::value(long long number){
	return to_string(number);
}
// ~b1
bigInt bigInt::operator ! (){
	bigInt b;
	b.integer = (integer[0]=='-') ? integer.substr(1,integer.length()-1) : "-"+integer;
	return b;
}
// b1 = b2
void bigInt::operator = (const bigInt &another){
	integer=another.integer;
}

float bigInt::toFloat(){
	string s = integer[0]=='-'?integer.substr(1,integer.length()-1):integer;
	int temp=0;
	int i=0;
	while(temp<INT_MAX  && i<s.length()){
		temp=((temp*10)+(s[i]-'0'));
		i++;
	}
	return integer[0]=='-'?-(float)temp:(float)temp;
}
double bigInt::toDouble(){
	string s = integer[0]=='-'?integer.substr(1,integer.length()-1):integer;
	int temp=0;
	int i=0;
	while(temp<INT_MAX  && i<s.length()){
		temp=((temp*10)+(s[i]-'0'));
		i++;	
	}
	return integer[0]=='-'?-(double)temp:(double)temp;
}
int bigInt::toInt(){
	string s = integer[0]=='-'?integer.substr(1,integer.length()-1):integer;
	int temp=0;
	int i=0;
	while(temp<INT_MAX  && i<s.length()){
		temp=((temp*10)+(s[i]-'0'));
		i++;
	}
	return integer[0]=='-'?-temp:temp;
}
long bigInt::toLong(){
	string s = integer[0]=='-'?integer.substr(1,integer.length()-1):integer;
	long temp=0;
	long i=0;
	while(temp<LONG_MAX  && i<s.length()){
		temp=((temp*(long)10)+(long)(s[i]-'0'));
		i+=(long)1;
	}
	return integer[0]=='-'?-temp:temp;
}
long long bigInt::toLongLong(){
	string s = integer[0]=='-'?integer.substr(1,integer.length()-1):integer;
	long long temp=0;
	long long i=0;
	while(temp<LLONG_MAX  && i<s.length()){
		temp=((temp*(long long)10)+(long long)(s[i]-'0'));
		i+=(long long)1;
	}
	return integer[0]=='-'?-temp:temp;
}

bool bigInt::if_even(const string &s){
	return ((s[s.length()-1] - '0') & 1)==0 ? true : false;
}
bool bigInt::big_even (const int &number){
	return if_even(to_string(number));
}
bool bigInt::big_even (const long &number){
	return if_even(to_string(number));
}
bool bigInt::big_even (const long long &number){
	return if_even(to_string(number));
}
bool bigInt::big_even (const bigInt &another){
	return if_even(another.integer);
}
bool bigInt::big_even (const string &input_string) throw (bigIntException){
	if(checkValidInt(input_string)){
		return if_even(input_string);
	}else throw bigIntException();
}
string bigInt::hashCode(){
	string hash="0";
	long long i=0,len=integer.length();
	while(i<len){
		hash=big_sum(hash,big_mul(to_string(integer[0]-'0'),big_power("31",to_string(len-i))));
		i++;
	}
	return hash;
}