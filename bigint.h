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
	public:
		bigInt();
		bigInt(int number);
		bigInt(long number);
		bigInt(long long number);
		bigInt(string input_string) throw (bigIntException);
		string get();
		string big_abs();
		bigInt operator ! ();
		void operator = (const bigInt &another);
		//--------------------------------------------------------------
		static bool checkValidInt(string input_string);
		static string value(int number);
		static string value(long number);
		static string value(long long number);
		//---------------------------------------------------------------
		static bool big_even (const bigInt &another); 
		static bool big_even (const string &input_string) throw (bigIntException);
		static bool big_even (const int &number);
		static bool big_even (const long &number);
		static bool big_even (const long long &number);
		static bool if_even(const string &s);
		//---------------------------------------------------------------
		bool operator > (const bigInt &another); 
		bool operator > (const string &input_string) throw (bigIntException);
		bool operator > (const int &number);
		bool operator > (const long &number);
		bool operator > (const long long &number);
		//--------------------------------------------------------------
		bool operator < (const bigInt &another); 
		bool operator < (const string &input_string) throw (bigIntException);
		bool operator < (const int &number);
		bool operator < (const long &number);
		bool operator < (const long long &number);
		static int big_compare(const string &s1,const string &s2);
		//---------------------------------------------------------------
		bool operator == (const bigInt &another);
		bool operator == (const string &input_string) throw (bigIntException);
		bool operator == (const int &number);
		bool operator == (const long &number);
		bool operator == (const long long &number);
		//------------------------------------------------------------
		static bigInt big_min(const vector<bigInt> &v);
		static bigInt big_max(const vector<bigInt> &v);
		//-------------------------------
		bigInt big_max(const bigInt &another);
		bigInt big_max(const string &input_string) throw (bigIntException);
		bigInt big_max(const int &number);
		bigInt big_max(const long &number);
		bigInt big_max(const long long &number);
		//-----------------------------------
		bigInt big_min(const bigInt &another);
		bigInt big_min(const string &input_string) throw (bigIntException);
		bigInt big_min(const int &number);
		bigInt big_min(const long &number);
		bigInt big_min(const long long &number);
		//-----------------------------------------------------------------
		static string helper_sub(string s1,string s2);
		static string big_sub(string s1,string s2);
		static string big_sum(string s1,string s2);
		static string big_mul(string s1, string s2);
		//-----------------------------------------------------------
		bigInt operator - (int number);
		bigInt operator - (long number);
		bigInt operator - (long long number);
		bigInt operator - (string input_string) throw (bigIntException);
		bigInt operator - (bigInt another);
		//----------------------------------------------------------
		bigInt operator + (int number);
		bigInt operator + (long number);
		bigInt operator + (long long number);
		bigInt operator + (string input_string) throw (bigIntException);
		bigInt operator + (bigInt another);
		//-------------------------------------------
		void operator ++ ();
		void operator -- ();
		//---------------------------------------------
		void operator += (int number);
		void operator += (long number);
		void operator += (long long number);
		void operator += (string input_string) throw (bigIntException);
		void operator += (bigInt another);
		//------------------------------------------------------
		void operator -= (int number);
		void operator -= (long number);
		void operator -= (long long number);
		void operator -= (string input_string) throw (bigIntException);
		void operator -= (bigInt another);
		//------------------------------------------------------
		bigInt operator * (int number);
		bigInt operator * (long number);
		bigInt operator * (long long number);
		bigInt operator * (string input_string) throw (bigIntException);
		bigInt operator * (bigInt another);
		//-------------------------------------------------------------
		void operator *= (int number);
		void operator *= (long number);
		void operator *= (long long number);
		void operator *= (string input_string) throw (bigIntException);
		void operator *= (bigInt another);	
		//------------------------------------------------------------------
		static string big_div(string s1,string s2);
		static string big_mod(string s1,string s2);
		//------------------------------
		bigInt operator / (int number) throw (bigIntException);
		bigInt operator / (string input_string) throw (bigIntException);
		bigInt operator / (long number) throw (bigIntException);
		bigInt operator / (long long number) throw (bigIntException);
		bigInt operator / (bigInt another) throw (bigIntException);
		//-------------------------------------------------------------
		void operator /= (int number) throw (bigIntException);
		void operator /= (long number) throw (bigIntException);
		void operator /= (long long number) throw (bigIntException);
		void operator /= (string input_string) throw (bigIntException);
		void operator /= (bigInt another) throw (bigIntException);	
		//--------------------------------------------------------------
		bigInt operator % (bigInt another) throw (bigIntException);
		bigInt operator % (string input_string) throw (bigIntException);
		bigInt operator % (int number) throw (bigIntException);
		bigInt operator % (long number) throw (bigIntException);
		bigInt operator % (long long number) throw (bigIntException);
		//-------------------------------------------------------------
		void operator %= (bigInt another) throw (bigIntException);
		void operator %= (string input_string) throw (bigIntException);
		void operator %= (int number) throw (bigIntException);
		void operator %= (long number) throw (bigIntException);
		void operator %= (long long number) throw (bigIntException);
		//----------------------------------------------------------------
		vector<bigInt> big_divide_and_remainder(int number) throw (bigIntException);
		vector<bigInt> big_divide_and_remainder(string input_string) throw (bigIntException);
		vector<bigInt> big_divide_and_remainder(long number) throw (bigIntException);
		vector<bigInt> big_divide_and_remainder(bigInt another) throw (bigIntException);
		vector<bigInt> big_divide_and_remainder(long long number) throw (bigIntException);
		//-----------------------------------------------------------------
		bigInt big_pow(bigInt another);
		bigInt big_pow(string input_string) throw (bigIntException);
		bigInt big_pow(int number);
		bigInt big_pow(long number);
		bigInt big_pow(long long number);
		static string big_power(string s1,string s2);
		//--------------------------------------------------------------------
		static bigInt big_factorial(const int &number);
		static bigInt big_factorial(const long &number);
		static bigInt big_factorial(const long long &number);
		static bigInt big_factorial(const string &input_string) throw (bigIntException);
		static bigInt big_factorial(const bigInt &another);
		static string big_fact(const string &s1);
		//--------------------------------------------------------------
		double toDouble(); // making the bigInt to double
		float toFloat(); //making the bigint into float
		int toInt();// bigInt to int
		long toLong();//  bigInt to long
		long long toLongLong();// bigInt to long
		//----------------------------------------------------------------
		//-------------------------------------------------------------------
		static string bigGcd(string s1,string s2);
		static string bigLcm(string s1,string s2);
		//------------------------------
		bigInt big_gcd(bigInt another);
		bigInt big_gcd(string input_string) throw (bigIntException);
		bigInt big_gcd(int number);
		bigInt big_gcd(long number);
		bigInt big_gcd(long long number);
		//--------------------------------------------------------------------------
		bigInt big_lcm(bigInt another);
		bigInt big_lcm(string input_string) throw (bigIntException);
		bigInt big_lcm(int number);
		bigInt big_lcm(long number);
		bigInt big_lcm(long long number);
		//---------------------------------------------------
		bigInt big_root_by(int number);
		bigInt big_root_by(long number);
		bigInt big_root_by(long long number);
		bigInt big_root_by(bigInt another);
		bigInt big_root_by(string input_string) throw (bigIntException);
		static string big_root(string a,string b);
		//------------------------------------------------------------------------------
		//TODO: remaining
		//-----------------------------------------------------------
		int hashCode();
		int bit_length();
		int bit_count();
		bool primeProbability(int certainly);
		//-------------------------------------------------------------------------------
		string bit_clear(int position);
		bigInt bit_flip(int position);
		//----------------------------------------------------------------------------------
		bigInt big_mod_inverse(bigInt another);
		bigInt big_mod_inverse(string input_string);
		bigInt big_mod_inverse(int number);
		bigInt big_mod_inverse(long number);
		bigInt big_mod_inverse(long long number);
		//---------------------------------------------------------------------------------------
		bigInt big_mod_pow(bigInt exponent,bigInt another);
		bigInt big_mod_pow(string exponent,string input_string);
		bigInt big_mod_pow(int exponent,int number);
		bigInt big_mod_pow(long exponent,long number);
		bigInt big_mod_pow(long long exponent,long long number);
		//-----------------------------------------------------------------------------------------
		bigInt big_set_bit(int n);//Returns a BigInteger whose value is equivalent to this BigInteger with the designated bit set.
		bigInt big_shift_left(int n);
		bigInt big_shift_right(int n);
		int getLowestSetBit();// returns the inde of the lowest set bit in the bigint
		int big_signum();//Returns the signum function of this BigInteger.
		bool big_test_bit(int n); //Returns true if and only if the designated bit is set.
		vector<int> big_byte_array(); //Returns a byte array containing the two's-complement representation of this BigInteger.
		//------------------------------------------------------
		static bigInt big_bitwise_not(bigInt b); //~b
		static bigInt big_bitwise_and(bigInt b1,bigInt b2); // b1 & b2
		static bigInt big_bitwise_and_not(bigInt b1,bigInt b2); //b1 & ~b2
		static bigInt big_bitwise_or(bigInt b1,bigInt b2); // b1 | b2
		static bigInt big_bitwise_or_not(bigInt b1,bigInt b2); //b1 | ~b2
		static bigInt big_bitwise_xor(bigInt b1,bigInt b2); // b1 ^ b2
		static bigInt big_bitwise_xor_not(bigInt b1,bigInt b2); //b1 ^ ~b2
		//-----------------------------------------------
};
#endif