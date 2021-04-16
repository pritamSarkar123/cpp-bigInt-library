#include "bigInt.h"
/*
    bigInt big_root_by(int number);
    bigInt big_root_by(long number);
    bigInt big_root_by(long long number);
    bigInt big_root_by(bigInt another);
    bigInt big_root_by(string input_string) throw (bigIntException);
    static string big_root(string a,string b);
*/
bigInt bigInt::big_root_by(int number){
    return bigInt(big_root(integer,to_string(number)));
}
bigInt bigInt::big_root_by(long number){
    return bigInt(big_root(integer,to_string(number)));
}
bigInt bigInt::big_root_by(long long  number){
    return bigInt(big_root(integer,to_string(number)));
}
bigInt bigInt::big_root_by(bigInt another){
    return bigInt(big_root(integer,another.integer));
}
bigInt bigInt::big_root_by(string input_string) throw (bigIntException){
    if(checkValidInt(input_string)){
        return bigInt(big_root(integer,input_string));
    }else throw bigIntException();
}
string bigInt::big_root(string a,string b){
    string l="1";
    string h=big_div(a,b);
    while(big_compare(l,h)<=0){
        string m=big_div(big_sum(l,h),"2");
        string ms="1";string ms_1="1";string mi=big_sum(m,"1");
        for(string i="1";big_compare(i,b)<=0;i=big_sum(i,"1")){
            ms=big_mul(ms,m);
            ms_1=big_mul(ms_1,mi);
        }
        if(big_compare(ms,a)==0) return m;
        else if(big_compare(ms,a)<0){
            if(big_compare(ms_1,a)>0) return m;
            else l=big_sum(m,"1");
        }else h=big_sub(m,"1");
    }
}