#include "bigInt.h"
/*
	int compare_to(bigInt another); 
	int compare_to(string input_string) throw (bigIntException);
	int compare_to(int number);
	int compare_to(long number);
	int compare_to(long long number);
	static int big_compare(string s1,string s2);
	//-------------------------------------------------
	bool is_equal(bigInt another);
	bool is_equal(string input_string) throw (bigIntException);
	bool is_equal(int number);
	bool is_equal(long number);
	bool is_equal(long long number);
*/
/*
	s1 > s2 return 1
	s1 < s2 return -1
	s1 == s2 return 0  then is_equal true
*/
bool bigInt::is_equal(bigInt another){
	return compare_to(another)==0?true:false;
}
bool bigInt::is_equal(string input_string) throw (bigIntException){
	if(checkValidInt(input_string)){
		return compare_to(input_string)==0?true:false;
	}else throw bigIntException();
}
bool bigInt::is_equal(int number){
	return compare_to(number)==0?true:false;
}
bool bigInt::is_equal(long number){
	return compare_to(number)==0?true:false;
}
bool bigInt::is_equal(long long number){
	return compare_to(number)==0?true:false;
}
int bigInt::compare_to(bigInt another){
	return big_compare(integer, another.integer);
}
int bigInt::compare_to(int number){
	return big_compare(integer,to_string(number));
}
int bigInt::compare_to(long number){
	return big_compare(integer,to_string(number));
}
int bigInt::compare_to(long long number){
	return big_compare(integer,to_string(number));
}
int bigInt::compare_to(string input_string) throw (bigIntException){
	if(checkValidInt(input_string)){
		return big_compare(integer,input_string);
	}else throw bigIntException();
}
int bigInt::big_compare(string s1,string s2){
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