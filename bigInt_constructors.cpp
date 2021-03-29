#include "bigInt.h"
string bigIntException::what(){
	return "Not a valid integer";
}

bigInt::bigInt(){
	integer="";
}
bigInt::bigInt(int number){
	integer=to_string(number);
	}
bigInt::bigInt(long number){
	integer=to_string(number);
}
bigInt::bigInt(long long number){
	integer=to_string(number);
}
bigInt::bigInt(string input_string) throw (bigIntException){
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
