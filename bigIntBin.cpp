#include "bigInt.h"
/*
	bool checkValidBin(string input_string);

	bigInt bit_clear(int position);
	bigInt bit_clear(long position);
	bigInt bit_clear(long long position);

	bigInt bit_flip(int position);
	bigInt bit_flip(long position);
	bigInt bit_flip(long long position);

	void bit_clear_and_update(int position);
	void bit_clear_and_update(long position);
	void bit_clear_and_update(long long position);

	void bit_flip_and_update(int position);
	void bit_flip_and_update(long position);
	void bit_flip_and_update(long long position);

	bigInt clear_bit(long long position);
	bigInt flip_bit(long long position);

	static string toBinary(int &number);<br />
	static string toBinary(long &number);<br />
	static string toBinary(long long &number);<br />
	static string toBinary(string input_string) throw (bigIntException);<br />
	static string toBinary(bigInt &another);<br />
	static string toDecimal(int &number) throw (bigIntException);<br />
	static string toDecimal(long &number) throw (bigIntException);<br />
	static string toDecimal(long long &number) throw (bigIntException);<br />
	static string toDecimal(string &input_string) throw (bigIntException);<br />
	static string toDecimal(bigInt &another) throw (bigIntException);<br />

	static string bigIntToBinary(string s);
	static string binaryToBigInt(string s);
	long long bit_length();
	long long bit_count(char x);
*/
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
bigInt bigInt::bit_clear(int position){
	return clear_bit(position);
}
bigInt bigInt::bit_clear(long position){
	return clear_bit(position);
}
bigInt bigInt::bit_clear(long long position){
	return clear_bit(position);
}
void bigInt::bit_clear_and_update(int position){
	integer=clear_bit(position).integer;
}
void bigInt::bit_clear_and_update(long position){
	integer=clear_bit(position).integer;
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
bigInt bigInt::bit_flip(int position){
	return flip_bit(position);
}
bigInt bigInt::bit_flip(long position){
	return flip_bit(position);
}
bigInt bigInt::bit_flip(long long position){
	return flip_bit(position);
}
void bigInt::bit_flip_and_update(int position){
	integer=flip_bit(position).integer;
}
void bigInt::bit_flip_and_update(long position){
	integer=flip_bit(position).integer;
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

string bigInt::toBinary(int number){
	return bigIntToBinary(to_string(number));
}
string bigInt::toBinary(long number){
	return bigIntToBinary(to_string(number));
}
string bigInt::toBinary(long long number){
	return bigIntToBinary(to_string(number));
}
string bigInt::toBinary(string input_string) throw (bigIntException){
	if(checkValidInt(input_string)){
		return bigIntToBinary(input_string);
	} else throw bigIntException();
}
string bigInt::toBinary(const bigInt another){
	return bigIntToBinary(another.integer);
}
//-------------------------------------------------------------------------
string bigInt::toDecimal(int number) throw (bigIntException){
	if(checkValidBin(to_string(number))){
		return bigIntToBinary(to_string(number));
	}else throw bigIntException("Not a valid binary string");
}
string bigInt::toDecimal(long number) throw (bigIntException){
	if(checkValidBin(to_string(number))){
		return bigIntToBinary(to_string(number));
	}else throw bigIntException("Not a valid binary string");
}
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
	while(big_compare(s,"1")!=0){
		quo=big_div(s,"2");
		rem=big_sub(s,big_mul(quo,"2"));
		b=rem+b;
		s=quo;
	}
	b="1"+b;
	if(negative){// need to perform 2's complement
		string ans="";
		int i=b.size()-1;
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
		b="2"+ans; // 2 means in 2's complement form
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
	int i=0,pos;
	int len=s.length();
	while(i<len){
		pos=len-i-1;
		if(s[pos]!='0'){
			decimal=big_sum(decimal,big_power("2",to_string(i)));
		}
		i++;
	}
	if(negative){
		string length=to_string(s.length());
		string max_val=big_power("2",length);
		string ans='-'+big_sub(max_val,decimal);
		return ans;
	}
	return decimal;
}