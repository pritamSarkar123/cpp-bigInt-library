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
		int i=0;
		while(input_string[i]=='0' || input_string[i]=='+'){
			i++;
		}
		if(i==input_string.length()) integer="0";
		else integer=input_string.substr(i,input_string.length()-i);
	}else{
		throw bigIntException();
	}
}