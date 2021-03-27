#include<iostream>
#include<string>
#include<regex>
#include<exception>
#include<cstdlib>
#include<vector>
using namespace std;
class bigIntException:public exception{
	public:
		string what(){
			return "Not a valid integer";
		}
};

class bigInt{
	string integer;
	public:
		bigInt(){
			integer="";
		}
		bigInt(int number){
			integer=to_string(number);
		}
		bigInt(long number){
			integer=to_string(number);
		}
		bigInt(long long number){
			integer=to_string(number);
		}
		bigInt(string input_string) throw (bigIntException){
			if(checkValidInt(input_string)){
				if(input_string[0]=='+'){
					integer=input_string.substr(1,input_string.length()-1);
				}else{
					integer=input_string;
				}
			}else{
				throw bigIntException();
			}
		}
		string get();
		string big_abs();
		static bool checkValidInt(string input_string);
		static string value(int number) throw (bigIntException);
		//TODO: remaining
		int hashCode();
		string compare_to(bigInt another); 
		string compare_to(string input_string);
		string compare_to(int number);
		/*
			(a,b) compare > 0  b-a > 0 b is greater than a
			(a,b) compare < 0  b-a < 0 a is greater than b
			(a,b) compare == 0 a==b

		*/
		int bit_length();
		int bit_count();
		double toDouble(); // making the bigInt to double
		float toFloat(); //making the bigint into float
		int toInt();// bigInt to int
		long toLong();//  bigInt to long
		long long toLongLong();// bigInt to long
		bool primeProbability(int certainly);
		//----------------------------------
		bool is_equal(bigInt another);
		bool is_equal(string input_string);
		bool is_equal(int number);
		bool is_equal(long number);
		bool is_equal(long long number);
		//------------------------
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
		bigInt big_negate();
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
		//------------------------------------------------------
		bigInt big_multiply(int number);
		bigInt big_multiply(long number);
		bigInt big_multiply(long long number);
		bigInt big_multiply(string input_string);
		bigInt big_multiply(bigInt another);
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
		bigInt big_substract(int number);
		bigInt big_substract(long number);
		bigInt big_substract(long long number);
		bigInt big_substract(string input_string);
		bigInt big_substract(bigInt another);
		//----------------------------------------------------------
		bigInt big_add(int number);
		bigInt big_add(long number);
		bigInt big_add(long long number);
		bigInt big_add(string input_string);
		bigInt big_add(bigInt another);
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
string bigInt::get(){
	//returns the actual int string
	return integer;
}
string bigInt::big_abs(){
	if(integer[0]=='-') return integer.substr(1,integer.length()-1);
	return integer;
}
bool bigInt::checkValidInt(string input_string){
	//check whether the string of a valid integer or not
	regex int_format("[+-]?[0-9]+");
	if(regex_match(input_string,int_format)) return true;
	else return false;
}
string bigInt::value(int number) throw (bigIntException){
	//returns the value as string
	string input_string=to_string(number);
	if(checkValidInt(input_string)){
		return input_string;
	}else{
		throw bigIntException();
	}
}
int main(){
	try{
		bigInt bi("-123");
		cout<<"completed"<<"\n";
		// cout<<bigInt.value(145)<<"\n";
		cout<<bi.get()<<"\n";
		cout<<bi.big_abs()<<"\n";

	}catch(bigIntException e){
		cout<<e.what()<<"\n";
	}
	return 0;
}