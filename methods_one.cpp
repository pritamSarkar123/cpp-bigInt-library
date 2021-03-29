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
