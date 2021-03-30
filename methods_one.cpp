#include "bigInt.h"

/*
	get()
	big_abs()
	checkValidInt()
	value()
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
