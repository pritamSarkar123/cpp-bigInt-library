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
	//---------------------------------------------------------------------------
	//---------------------------------------------------------------------------
	//--------------------------------------------------------------------------
	//--------------------------------------------------------------------------
	//--------------------------------------------------------------------------
	public:
		bigInt();
		bigInt(long long number);
		bigInt(string input_string) throw (bigIntException);
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
		bool primeProbability(int certainly);
};
#endif