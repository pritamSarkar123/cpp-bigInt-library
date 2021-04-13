#include "bigInt.h"
/*
        static string bigGcd(string s1,string s2);
		static string bigLcm(string s1,string s2);
        //-------------------------------------------------------------
        bigInt big_gcd(bigInt another);
		bigInt big_gcd(string input_string) throw (bigIntException);
		bigInt big_gcd(int number);
		bigInt big_gcd(long number);
		bigInt big_gcd(long long number);
		//--------------------------------------------------------------------------
		bigInt big_lcm(bigInt another);
		bigInt big_lcm(string input_string) throw (bigIntException);
		bigInt big_lcm(int number);
		bigInt big_lcm(long number);
		bigInt big_lcm(long long number);
*/
bigInt bigInt::big_gcd(bigInt another){
    return bigInt(bigGcd(integer,another.integer));
}
bigInt bigInt::big_gcd(int number){
    return bigInt(bigGcd(integer,to_string(number)));
}
bigInt bigInt::big_gcd(long number){
    return bigInt(bigGcd(integer,to_string(number)));
}
bigInt bigInt::big_gcd(long long number){
    return bigInt(bigGcd(integer,to_string(number)));
}
bigInt bigInt::big_gcd(string input_string) throw (bigIntException){
    if(checkValidInt(input_string)){
        return bigInt(bigGcd(integer,input_string));
    }else throw bigIntException();
}
//--------------------------------------------------------------------
bigInt bigInt::big_lcm(bigInt another){
    return bigInt(bigLcm(integer,another.integer));
}
bigInt bigInt::big_lcm(int number){
    return bigInt(bigLcm(integer,to_string(number)));
}
bigInt bigInt::big_lcm(long number){
    return bigInt(bigLcm(integer,to_string(number)));
}
bigInt bigInt::big_lcm(long long number){
    return bigInt(bigLcm(integer,to_string(number)));
}
bigInt bigInt::big_lcm(string input_string) throw (bigIntException){
    if(checkValidInt(input_string)){
        return bigInt(bigLcm(integer,input_string));
    }else throw bigIntException();
}
//--------------------------------------------------------------------
string bigInt::bigGcd(string s1,string s2){
    s1= s1[0]=='-'? s1.substr(1,s1.length()-1):s1;
    s2= s2[0]=='-'? s2.substr(1,s2.length()-1):s2;
    if(big_compare(s1,s2)==-1) swap(s1,s2);
    if(s2=="0") return s1;
    else return bigGcd(s2,big_mod(s1,s2));
}
string bigInt::bigLcm(string s1,string s2){
    s1= s1[0]=='-'? s1.substr(1,s1.length()-1):s1;
    s2= s2[0]=='-'? s2.substr(1,s2.length()-1):s2;
    string mul=big_mul(s1,s2);
    string gcd=bigGcd(s1,s2);
    return big_div(mul,gcd);
}
