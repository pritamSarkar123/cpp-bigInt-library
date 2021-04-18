#include "bigInt.h"
bigIntException::bigIntException(){
	message="Not a valid integer";
}
bigIntException::bigIntException(string msg){
	message=msg;
}
string bigIntException::what(){
	return message;
}
bigInt::bigInt(){
	integer="";
}
bigInt::bigInt(long long number){
	integer=to_string(number);
}
bigInt::bigInt(string input_string) throw (bigIntException){
	if(checkValidInt(input_string)){
		int i=0;
		while((input_string[i]=='0' || input_string[i]=='+') && i<input_string.length()){
			i++;
		}
		if(i==input_string.length()) integer="0";
		else integer=input_string.substr(i,input_string.length()-i);
	}else{
		throw bigIntException();
	}
}