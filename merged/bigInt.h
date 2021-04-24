#ifndef BIGINT
#define BIGINT
#include<iostream>
#include<string>
#include<regex>
#include<exception>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
class bigIntException:public exception{
	string message;
	public:
		bigIntException();
		bigIntException(string msg);
		string what();
};

class bigInt{
	string integer;
	static string big_not(string s);
	static string big_and(string s1,string s2);
	static string big_or(string s1,string s2);
	static string big_xor(string s1,string s2);
	static string filter(string &s1,string &s2);
	//--------------------------------------------------------------------------
	static string bigIntToBinary(string s);
	static string binaryToBigInt(string s);
	//--------------------------------------------------------------------------
	static bool checkValidInt(string input_string);
	static bool checkValidBin(string input_string);
	//---------------------------------------------------------------------------
	static bool if_even(const string &s);
	//---------------------------------------------------------------------------
	static int big_compare(const string &s1,const string &s2);
	//---------------------------------------------------------------------------
	static string helper_sub(string s1,string s2);
	static string big_sub(string s1,string s2);
	static string big_sum(string s1,string s2);
	static string big_mul(string s1, string s2);
	//---------------------------------------------------------------------------
	static string big_div(string s1,string s2);
	static string big_mod(string s1,string s2);
	//---------------------------------------------------------------------------
	static string big_power(string s1,string s2);
	//---------------------------------------------------------------------------
	static string big_fact(const string &s1);
	//---------------------------------------------------------------------------
	static string bigGcd(string s1,string s2);
	static string bigLcm(string s1,string s2);
	//---------------------------------------------------------------------------
	static string big_mod_inv(string s1,string s2);
	static string big_mod_power(string s1,string s2,string s3);
	static string big_minimal_reminder(string s1,string s2);
	//---------------------------------------------------------------------------
	static string big_root(string a,string b);
	public:
		bigInt();
		bigInt(long long number);
		bigInt(string input_string) throw (bigIntException); // copy constructor making problem -_-
		string get();
		string big_abs();
		bigInt operator ! ();
		void operator = (const bigInt &another);
		static string value(long long number);
		//----------------------------------------------------------------
		friend ostream & operator << (ostream &out, const bigInt &b);
		friend istream & operator >> (istream &in,bigInt &b);
		//---------------------------------------------------------------
		static bool big_even (const bigInt &another); 
		static bool big_even (const string &input_string) throw (bigIntException);
		static bool big_even (const long long &number);
		//---------------------------------------------------------------
		bool operator > (const bigInt &another); 
		bool operator > (const string &input_string) throw (bigIntException);
		bool operator > (const long long &number);
		//--------------------------------------------------------------
		bool operator < (const bigInt &another); 
		bool operator < (const string &input_string) throw (bigIntException);
		bool operator < (const long long &number);
		//---------------------------------------------------------------
		bool operator == (const bigInt &another);
		bool operator == (const string &input_string) throw (bigIntException);
		bool operator == (const long long &number);
		//------------------------------------------------------------
		static bigInt big_min(const vector<bigInt> &v);
		static bigInt big_max(const vector<bigInt> &v);
		//-------------------------------
		bigInt big_max(const bigInt &another);
		bigInt big_max(const string &input_string) throw (bigIntException);
		bigInt big_max(const long long &number);
		//-----------------------------------
		bigInt big_min(const bigInt &another);
		bigInt big_min(const string &input_string) throw (bigIntException);
		bigInt big_min(const long long &number);
		//-----------------------------------------------------------
		bigInt operator - (long long number);
		bigInt operator - (string input_string) throw (bigIntException);
		bigInt operator - (bigInt another);
		//----------------------------------------------------------
		bigInt operator + (long long number);
		bigInt operator + (string input_string) throw (bigIntException);
		bigInt operator + (bigInt another);
		//-------------------------------------------
		void operator ++ ();
		void operator -- ();
		//---------------------------------------------
		void operator += (long long number);
		void operator += (string input_string) throw (bigIntException);
		void operator += (bigInt another);
		//------------------------------------------------------
		void operator -= (long long number);
		void operator -= (string input_string) throw (bigIntException);
		void operator -= (bigInt another);
		//------------------------------------------------------
		bigInt operator * (long long number);
		bigInt operator * (string input_string) throw (bigIntException);
		bigInt operator * (bigInt another);
		//-------------------------------------------------------------
		void operator *= (long long number);
		void operator *= (string input_string) throw (bigIntException);
		void operator *= (bigInt another);	
		//------------------------------------------------------------------
		bigInt operator / (string input_string) throw (bigIntException);
		bigInt operator / (long long number) throw (bigIntException);
		bigInt operator / (bigInt another) throw (bigIntException);
		//-------------------------------------------------------------
		void operator /= (long long number) throw (bigIntException);
		void operator /= (string input_string) throw (bigIntException);
		void operator /= (bigInt another) throw (bigIntException);	
		//--------------------------------------------------------------
		bigInt operator % (bigInt another) throw (bigIntException);
		bigInt operator % (string input_string) throw (bigIntException);
		bigInt operator % (long long number) throw (bigIntException);
		//-------------------------------------------------------------
		void operator %= (bigInt another) throw (bigIntException);
		void operator %= (string input_string) throw (bigIntException);
		void operator %= (long long number) throw (bigIntException);
		//----------------------------------------------------------------
		vector<bigInt> big_divide_and_remainder(string input_string) throw (bigIntException);
		vector<bigInt> big_divide_and_remainder(bigInt another) throw (bigIntException);
		vector<bigInt> big_divide_and_remainder(long long number) throw (bigIntException);
		//-----------------------------------------------------------------
		bigInt big_pow(bigInt another);
		bigInt big_pow(string input_string) throw (bigIntException);
		bigInt big_pow(long long number);
		//--------------------------------------------------------------------
		static bigInt big_factorial(const long long &number);
		static bigInt big_factorial(const string &input_string) throw (bigIntException);
		static bigInt big_factorial(const bigInt &another);
		//--------------------------------------------------------------
		double toDouble(); // making the bigInt to double
		float toFloat(); //making the bigint into float
		int toInt();// bigInt to int
		long toLong();//  bigInt to long
		long long toLongLong();// bigInt to long
		//-----------------------------------------------------------------------
		bigInt big_gcd(bigInt another);
		bigInt big_gcd(string input_string) throw (bigIntException);
		bigInt big_gcd(long long number);
		//--------------------------------------------------------------------------
		bigInt big_lcm(bigInt another);
		bigInt big_lcm(string input_string) throw (bigIntException);
		bigInt big_lcm(long long number);
		//---------------------------------------------------
		bigInt big_root_by(long long number);
		bigInt big_root_by(bigInt another);
		bigInt big_root_by(string input_string) throw (bigIntException);
		//------------------------------------------------------------------------------
		static string toBinary(long long number);
		static string toBinary(string input_string) throw (bigIntException);
		static string toBinary(bigInt another);
		static string toDecimal(long long number) throw (bigIntException);
		static string toDecimal(string input_string) throw (bigIntException);
		static string toDecimal(bigInt another) throw (bigIntException);
		//----------------------------------------------------------------------------
		string hashCode();
		long long bit_length();
		long long bit_count(char x);
		//-----------------------------------------------------------------------------------
		bigInt bit_clear(long long position);
		bigInt bit_flip(long long position);
		void bit_clear_and_update(long long position);
		void bit_flip_and_update(long long position);
		bigInt clear_bit(long long position);
		bigInt flip_bit(long long position);
		//---------------------------------------------------------------------------------------
		bigInt big_mod_inverse(bigInt another);
		bigInt big_mod_inverse(string input_string) throw (bigIntException);
		bigInt big_mod_inverse(long long number);
		//---------------------------------------------------------------------------------------
		bigInt big_mod_pow(bigInt exponent,bigInt another);
		bigInt big_mod_pow(string exponent,string input_string) throw (bigIntException);
		bigInt big_mod_pow(long long exponent,long long number);
		//-----------------------------------------------------------------------------------
		bigInt big_minimal_rem(long long number);
		bigInt big_minimal_rem(string input_string) throw (bigIntException);
		bigInt big_minimal_rem(bigInt another);
		//-------------------------------------------------------------------------------------
		bigInt operator >> (long long n);
		void operator >>=(long long n);
		bigInt operator << (long long n);
		void operator <<=(long long n);
		long long getLowestSetBit();// returns the inde of the lowest set bit in the bigint<-
		bool big_test_bit(long long n); //Returns true if and only if the designated bit is set.<-
		int big_signum();//Returns the signum function of this BigInteger.
		//-------------------------------------------------------------------------------------
		bigInt operator ~ ();
		void bitwise_not_update();
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
		//-----------------------------------------------
		//TODO: remaining
		bool primeProbability(int certainity) throw (bigIntException);
};
bigIntException::bigIntException(){
	message="Not a valid integer";
}
bigIntException::bigIntException(string msg){
	message=msg;
}
string bigIntException::what(){
	return message;
}
bigInt::bigInt(){
	integer="";
}
bigInt::bigInt(long long number){
	integer=to_string(number);
}
bigInt::bigInt(string input_string) throw (bigIntException){
	if(checkValidInt(input_string)){
		int i=0;
		while((input_string[i]=='0' || input_string[i]=='+') && i<input_string.length()){
			i++;
		}
		if(i==input_string.length()) integer="0";
		else integer=input_string.substr(i,input_string.length()-i);
	}else{
		throw bigIntException();
	}
}
ostream & operator << (ostream &out, const bigInt &b){
	out<<b.integer;
	return out;
}
istream & operator >> (istream &in,bigInt &b){
	in>>b.integer;
	return in;
}
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
bigInt bigInt::big_max(const long long &number){
	return big_compare(integer,to_string(number)) > 0 ? bigInt(integer) : bigInt(number); 
}
bigInt bigInt::big_max(const bigInt &another){
	return big_compare(integer,another.integer) > 0 ? bigInt(integer) : another; 
}
bigInt bigInt::big_max(const string &input_string) throw (bigIntException){
	if(checkValidInt(input_string)){
		return big_compare(integer,input_string) > 0 ? bigInt(integer) : bigInt(input_string); 
	}else throw bigIntException();
}

