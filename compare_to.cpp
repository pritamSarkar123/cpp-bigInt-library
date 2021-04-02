#include "bigInt.h"
/*
	int operator > (bigInt another); 
	int operator > (string input_string) throw (bigIntException);
	int operator > (int number);
	int operator > (long number);
	int operator > (long long number);
	static int big_compare(string s1,string s2);
	//-------------------------------------------------
	bool operator == (bigInt another);
	bool operator == (string input_string) throw (bigIntException);
	bool operator == (int number);
	bool operator == (long number);
	bool operator == (long long number);
*/
/*
	s1 > s2 return 1
	s1 < s2 return -1
	s1 == s2 return 0  then is_equal true
*/
bool bigInt::operator == (bigInt another){
	return big_compare(integer,another.integer)==0?true:false;
}
bool bigInt::operator == (string input_string) throw (bigIntException){
	if(checkValidInt(input_string)){
		return big_compare(integer,input_string)==0?true:false;
	}else throw bigIntException();
}
bool bigInt::operator == (int number){
	return big_compare(integer,to_string(number))==0?true:false;
}
bool bigInt::operator == (long number){
	return big_compare(integer,to_string(number))==0?true:false;
}
bool bigInt::operator == (long long number){
	return big_compare(integer,to_string(number))==0?true:false;
}
int bigInt::operator > (bigInt another){
	return big_compare(integer, another.integer);
}
int bigInt::operator > (int number){
	return big_compare(integer,to_string(number));
}
int bigInt::operator > (long number){
	return big_compare(integer,to_string(number));
}
int bigInt::operator > (long long number){
	return big_compare(integer,to_string(number));
}

int bigInt::operator > (string input_string) throw (bigIntException){
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