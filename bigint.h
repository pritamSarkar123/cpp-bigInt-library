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
	public:
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
		//-------------------------------------------------------
		int operator > (bigInt another); 
		int operator > (string input_string) throw (bigIntException);
		int operator > (int number);
		int operator > (long number);
		int operator > (long long number);
		static int big_compare(string s1,string s2);
		//-------------------------------------------------------------
		bool operator == (bigInt another);
		bool operator == (string input_string) throw (bigIntException);
		bool operator == (int number);
		bool operator == (long number);
		bool operator == (long long number);
		//-----------------------------------------------------------------
		static string helper_sub(string s1,string s2);
		static string big_sub(string s1,string s2);
		static string big_sum(string s1,string s2);
		static string big_mul(string s1, string s2);
		static string big_fact(string s1);
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
		//--------------------------------------------------------------------
		static bigInt big_factorial(int number);
		static bigInt big_factorial(long number);
		static bigInt big_factorial(long long number);
		static bigInt big_factorial(string input_string) throw (bigIntException);
		static bigInt big_factorial(bigInt another);
		//--------------------------------------------------------------
		//--------------------------------------------------------------
		double toDouble(); // making the bigInt to double
		float toFloat(); //making the bigint into float
		int toInt();// bigInt to int
		long toLong();//  bigInt to long
		long long toLongLong();// bigInt to long
		//----------------------------------------------------------------
		//TODO: remaining
		int hashCode();
		int bit_length();
		int bit_count();
		bool primeProbability(int certainly);
		//----------------------------------
		
		bigInt big_gcd(bigInt another);
		bigInt big_gcd(string input_string);
		bigInt big_gcd(int number);
		bigInt big_gcd(long number);
		bigInt big_gcd(long long number);
		//-------------------------------
		string bit_clear(int position);
		bigInt bit_flip(int position);
		//--------------------------------
		bigInt big_max(bigInt another);
		bigInt big_max(string input_string);
		bigInt big_max(int number);
		bigInt big_max(long number);
		bigInt big_max(long long number);
		//-----------------------------------
		bigInt big_min(bigInt another);
		bigInt big_min(string input_string);
		bigInt big_min(int number);
		bigInt big_min(long number);
		bigInt big_min(long long number);
		//-------------------------------------
		bigInt big_mod(bigInt another);
		bigInt big_mod(string input_string);
		bigInt big_mod(int number);
		bigInt big_mod(long number);
		bigInt big_mod(long long number);
		//------------------------------------
		bigInt big_mod_inverse(bigInt another);
		bigInt big_mod_inverse(string input_string);
		bigInt big_mod_inverse(int number);
		bigInt big_mod_inverse(long number);
		bigInt big_mod_inverse(long long number);
		//-----------------------------------------
		bigInt big_mod_pow(bigInt exponent,bigInt another);
		bigInt big_mod_pow(string exponent,string input_string);
		bigInt big_mod_pow(int exponent,int number);
		bigInt big_mod_pow(long exponent,long number);
		bigInt big_mod_pow(long long exponent,long long number);
		//---------------------------------------------
		
		//--------------------------------------------
		bigInt big_pow(bigInt another);
		bigInt big_pow(string input_string);
		bigInt big_pow(int number);
		bigInt big_pow(long number);
		bigInt big_pow(long long number);
		//------------------------------------------
		bigInt big_remainder(bigInt another);
		bigInt big_remainder(string input_string);
		bigInt big_remainder(int number);
		bigInt big_remainder(long number);
		bigInt big_remainder(long long number);
		//---------------------------------------
		bigInt big_set_bit(int n);//Returns a BigInteger whose value is equivalent to this BigInteger with the designated bit set.
		bigInt big_shift_left(int n);
		bigInt big_shift_right(int n);
		int getLowestSetBit();// returns the inde of the lowest set bit in the bigint
		int big_signum();//Returns the signum function of this BigInteger.
		bool big_test_bit(int n); //Returns true if and only if the designated bit is set.
		vector<int> big_byte_array(); //Returns a byte array containing the two's-complement representation of this BigInteger.
		
		//--------------------------------------------------------
		bigInt big_divide(int number);
		bigInt big_divide(string input_string);
		bigInt big_divide(long number);
		bigInt big_divide(long long number);
		bigInt big_divide(bigInt another);
		//------------------------------------------------------
		vector<bigInt> big_divide_and_remainder(int number);
		vector<bigInt> big_divide_and_remainder(string input_string);
		vector<bigInt> big_divide_and_remainder(long number);
		vector<bigInt> big_divide_and_remainder(bigInt another);
		vector<bigInt> big_divide_and_remainder(long long number);
		//-------------------------------------------------------------
		//----------------------------------------------------
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