bigInt bigInt::big_max(const vector<bigInt> &v){
	if(v.size()==0) return bigInt();
	bigInt ans(v[0]);
	for(int i = 1; i < v.size();i++){
		if(big_compare(ans.integer,v[i].integer) < 0) ans.integer=v[i].integer;
	}
	return ans;
}

//-------------------------------------------------------------------------------------------

bigInt bigInt::big_min(const long long &number){
	return big_compare(integer,to_string(number)) < 0 ? bigInt(integer) : bigInt(number); 
}
bigInt bigInt::big_min(const bigInt &another){
	return big_compare(integer,another.integer) < 0 ? bigInt(integer) : another; 
}
bigInt bigInt::big_min(const string &input_string) throw (bigIntException){
	if(checkValidInt(input_string)){
		return big_compare(integer,input_string) < 0 ? bigInt(integer) : bigInt(input_string); 
	}else throw bigIntException();
}
bigInt bigInt::big_min(const vector<bigInt> &v){
	if(v.size()==0) return bigInt();
	bigInt ans(v[0]);
	for(int i = 1; i < v.size();i++){
		if(big_compare(ans.integer,v[i].integer) > 0) ans.integer=v[i].integer;
	}
	return ans;
}
//------------------------------------------------------------------------------------


bool bigInt::operator == (const bigInt &another){
	return big_compare(integer,another.integer)==0?true:false;
}
bool bigInt::operator == (const string &input_string) throw (bigIntException){
	if(checkValidInt(input_string)){
		return big_compare(integer,input_string)==0?true:false;
	}else throw bigIntException();
}
bool bigInt::operator == (const long long &number){
	return big_compare(integer,to_string(number))==0?true:false;
}
bool bigInt::operator > (const bigInt &another){
	return big_compare(integer, another.integer)>0?true:false;
}
bool bigInt::operator > (const long long &number){
	return big_compare(integer,to_string(number))>0?true:false;
}
bool bigInt::operator > (const string &input_string) throw (bigIntException){
	if(checkValidInt(input_string)){
		return big_compare(integer,input_string)>0?true:false;
	}else throw bigIntException();
}
//---------------------------------------------------------------------
bool bigInt::operator < (const bigInt &another){
	return big_compare(integer, another.integer)<0?true:false;
}
bool bigInt::operator < (const long long &number){
	return big_compare(integer,to_string(number))<0?true:false;
}
bool bigInt::operator < (const string &input_string) throw (bigIntException){
	if(checkValidInt(input_string)){
		return big_compare(integer,input_string)<0?true:false;
	}else throw bigIntException();
}
int bigInt::big_compare(const string &s1,const string &s2){
	if(s1[0]!='-' && s2[0]=='-') return 1;
	else if(s1[0]=='-' && s2[0]!='-') return -1;
	else if(s1[0]=='-' && s2[0]=='-') return - big_compare(s1.substr(1,s1.length()-1),s2.substr(1,s2.length()-1)); // a >b then -a < -b
	else{ // a b
		if(s1.length() > s2.length()) return 1; //s1 > s2
		else if(s1.length() < s2.length()) return -1; //s2 < s1
		else{ // both length equal 
			for(int i=0; i<s1.length();i++){
				if(s1[i] > s2[i]) return 1; //s1 >s2
				if(s1[i] < s2[i]) return -1; // s1 < s2
			}
			return 0; //s1 == s2
		}
	}
}
bigInt bigInt:: operator - (long long number){
	return bigInt(big_sub(integer,to_string(number)));
}
bigInt bigInt:: operator - (bigInt another){
	return bigInt(big_sub(integer,another.integer));
}
bigInt bigInt:: operator - (string input_string) throw(bigIntException){
	if(checkValidInt(input_string))
		return bigInt(big_sub(integer,input_string));
	else throw bigIntException();
}
//-------------------------------------------------------
bigInt bigInt:: operator + (long long number){
	return bigInt(big_sum(integer,to_string(number)));
}
bigInt bigInt:: operator + (bigInt another){
	return bigInt(big_sum(integer,another.integer));
}
bigInt bigInt:: operator + (string input_string) throw(bigIntException){
	if(checkValidInt(input_string))
		return bigInt(big_sum(integer,input_string));
	else throw bigIntException();
}
//-----------------------------------------------
void bigInt:: operator ++ (){
	integer = big_sum(integer,"1"); 
}
void bigInt:: operator += (long long number){
	integer = big_sum(integer,to_string(number)); 
}
void bigInt:: operator += (bigInt another){
	integer = big_sum(integer,another.integer);
}
void bigInt:: operator += (string input_string) throw (bigIntException){
	if(checkValidInt(input_string))
		integer=big_sum(integer,input_string);
	else throw bigIntException();
}
//---------------------------------------------------------------
void bigInt:: operator -- (){
	integer = big_sub(integer,"1"); 
}
void bigInt:: operator -= (long long number){
	integer = big_sub(integer,to_string(number)); 
}
void bigInt:: operator -= (bigInt another){
	integer = big_sub(integer,another.integer);
}
void bigInt:: operator -= (string input_string) throw (bigIntException){
	if(checkValidInt(input_string))
		integer=big_sum(integer,input_string);
	else throw bigIntException();
}

//-----------------------------------------------------------
string bigInt::big_sub(string s1,string s2){
	if(!big_compare(s1,s2)) return "0"; // if a and b both equal 
	string ans="";
	if(s1[0]!='-' && s2[0]=='-') return big_sum(s1,s2.substr(1,s2.length()-1)); // a-(-b) => a+b
	else if(s1[0]=='-' && s2[0]!='-') return big_sum(s1,"-"+s2); // -a - (b) => -a + -b => -(a+b)
	else if(s1[0]=='-' && s2[0]=='-'){
		// -a - (-b)
		ans=helper_sub(s1.substr(1,s1.length()-1),s2.substr(1,s2.length()-1));
		ans = ans[0]=='-'? ans.substr(1,s1.length()-1) : '-'+ans;
	}
	else if(s1[0]!='-' && s2[0]!='-'){
		ans=helper_sub(s1,s2);
	}
	return ans;
}

string bigInt::big_sum(string s1,string s2){
	if(s1[0]=='-' && s2[0]!='-') return big_sub(s2,s1.substr(1,s1.length()-1));
	if(s1[0]!='-' && s2[0]=='-') return big_sub(s1,s2.substr(1,s2.length()-1));
	bool both_negative=(s1[0]=='-' && s2[0]=='-')?true:false; //-a + -b => -(a+b)
	if(both_negative){
		s1=s1.substr(1,s1.length()-1);
		s2=s2.substr(1,s2.length()-1);
	}
	if(big_compare(s1,s2)==1) swap(s1,s2); //s2 should be large 
	string s="";
	int s1_len=s1.length();
	int s2_len=s2.length();
	int diff=s2_len-s1_len;
	int carry=0;
	int ans=0;
	for(int i=s1_len-1;i>=0;i--){
		ans=(s1[i]-'0')+(s2[i+diff]-'0')+carry;
		s.push_back(ans%10 +'0');
		carry=ans/10;
	}
	for(int i=diff-1;i>=0;i--){
		ans=(s2[i]-'0')+carry;
		s.push_back(ans%10 +'0');
		carry=ans/10;
	}
	if(carry) s.push_back(carry+'0');
	reverse(s.begin(),s.end());
	int i=0;
	while(i<s.length() && s[i]=='0') i++;
	return both_negative==true? "-"+s.substr(i,s.length()-i) : s.substr(i,s.length()-i);
}

string bigInt::helper_sub(string s1,string s2){
	// always keep s1 > s2
	bool s1_gt_s2= big_compare(s1,s2) > 0 ? true : false;
	if(!s1_gt_s2) swap(s1,s2);
	string s="";
	int s1_len=s1.length();
	int s2_len=s2.length();
	int diff=s1_len-s2_len;
	int borrow=0;
	int ans=0;
	for(int i=s2_len-1;i>=0;i--){
		ans=(s1[i+diff]-'0')-(s2[i]-'0')-borrow;
		if(ans<0){
			ans+=10;
			borrow=1;
		}else{
			borrow=0;
		}
		s.push_back(ans +'0');
	}
	for(int i=diff-1;i>=0;i--){
		ans=(s1[i]-'0')-borrow;
		if(ans<0){
			ans+=10;
			borrow=1;
		}else{
			borrow=0;
		}
		s.push_back(ans +'0');
	}
	reverse(s.begin(),s.end());
	int i=0;
	while(i<s.length() && s[i]=='0') i++;
	return s1_gt_s2!=true? "-"+s.substr(i,s.length()-i) : s.substr(i,s.length()-i);
}
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
string bigInt::big_power(string s1,string s2){
	if(s2=="0") return "1";
	if(s2[0]=='-') return big_root(s1,s2.substr(1,s2.length()-1));
	bool negative=false;
	if(s1[0]=='-'){
		s1=s1.substr(1,s1.length()-1);
		if(!if_even(s2)) negative=true;
	}
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
	if(negative) return '-'+result;
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
bigInt bigInt::big_pow(long long number){
	return bigInt(big_power(integer,to_string(number)));
}
bigInt bigInt::big_pow(string input_string) throw (bigIntException){
	if(checkValidInt(input_string)){
		return bigInt(big_power(integer,input_string));
	}else throw bigIntException();
}
bigInt bigInt::big_pow(bigInt another){
	return bigInt(big_power(integer,another.integer));
}
//----------------------------------------------------------------------
bigInt bigInt::big_mod_inverse(long long number){
	return bigInt(big_mod_inv(integer,to_string(number)));
}
bigInt bigInt::big_mod_inverse(bigInt another){
	return bigInt(big_mod_inv(integer,another.integer));
}
bigInt bigInt::big_mod_inverse(string input_string) throw (bigIntException){
	if(checkValidInt(input_string)){
		return bigInt(big_mod_inv(integer,input_string));
	}else throw bigIntException();
}
string bigInt::big_mod_inv(string s1,string s2){
	string quotient=big_div(s1,s2);
	quotient=big_sum(quotient,"1");
	return big_sub(s1,quotient);
}
//-------------------------------------------------------------------------------------------
string bigInt::big_mod_power(string s1,string s2,string s3){
	string remainder=big_mod(s1,s2);
	return big_power(remainder,s3);
}
bigInt bigInt::big_mod_pow(long long exponent,long long number){
	return bigInt(big_mod_power(integer,to_string(number),to_string(exponent)));
}
bigInt bigInt::big_mod_pow(bigInt exponent,bigInt another){
	return bigInt(big_mod_power(integer,another.integer,exponent.integer));
}
bigInt bigInt::big_mod_pow(string exponent,string input_string) throw (bigIntException){
	if(checkValidInt(input_string) && checkValidInt(exponent)){
		return bigInt(big_mod_power(integer,input_string,exponent));
	}else throw bigIntException();
}
//----------------------------------------------------------------------
string bigInt::big_minimal_reminder(string s1,string s2){
	string remainder= big_mod(s1,s2);
	string half_s2=big_div(s2,"2");
	if(big_compare(remainder,half_s2)==1){
		return big_sub(remainder,s2);
	}else{
		return remainder;
	}
}
bigInt bigInt::big_minimal_rem(long long number){
	return bigInt(big_minimal_reminder(integer,to_string(number)));
}
bigInt bigInt::big_minimal_rem(bigInt another){
	return bigInt(big_minimal_reminder(integer,another.integer));
}
bigInt bigInt::big_minimal_rem(string input_string) throw (bigIntException){
	if(checkValidInt(input_string)){
		return bigInt(big_minimal_reminder(integer,input_string));
	}else throw bigIntException();
}
bigInt bigInt::big_gcd(bigInt another){
    return bigInt(bigGcd(integer,another.integer));
}
bigInt bigInt::big_gcd(long long number){
    return bigInt(bigGcd(integer,to_string(number)));
}
bigInt bigInt::big_gcd(string input_string) throw (bigIntException){
    if(checkValidInt(input_string)){
        return bigInt(bigGcd(integer,input_string));
    }else throw bigIntException();
}
//--------------------------------------------------------------------
bigInt bigInt::big_lcm(bigInt another){
    return bigInt(bigLcm(integer,another.integer));
}
bigInt bigInt::big_lcm(long long number){
    return bigInt(bigLcm(integer,to_string(number)));
}
bigInt bigInt::big_lcm(string input_string) throw (bigIntException){
    if(checkValidInt(input_string)){
        return bigInt(bigLcm(integer,input_string));
    }else throw bigIntException();
}
//--------------------------------------------------------------------
string bigInt::bigGcd(string s1,string s2){
    s1= s1[0]=='-'? s1.substr(1,s1.length()-1):s1;
    s2= s2[0]=='-'? s2.substr(1,s2.length()-1):s2;
    if(big_compare(s1,s2)==-1) swap(s1,s2);
    if(s2=="0") return s1;
    else return bigGcd(s2,big_mod(s1,s2));
}
string bigInt::bigLcm(string s1,string s2){
    s1= s1[0]=='-'? s1.substr(1,s1.length()-1):s1;
    s2= s2[0]=='-'? s2.substr(1,s2.length()-1):s2;
    string mul=big_mul(s1,s2);
    string gcd=bigGcd(s1,s2);
    return big_div(mul,gcd);
}
bigInt bigInt::big_root_by(long long  number){
    return bigInt(big_root(integer,to_string(number)));
}
bigInt bigInt::big_root_by(bigInt another){
    return bigInt(big_root(integer,another.integer));
}
bigInt bigInt::big_root_by(string input_string) throw (bigIntException){
    if(checkValidInt(input_string)){
        return bigInt(big_root(integer,input_string));
    }else throw bigIntException();
}
string bigInt::big_root(string a,string b){
	if(a[0]=='-') return "";
	if(b[0]=='-') return big_power(a,b.substr(1,b.length()-1));
    string l="1";
    string h=big_div(a,b);
    while(big_compare(l,h)<=0){
        string m=big_div(big_sum(l,h),"2");
        string ms="1";string ms_1="1";string mi=big_sum(m,"1");
        for(string i="1";big_compare(i,b)<=0;i=big_sum(i,"1")){
            ms=big_mul(ms,m);
            ms_1=big_mul(ms_1,mi);
        }
        if(big_compare(ms,a)==0) return m;
        else if(big_compare(ms,a)<0){
            if(big_compare(ms_1,a)>0) return m;
            else l=big_sum(m,"1");
        }else h=big_sub(m,"1");
    }
}
bigInt bigInt::clear_bit(long long position){
	if(position<0) return bigInt(integer);
	string binary=bigIntToBinary(integer);
	bool negative = false;
	if(binary[0]=='2'){
		negative = true;
		binary=binary.substr(1,binary.length()-1);
	}
	long long len=binary.length();
	if(position<len){// otherwise do nothing keep as it is
		string ans=binary.substr(0,len-position-1);
		ans+="0";
		if(len-position<len)
			ans+=binary.substr(len-position,position);
		if(negative) ans="2"+ans;
		return bigInt(binaryToBigInt(ans));
	}else{
		return bigInt(integer);
	}
}
bigInt bigInt::bit_clear(long long position){
	return clear_bit(position);
}
void bigInt::bit_clear_and_update(long long position){
	integer=clear_bit(position).integer;
}
//------------------------------------------------------------------------------------
bigInt bigInt::flip_bit(long long position){
	if(position<0) return bigInt(integer);
	string binary=bigIntToBinary(integer);
	bool negative = false;
	if(binary[0]=='2'){
		negative = true;
		binary=binary.substr(1,binary.length()-1);
	}
	long long len=binary.length();
	if(position<len){// otherwise do nothing keep as it is
		string ans=binary.substr(0,len-position-1);
		if(binary[len-position-1]=='1') ans+="0";
		else ans+="1";
		if(len-position<len)
			ans+=binary.substr(len-position,position);
		if(negative) ans="2"+ans;
		return bigInt(binaryToBigInt(ans));
	}else{
		return bigInt(integer);
	}
}
bigInt bigInt::bit_flip(long long position){
	return flip_bit(position);
}
void bigInt::bit_flip_and_update(long long position){
	integer=flip_bit(position).integer;
}
//-----------------------------------------------------------------------------------------------------------------
long long bigInt::bit_length(){
	string binary=bigIntToBinary(integer);
	if(binary[0]=='2'){
		return binary.length()-1;
	}
	return binary.length();
}
long long bigInt::bit_count(char x){
	string binary=bigIntToBinary(integer);
	binary= binary[0]=='2'?binary.substr(1,binary.length()-1):binary;
	long long count=0;
	for(long long i=0;i<binary.length();i++){
		if(binary[i]==x) count++;
	}
	return count;
}
string bigInt::toBinary(long long number){
	return bigIntToBinary(to_string(number));
}
string bigInt::toBinary(string input_string) throw (bigIntException){
	if(checkValidInt(input_string)){
		return bigIntToBinary(input_string);
	} else throw bigIntException();
}
string bigInt::toBinary(bigInt another){
	return bigIntToBinary(another.integer);
}
//-------------------------------------------------------------------------
string bigInt::toDecimal(long long number) throw (bigIntException){
	if(checkValidBin(to_string(number))){
		return bigIntToBinary(to_string(number));
	}else throw bigIntException("Not a valid binary string");
}
string bigInt::toDecimal(string input_string) throw (bigIntException){
	if(checkValidBin(input_string)){
		return bigIntToBinary(input_string);
	}else throw bigIntException("Not a valid binary string");
}
string bigInt::toDecimal(bigInt another) throw (bigIntException){
	if(checkValidBin(another.integer)){
		return bigIntToBinary(another.integer);
	}else throw bigIntException("Not a valid binary string");
}
//------------------------------------------------------------------------------------

bool bigInt::checkValidBin(string input_string){
	//2 stands for 2's complement
	regex bin_format("2?[01]+");
	return regex_match(input_string,bin_format)==true ? true : false;
}

string bigInt::bigIntToBinary(string s){
	bool negative = false;
	if(s[0]=='-'){
		negative = true; s=s.substr(1,s.length()-1);
	}
	// converting non nwgative part to binary
	string b="";
	string rem,quo;
	while(big_compare(s,"1")!=0 && big_compare(s,"0")!=0){
		quo=big_div(s,"2");
		rem=big_sub(s,big_mul(quo,"2"));
		b=rem+b;
		s=quo;
	}
	b=s+b;
	if(negative){// need to perform 2's complement
		string ans="";
		long long i=b.size()-1;
		while(b[i]!='1' && i>=0){ // r to l untill 1 keep as it is
			ans=b[i]+ans;
			i--;
		}
		if(i>=0) {ans='1'+ans;i--;} // place the right most one as it is // if no one then i would be -1
		while(i>=0){
			if(b[i]=='1') ans='0'+ans;
			else ans='1'+ans;
			i--;
		}
		i=0;
		while(ans[i]=='1') i++;
		b="2"+ans.substr(i,ans.length()-i); // 2 means in 2's complement form
	}
	return b;
}
string bigInt::binaryToBigInt(string s){
	bool negative = false;
	if(s[0]=='2'){
		s=s.substr(1,s.length()-1);
		negative=true;
	}
	string decimal = "0";
	long long len=s.length();
	long long i=len-1,pos;
	while(i>=0){
		pos=len-i-1;
		if(s[pos]!='0'){
			decimal=big_sum(decimal,big_power("2",to_string(i)));
		}
		i--;
	}
	if(negative){
		string length=to_string(s.length());
		string max_val=big_power("2",length);
		string ans='-'+big_sub(max_val,decimal);
		return ans;
	}
	return decimal;
}
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
bool bigInt::primeProbability(int certainity) throw (bigIntException){
    if(certainity<0 || certainity>100) throw bigIntException("certainity limit exceedeed");
    if(certainity==0) return true;
    string cert=to_string(certainity);
    string root_s=big_root(integer,"2");
    string a=big_mul(root_s,cert);
    string limit=big_div(a,"100");

    string i="2";
    string j="0";
    while(big_compare(big_mul(i,i),integer)<=0){
        if(big_mod(integer,i)=="0") return false;
        if(certainity<100 && big_compare(j,limit)>0) return true;
        i=big_sum(i,"1");
        j=big_sum(j,"1");
    }
    return true;
}
#endif